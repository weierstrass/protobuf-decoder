#include "TextAreaBase.hpp"

namespace protobuf_decoder
{

    TextAreaBase::TextAreaBase() : Gtk::ScrolledWindow()
    {
        // Only show the scrollbars when they are necessary.
        set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
        
        // Add the TreeView inside this ScrolledWindow. 
        add(_textView);
    }

    void TextAreaBase::setText(const std::string& iText)
    {
        _textView.get_buffer()->set_text(iText);
    }

    std::string TextAreaBase::getText() const
    {
        return _textView.get_buffer()->get_text();
    }

}
