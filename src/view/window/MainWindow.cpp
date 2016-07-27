#include "MainWindow.hpp"

namespace protobuf_decoder
{

    MainWindow::MainWindow()
        : _box(Gtk::ORIENTATION_VERTICAL)
        , _messagePath("Drop directory containing message files here.", true)
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

        // Register signal handler for file drop.
        signal_drag_data_received().connect(
            sigc::bind(
                sigc::mem_fun(_signalHandler, &MainSignalHandler::onDroppedFile),
                &_messagePath
            )
        );

        // Set up message path label.
        add(_box);

        _box.pack_start(_messagePath);
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

        // Show widgets.
        show_all_children();
    }

}
