#ifndef TEXT_AREA_BASE_H
#define TEXT_AREA_BASE_H

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/TextView.h>

namespace protobuf_decoder
{

class TextAreaBase : public Gtk::ScrolledWindow
{
public:
    TextAreaBase();

    virtual ~TextAreaBase() {}

    Gtk::TextView _textView;
  
};

}

#endif //TEXT_AREA_BASE_H
