#ifndef MAIN_SIGNAL_HANDLER_H
#define MAIN_SIGNAL_HANDLER_H

#include <memory>
#include <gtkmm.h>

#include "../../conversion/ConversionInterface.hpp"

namespace protobuf_decoder
{

    class ConversionInterface;
    class EncodedTextArea;
    class DecodedTextArea;

    /**
     * @brief Handles signals from Conversion window.
     *
     * There are signals triggered when either the encoded
     * or decoded text are changed. The signal handler is
     * responsible for calling the apropriate conversion
     * algorithm through the converter member and updating
     * the text areas.
     */
    class MainSignalHandler
    {
    public:
        /**
         * @brief Constructor
         */
        MainSignalHandler();

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
    private:
        std::unique_ptr<ConversionInterface> _converter;

    };

}

#endif //MAIN_SIGNAL_HANDLER_H
