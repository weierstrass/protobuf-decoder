#ifndef UPPER_LOWER_CASE_CONVERTER
#define UPPER_LOWER_CASE_CONVERTER

#include "ConversionInterface.hpp"

namespace protobuf_decoder
{

class UpperLowerCaseConverter : public ConversionInterface
{
public:

    virtual std::string encode(const std::string& iDecodedString);

    virtual std::string decode(const std::string& iEncodedString);

    virtual void setEncodeAlgorithm(const std::string& iAlgoName);

    virtual void setMessagePath(const std::string& iMessagePath);

};

}


#endif // UPPER_LOWER_CASE_CONVERTER
