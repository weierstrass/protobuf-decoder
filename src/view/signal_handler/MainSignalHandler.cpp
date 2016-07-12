#include "MainSignalHandler.hpp"

#include "../window/DecodedTextArea.hpp"
#include "../window/EncodedTextArea.hpp"

#include "../../conversion/UpperLowerCaseConverter.hpp"

#include <iostream>

namespace protobuf_decoder
{

    MainSignalHandler::MainSignalHandler() : _converter(new UpperLowerCaseConverter) {}

void MainSignalHandler::onEncodedTextAreaChange(
    EncodedTextArea* iEncodedTextArea,
    DecodedTextArea* iDecodedTextArea)
{
    std::cout << "Encoded has changed" << std::endl;
    iDecodedTextArea->setText(_converter->decode(iEncodedTextArea->getText()));    
}

void MainSignalHandler::onDecodedTextAreaChange(
    EncodedTextArea* iEncodedTextArea,
    DecodedTextArea* iDecodedTextArea)
{
    std::cout << "Decoded has changed" << std::endl;
    iEncodedTextArea->setText(_converter->encode(iDecodedTextArea->getText()));
}

}
