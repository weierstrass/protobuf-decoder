#include "MainWindow.hpp"

#include <exception>
#include <iostream>

#include "DecodedTextArea.hpp"
#include "EncodedTextArea.hpp"

#include "../../conversion/algorithm/ConversionAlgorithm.hpp"
#include "../../conversion/ProtoBufConverter.hpp"

namespace protobuf_decoder
{

    MainWindow::MainWindow()
        : _box(Gtk::ORIENTATION_VERTICAL)
        , _messagePath("Drop directory containing message files here.", true)
        , _converter(new ProtoBufConverter)
    {
        // Set up window.
        set_title("Protobuf decoder");
        set_border_width(5);
        set_default_size(400, 200);


        // Setup file drop on the window
        std::vector<Gtk::TargetEntry> aListTargets;
        aListTargets.push_back(Gtk::TargetEntry("text/uri-list"));
        drag_dest_set(aListTargets,
                      Gtk::DEST_DEFAULT_ALL,
                      Gdk::ACTION_COPY | Gdk::ACTION_MOVE);

        // Set up message path label.
        _messagePath.set_padding(20,20);
        
        // Add combo box for algorithm selection.
        _refTreeModel = Gtk::ListStore::create(_columns);
        _comboBox.set_model(_refTreeModel);
        
        for (auto aAlgorithm : algorithm::ConversionAlgorithm::GetAlgorithms())
        {
            Gtk::TreeModel::Row row = *(_refTreeModel->append());
            row[_columns._key] = aAlgorithm.first;
            row[_columns._name] = aAlgorithm.second;
            _comboBox.set_active(row);
        }
        
        //_comboBox.pack_start(_columns._key);
        _comboBox.pack_start(_columns._name);

        _comboBox.set_margin_bottom(20);
        
        _box.pack_start(_messagePath, Gtk::PACK_SHRINK);
        _box.pack_start(_comboBox, Gtk::PACK_SHRINK);
        _box.pack_start(_encodedTextArea);
        _box.pack_start(_decodedTextArea);

       // Register signal handler for file drop.
        signal_drag_data_received().connect(
                sigc::mem_fun(*this, &MainWindow::onDroppedFile));
        
        // Register signal handler for encoded text.
        _encodedTextArea._textView.get_buffer()->signal_end_user_action().connect(
            sigc::mem_fun(*this, &MainWindow::onEncodedTextAreaChange));

        // Register signal handler for decoded text.
        _decodedTextArea._textView.get_buffer()->signal_end_user_action().connect(
                sigc::mem_fun(*this, &MainWindow::onDecodedTextAreaChange));

        // Register signal handler for algorithm change.
        _comboBox.signal_changed().connect(
            sigc::mem_fun(*this, &MainWindow::onAlgorithmChanged));

        add(_box);
        
        // Show widgets.
        show_all_children();
    }
        
    void MainWindow::onAlgorithmChanged()
    {
        Gtk::TreeModel::iterator iter = _comboBox.get_active();
        if(iter)
        {
            Gtk::TreeModel::Row row = *iter;
            if(row)
            {
                
                Glib::ustring aKey = row[_columns._key];
                _converter->setEncodeAlgorithm(aKey);

                std::cout << " Changing algorithm: " << aKey << std::endl;
            }
        }
        else
            std::cout << "invalid iter" << std::endl;       
    }

    void MainWindow::handleTextAreaChange(
        TextAreaBase& iChangedTextArea,
        TextAreaBase& iOtherTextArea)
    {
        std::string aConvertedString;

        try
        {
            if (dynamic_cast<EncodedTextArea*>(&iChangedTextArea))
            {
                aConvertedString = _converter->decode(iChangedTextArea.getText());    
            }
            else
            {
                aConvertedString = _converter->encode(iChangedTextArea.getText());   
            }
        }
        catch (const algorithm::AlgorithmException& iEx)
        {
            aConvertedString = iEx._text;
        }
        catch(...)
        {
            aConvertedString = "Unable to perform conversion, not sure why :/";
        }
        
        iOtherTextArea.setText(aConvertedString);
    }
    
    void MainWindow::onEncodedTextAreaChange()
    {
        std::cout << "Encoded has changed" << std::endl;
        handleTextAreaChange(_encodedTextArea, _decodedTextArea);
    }

    void MainWindow::onDecodedTextAreaChange()
    {
        std::cout << "Decoded has changed" << std::endl;
        handleTextAreaChange(_decodedTextArea, _encodedTextArea);
    }    
    
    void MainWindow::onDroppedFile(
        const Glib::RefPtr<Gdk::DragContext>& context,
        int x,
        int y,
        const Gtk::SelectionData& selection_data,
        guint info,
        guint time)
    {
        std::cout << "file is in" << std::endl;

        std::vector<Glib::ustring> file_list = selection_data.get_uris();

        for (auto aFile : file_list)
        {
            aFile.erase(0,7);
            std::cout << aFile << std::endl;
            _converter->setMessagePath(aFile);
            _messagePath.set_text(aFile);
            return;
        }
    }
    
}
