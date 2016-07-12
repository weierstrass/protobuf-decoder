#ifndef MAIN_SIGNAL_HANDLER_H
#define MAIN_SIGNAL_HANDLER_H

#include <gtkmm.h>

namespace protobuf_decoder
{

class EncodedTextArea;
class DecodedTextArea;
    
class MainSignalHandler
{
public:
    MainSignalHandler() {};
    
    virtual ~MainSignalHandler(){};

    void onEncodedTextAreaChange(DecodedTextArea* iDecodedTextArea);

    void onDecodedTextAreaChange(EncodedTextArea* iEncodedTextArea);
};

}

#endif //MAIN_SIGNAL_HANDLER_H
