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

        /// Container of the other elements in the window. 
        Gtk::Box _box;

        /// Text area for the encoded text.
        EncodedTextArea _encodedTextArea;
        
        /// Text area for the decoded text.
        DecodedTextArea _decodedTextArea;

        /// Signal handler for window. 
        MainSignalHandler _signalHandler;
  
    };

}

#endif //MAIN_WINDOW_H
