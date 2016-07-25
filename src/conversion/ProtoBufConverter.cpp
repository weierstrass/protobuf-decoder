#include "ProtoBufConverter.hpp"

#include "helper/MessageBuilder.hpp"

#include <boost/algorithm/hex.hpp>

#include <google/protobuf/io/tokenizer.h>

#include <iostream>

using std::string;

namespace protobuf_decoder
{

    std::string ProtoBufConverter::encode(const std::string& iDecodedString)
    {
        std::string aBinString, aEncodedString;

        aBinString = convertJsonToBinary(iDecodedString);
        
        boost::algorithm::hex(aBinString, std::back_inserter(aEncodedString));
        
        return aEncodedString;
    }

    std::string ProtoBufConverter::decode(const std::string& iEncodedString)
    {
        std::string aBinString;

        boost::algorithm::unhex(iEncodedString, std::back_inserter(aBinString));

        return convertBinaryToJson(aBinString);
    }

    void ProtoBufConverter::setEncodeAlgorithm(const std::string& iAlgoName)
    {
        
    }

    void ProtoBufConverter::setMessagePath(const std::string& iMessagePath)
    {
        _messagePath = iMessagePath;
        _messages = _messageBuilder.getMessages(_messagePath);
        _currentMessage = 0;
    }
    
    std::string ProtoBufConverter::convertJsonToBinary(const std::string& iJsonString)
    {
        for (auto aMessage : _messages)
        {
            // Populate message from json representation in input.
            if (google::protobuf::TextFormat::ParseFromString(iJsonString, aMessage))
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


    std::string ProtoBufConverter::convertBinaryToJson(const std::string& iBinaryString)
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
