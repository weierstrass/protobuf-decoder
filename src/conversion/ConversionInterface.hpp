#ifndef CONVERSION_INTERFACE_H
#define CONVERSION_INTERFACE_H

namespace protobuf_decoder
{

class ConversionInterface
{
public:

    virtual std::string encode(const std::string& iDecodedString) = 0;

    virtual std::string decode(const std::string& iEncodedString) = 0;

    virtual void setEncodeAlgorithm(const std::string& iAlgoName) = 0;

    virtual void setMessagePath(const std::string& iMessagePath) = 0;

};

}

#endif // CONVERSION_INTERFACE_H
