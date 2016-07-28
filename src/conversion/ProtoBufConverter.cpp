#include "ProtoBufConverter.hpp"

#include "helper/MessageBuilder.hpp"

#include "algorithm/ConversionAlgorithm.hpp"

#include <google/protobuf/io/tokenizer.h>

#include <iostream>

using std::string;

namespace protobuf_decoder
{
    ProtoBufConverter::ProtoBufConverter()
        : _currentMessage(0)
        , _algorithm(algorithm::ConversionAlgorithm::Create("hex")) {}

    
    std::string ProtoBufConverter::encode(const std::string& iReadableString)
    {
        std::string aBinaryString = convertReadableToBinary(iReadableString);
        
        return _algorithm->encode(aBinaryString);
    }

    std::string ProtoBufConverter::decode(const std::string& iEncodedBinaryString)
    {
        std::string aBinaryString = _algorithm->decode(iEncodedBinaryString);

        return convertBinaryToReadable(aBinaryString);
    }

    void ProtoBufConverter::setEncodeAlgorithm(const std::string& iAlgorithmKey)
    {
        _algorithm = algorithm::ConversionAlgorithm::Create(iAlgorithmKey);
    }

    void ProtoBufConverter::setMessagePath(const std::string& iMessagePath)
    {
        std::cout << iMessagePath << std::endl;
        _messagePath = iMessagePath;
        _messages = _messageBuilder.getMessages(_messagePath);
        _currentMessage = 0;
    }

    std::map<std::string, std::string> ProtoBufConverter::getAlgorithms()
    {
        return algorithm::ConversionAlgorithm::GetAlgorithms();
    }
    
    std::string ProtoBufConverter::convertReadableToBinary(const std::string& iReadableString)
    {
        for (auto aMessage : _messages)
        {
            // Populate message from human readable representation in input.
            if (google::protobuf::TextFormat::ParseFromString(iReadableString, aMessage))
            {
                // Save message to use for decoding.
                _currentMessage = aMessage;
                
                // Serialize binary representation of string.
                std::string aBinString;
                aMessage->SerializeToString(&aBinString);

                return aBinString;
            }
        }
               
        return "Something went wrong...";
    }

    std::string ProtoBufConverter::convertBinaryToReadable(const std::string& iBinaryString)
    {

        if (_currentMessage)
        {
            _currentMessage->ParseFromString(iBinaryString);
            std::string aJsonString;
            google::protobuf::TextFormat::PrintToString(*_currentMessage, &aJsonString);
            return aJsonString;
        }
        
        for (auto aMessage : _messages)
        {
            // Populate message from binary string.
            if (aMessage->ParseFromString(iBinaryString))
            {                
                // Serialize json representation of string.
                std::string aJsonString;
                google::protobuf::TextFormat::PrintToString(*aMessage, &aJsonString);
                
                return aJsonString;     
            }
        }
        
        return "Something went wrong...";
            
    }
}
