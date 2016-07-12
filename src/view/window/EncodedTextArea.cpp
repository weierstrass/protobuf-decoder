#include "EncodedTextArea.hpp"

namespace protobuf_decoder
{

EncodedTextArea::EncodedTextArea() : TextAreaBase()
{
    // Set default text for text buffer.
    _textView.get_buffer()->set_text("Encoded string goes here...");
}

}
