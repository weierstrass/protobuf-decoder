#include "UpperLowerCaseConverter.hpp"

#include <boost/algorithm/string.hpp>

namespace protobuf_decoder
{
    

    std::string UpperLowerCaseConverter::encode(const std::string& iDecodedString)
    {
        return boost::to_upper_copy<std::string>(iDecodedString);
    }

    std::string UpperLowerCaseConverter::decode(const std::string& iEncodedString)
    {
        return boost::to_lower_copy<std::string>(iEncodedString);
    }

    void UpperLowerCaseConverter::setEncodeAlgorithm(const std::string& iAlgoName)
    {
        
    }

    void UpperLowerCaseConverter::setMessagePath(const std::string& iMessagePath)
    {
        
    }


}
