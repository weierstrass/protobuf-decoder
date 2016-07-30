#ifndef _ALGORITHM_EXCEPTION_
#define _ALGORITHM_EXCEPTION_

#include <string>
#include <exception>

namespace protobuf_decoder
{
    namespace algorithm
    {
        struct AlgorithmException : public std::exception
        {
            AlgorithmException(const std::string& iText) : _text(iText) {}

            std::string _text;
        };
    }
}
#endif //_ALGORITHM_EXCEPTION_
