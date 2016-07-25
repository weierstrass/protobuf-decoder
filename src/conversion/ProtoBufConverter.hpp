#ifndef PROTO_BUF_CONVERTER
#define PROTO_BUF_CONVERTER

#include <vector>

#include "ConversionInterface.hpp"
#include "helper/MessageBuilder.hpp"

namespace google
{
    namespace protobuf
    {
        class Message;
        class DynamicMessageFactory;
        class Importer;
    }
}

namespace protobuf_decoder
{
    
    class ProtoBufConverter : public ConversionInterface
    {
    public:
        ProtoBufConverter() : _currentMessage(0) {}
        
        virtual std::string encode(const std::string& iDecodedString);

        virtual std::string decode(const std::string& iEncodedString);

        virtual void setEncodeAlgorithm(const std::string& iAlgoName);

        virtual void setMessagePath(const std::string& iMessagePath);

    private:

        /**
         * @brief Returns binary representation of json data.
         *
         * @param iJsonString Message serialized as json.
         * @return std::string Binary representation.
         */
        std::string convertJsonToBinary(const std::string& iJsonString);

        /**
         * @brief Returns json representation from binary data.
         *
         * @param iBinaryString Message serialized binary.
         * @return std::string Json representation.
         */
        std::string convertBinaryToJson(const std::string& iBinaryString);

        std::string _messagePath;

        std::vector<google::protobuf::Message*> _messages;

        google::protobuf::Message* _currentMessage;

        MessageBuilder _messageBuilder;

    };
    
}   

#endif // PROTO_BUF_CONVERTER
