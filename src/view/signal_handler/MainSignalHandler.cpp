#include "MainSignalHandler.hpp"

#include <iostream>

namespace protobuf_decoder
{

void MainSignalHandler::onEncodedTextAreaChange(DecodedTextArea* iDecodedTextArea)
{
    std::cout << "Encoded has changed" << std::endl;
        
}

void MainSignalHandler::onDecodedTextAreaChange(EncodedTextArea* iEncodedTextArea)
{
    std::cout << "Decoded has changed" << std::endl;
}

}
