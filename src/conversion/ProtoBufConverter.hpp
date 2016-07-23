#ifndef PROTO_BUF_CONVERTER
#define PROTO_BUF_CONVERTER

#include "ConversionInterface.hpp"

namespace protobuf_decoder
{
    
    class ProtoBufConverter : public ConversionInterface
    {
    public:

        virtual std::string encode(const std::string& iDecodedString);

        virtual std::string decode(const std::string& iEncodedString);

        virtual void setEncodeAlgorithm(const std::string& iAlgoName);

        virtual void setMessagePath(const std::string& iMessagePath);
    };
    
}   

#endif // PROTO_BUF_CONVERTER
