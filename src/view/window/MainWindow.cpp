#include "MainWindow.hpp"

namespace protobuf_decoder
{

MainWindow::MainWindow() : m_VBox(Gtk::ORIENTATION_VERTICAL)
{
  set_title("Protobuf decoder");
  set_border_width(5);
  set_default_size(400, 200);

  add(m_VBox);

  m_VBox.pack_start(_encodedTextArea);
  m_VBox.pack_start(_decodedTextArea);
  
  _encodedTextArea._textView.get_buffer()->signal_changed().connect(
      sigc::bind<DecodedTextArea*>(
          sigc::mem_fun(_signalHandler, &MainSignalHandler::onEncodedTextAreaChange),
          &_decodedTextArea
      )
  );

  _decodedTextArea._textView.get_buffer()->signal_changed().connect(
      sigc::bind<EncodedTextArea*>(
          sigc::mem_fun(_signalHandler, &MainSignalHandler::onDecodedTextAreaChange),
          &_encodedTextArea
      )
  );

  on_button_buffer1();
  on_button_buffer2();
  
  show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_quit()
{
  hide();
}

void MainWindow::on_button_buffer1()
{    
    //_decodedTextView.get_buffer()->set_text("decoded\ndhd");
}

void MainWindow::on_button_buffer2()
{
    //_encodedTextView.get_buffer()->set_text("encoded");
}

}
