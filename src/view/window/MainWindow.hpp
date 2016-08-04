
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

#include "EncodedTextArea.hpp"
#include "DecodedTextArea.hpp"
#include "ValueComboBox.hpp"

#include "../../conversion/ConversionInterface.hpp"

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
         */
        void onEncodedTextAreaChange();

        /**
         * @brief Callback function for decoded text change.
         */
        void onDecodedTextAreaChange();

        void onDroppedFile(
            const Glib::RefPtr<Gdk::DragContext>& context,
            int x,
            int y,
            const Gtk::SelectionData& selection_data,
            guint info,
            guint time);

        void onAlgorithmChanged();

        void onMessageTypeChanged();
        
        void handleTextAreaChange(TextAreaBase& iChangedTextArea, TextAreaBase& iOtherTextArea);

        /// Combo box for algorithm selection.
        Gtk::ComboBoxText _comboBox;

        /// Container of the other elements in the window. 
        Gtk::Box _box;

        /// Text area for the encoded text.
        EncodedTextArea _encodedTextArea;
        
        /// Text area for the decoded text.
        DecodedTextArea _decodedTextArea;

        /// Label showing current message path.
        Gtk::Label _messagePath;

        /// Combobox containing the possible message choices.
        ValueComboBox _messageComboBox;

        /// Label for error messages.
        Gtk::Label _errorLabel;

        std::unique_ptr<ConversionInterface> _converter;
  
    };

}

#endif //MAIN_WINDOW_H
