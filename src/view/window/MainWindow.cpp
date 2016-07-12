#include "MainWindow.hpp"

namespace protobuf_decoder
{

    MainWindow::MainWindow() : m_VBox(Gtk::ORIENTATION_VERTICAL)
    {
        // Set up window.
        set_title("Protobuf decoder");
        set_border_width(5);
        set_default_size(400, 200);

        add(_box);

        _box.pack_start(_encodedTextArea);
        _box.pack_start(_decodedTextArea);

        // Register signal handler for encoded text.
        _encodedTextArea._textView.get_buffer()->signal_end_user_action().connect(
            sigc::bind(
                sigc::mem_fun(_signalHandler, &MainSignalHandler::onEncodedTextAreaChange),
                &_encodedTextArea, &_decodedTextArea
            )
        );

        // Register signal handler for decoded text.
        _decodedTextArea._textView.get_buffer()->signal_end_user_action().connect(
            sigc::bind(
                sigc::mem_fun(_signalHandler, &MainSignalHandler::onDecodedTextAreaChange),
                &_encodedTextArea, &_decodedTextArea
            )
        );

        // Show elements.
        show_all_children();
    }

}
