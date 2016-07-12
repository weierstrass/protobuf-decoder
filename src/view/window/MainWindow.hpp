#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "EncodedTextArea.hpp"
#include "DecodedTextArea.hpp"

#include "../signal_handler/MainSignalHandler.hpp"

#include <gtkmm.h>

namespace protobuf_decoder
{

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();

protected:

  void fill_buffers();
  
  //Signal handlers:
  void on_button_quit();
  void on_button_buffer1();
  void on_button_buffer2();

    //Child widgets:
    Gtk::Box m_VBox;

    
    EncodedTextArea _encodedTextArea;

    DecodedTextArea _decodedTextArea;

    MainSignalHandler _signalHandler;
  
};

}

#endif //MAIN_WINDOW_H
