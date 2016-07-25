#include "MainSignalHandler.hpp"

#include "../window/DecodedTextArea.hpp"
#include "../window/EncodedTextArea.hpp"

#include "../../conversion/ProtoBufConverter.hpp"

#include <iostream>

namespace protobuf_decoder
{

    MainSignalHandler::MainSignalHandler() : _converter(new ProtoBufConverter)
    {
        _converter->setMessagePath("test/data/message_single_file");
    }

    void MainSignalHandler::onEncodedTextAreaChange(
        EncodedTextArea* iEncodedTextArea,
        DecodedTextArea* iDecodedTextArea)
    {
        std::cout << "Encoded has changed" << std::endl;

        // Encoded text has changed -> update decoded text.
        iDecodedTextArea->setText(_converter->decode(iEncodedTextArea->getText()));
    }

    void MainSignalHandler::onDecodedTextAreaChange(
        EncodedTextArea* iEncodedTextArea,
        DecodedTextArea* iDecodedTextArea)
    {
        std::cout << "Decoded has changed" << std::endl;

        // Decoded text has changed -> update encoded text.
        iEncodedTextArea->setText(_converter->encode(iDecodedTextArea->getText()));
    }

    
    
    void MainSignalHandler::onDroppedFile(
        const Glib::RefPtr<Gdk::DragContext>& context,
        int x,
        int y,
        const Gtk::SelectionData& selection_data,
        guint info,
        guint time,
        Gtk::Label* iLabel)
    {
        std::cout << "file is in" << std::endl;

         std::vector<Glib::ustring> file_list = selection_data.get_uris();

         for (auto aFile : file_list)
         {
             aFile.erase(0,7);
             std::cout << aFile << std::endl;
             _converter->setMessagePath(aFile);
             iLabel->set_text(aFile);
         }
    }
}
