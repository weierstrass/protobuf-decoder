#ifndef _CONVERSION_EXCEPTION_
#define _CONVERSION_EXCEPTION_

#include <string>
#include <exception>

namespace protobuf_decoder
{
    struct ConversionException : public std::exception
    {
        ConversionException(const std::string& iText) : _text(iText) {}

        std::string _text;
    };
}
#endif //_ALGORITHM_EXCEPTION_
