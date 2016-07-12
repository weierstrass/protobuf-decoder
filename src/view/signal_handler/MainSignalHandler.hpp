#ifndef MAIN_SIGNAL_HANDLER_H
#define MAIN_SIGNAL_HANDLER_H

#include <memory>
#include <gtkmm.h>

#include "../../conversion/ConversionInterface.hpp"

namespace protobuf_decoder
{
    
class ConversionInterface;
class EncodedTextArea;
class DecodedTextArea;
    
class MainSignalHandler
{
public:
    MainSignalHandler();
    
    virtual ~MainSignalHandler(){};

    void onEncodedTextAreaChange(
        EncodedTextArea* iEncodedTextArea,
        DecodedTextArea* iDecodedTextArea);

    void onDecodedTextAreaChange(
        EncodedTextArea* iEncodedTextArea,
        DecodedTextArea* iDecodedTextArea);

private:    
    std::unique_ptr<ConversionInterface> _converter;
    
};

}

#endif //MAIN_SIGNAL_HANDLER_H
