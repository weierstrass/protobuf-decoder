#include "DecodedTextArea.hpp"

namespace protobuf_decoder
{

DecodedTextArea::DecodedTextArea() : TextAreaBase()
{
    // Set default text for text buffer.
    _textView.get_buffer()->set_text("Decoded string goes here...");   
}

}
