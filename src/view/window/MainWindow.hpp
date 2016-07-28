#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "EncodedTextArea.hpp"
#include "DecodedTextArea.hpp"

#include "../signal_handler/MainSignalHandler.hpp"

#include <gtkmm.h>

namespace protobuf_decoder
{
    /**
     * @brief Window for the conversion proccess.
     *
     * Contains the following widgets:
     *  - Text field for encoded text.
     *  - Text field for decoded text.
     *  - @todo field for message path
     *  - @todo field for algo selection
     *
     * The widgets who needs it gets registered with the
     * MainSignalHandler class.
     */
    class MainWindow : public Gtk::Window
    {
    public:
        /**
         * @brief Constructor.
         *
         * Sets up window and adds children.
         * Adds listeners to encode and decode text
         * areas.
         */
        MainWindow();

        /**
         * @brief Destructor
         */
        virtual ~MainWindow() {}

    private:

        /**
         * @brief Callback function for encoded text change.
         *
         * @param EncodedTextArea The text area containing the encoded text.
         * @param DecodedTextArea The text area containing the decoded text.
         */
        void onEncodedTextAreaChange(
            EncodedTextArea* iEncodedTextArea,
            DecodedTextArea* iDecodedTextArea);

        /**
         * @brief Callback function for decoded text change.
         *
         * @param EncodedTextArea The text area containing the encoded text.
         * @param DecodedTextArea The text area containing the decoded text.
         */
        void onDecodedTextAreaChange(
            EncodedTextArea* iEncodedTextArea,
            DecodedTextArea* iDecodedTextArea);


        void onDroppedFile(
            const Glib::RefPtr<Gdk::DragContext>& context,
            int x,
            int y,
            const Gtk::SelectionData& selection_data,
            guint info,
            guint time,
            Gtk::Label* iLabel);

        
        void onAlgorithmChanged();

        class ModelColumns : public Gtk::TreeModel::ColumnRecord
        {
        public:

            ModelColumns() { add(_key); add(_name); }

            Gtk::TreeModelColumn<Glib::ustring> _key;
            Gtk::TreeModelColumn<Glib::ustring> _name;
        };

        ModelColumns _columns;

        Gtk::ComboBox _comboBox;

        Glib::RefPtr<Gtk::ListStore> _refTreeModel;


        
        /// Container of the other elements in the window. 
        Gtk::Box _box;

        /// Text area for the encoded text.
        EncodedTextArea _encodedTextArea;
        
        /// Text area for the decoded text.
        DecodedTextArea _decodedTextArea;

        /// Label showing current message path.
        Gtk::Label _messagePath;

        /// Signal handler for window. 
//        MainSignalHandler _signalHandler;

        
        std::unique_ptr<ConversionInterface> _converter;
  
    };

}

#endif //MAIN_WINDOW_H
