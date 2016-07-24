#ifndef PROTO_BUF_CONVERTER
#define PROTO_BUF_CONVERTER

#include "ConversionInterface.hpp"

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

        virtual std::string encode(const std::string& iDecodedString);

        virtual std::string decode(const std::string& iEncodedString);

        virtual void setEncodeAlgorithm(const std::string& iAlgoName);

        virtual void setMessagePath(const std::string& iMessagePath);

    private:

        /**
         * @brief Returns binary representation of the decoded data.
         *
         * Constructs a protbuf::Message and build the binary string
         * from the json representation in iDecodedString.
         *
         * @param iDecodedString Decoded json representation.
         * @return std::string Binary representation.
         */
        std::string getBinaryDecodedString(const std::string& iDecodedString);


        std::string convertBinaryToJson(const std::string& iBinaryString);
        std::string _messagePath;
    };
    
}   

#endif // PROTO_BUF_CONVERTER
