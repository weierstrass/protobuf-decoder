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
    namespace algorithm
    {
        class ConversionAlgorithmInterface;
    }

    class ProtoBufConverter : public ConversionInterface
    {
    public:
        ProtoBufConverter();
        
        virtual std::string encode(const std::string& iDecodedString);

        virtual std::string decode(const std::string& iEncodedString);

        virtual void setEncodeAlgorithm(const std::string& iAlgoName);

        virtual void setMessagePath(const std::string& iMessagePath);

        virtual std::map<std::string, std::string> getAlgorithms();
    
    private:

        /**
         * @brief Returns binary from human readable representation.
         *
         * @param iReadableString Human readable representation.
         * @return std::string Binary representation.
         */
        std::string convertReadableToBinary(const std::string& iReadableString);

        /**
         * @brief Returns human readable representation from binary data.
         *
         * @param iBinaryString Message serialized binary.
         * @return std::string Human readable representation.
         */
        std::string convertBinaryToReadable(const std::string& iBinaryString);

        std::string _messagePath;

        std::vector<google::protobuf::Message*> _messages;

        google::protobuf::Message* _currentMessage;

        MessageBuilder _messageBuilder;

        std::shared_ptr<algorithm::ConversionAlgorithmInterface> _algorithm;
    };
    
}   

#endif // PROTO_BUF_CONVERTER
