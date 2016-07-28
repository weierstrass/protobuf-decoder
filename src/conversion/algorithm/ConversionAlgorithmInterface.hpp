#ifndef _CONVERSION_ALGORITHM_INTERFACE_
#define _CONVERSION_ALGORITHM_INTERFACE_

#include <string>
#include <map>

namespace protobuf_decoder
{
    namespace algorithm
    {
        
        class ConversionAlgorithmInterface
        {
        public:
            virtual ~ConversionAlgorithmInterface() {}
            
            virtual std::string encode(const std::string& iString) = 0;

            virtual std::string decode(const std::string& iString) = 0;

            virtual std::string getName() = 0;
        };
        
    }
}

#endif // _CONVERSION_ALGORITHM_INTERFACE_
