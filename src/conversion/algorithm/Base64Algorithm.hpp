#ifndef _BASE64_ALGORITHM_
#define _BASE64_ALGORITHM_

#include "BaseAlgorithm.hpp"

namespace protobuf_decoder
{
    namespace algorithm
    {
        /**
         * @brief Algorithm handling base64 encoding/decoding.
         * 
         * Standard implementation using + and / as extra characters 
         * and = for padding.
         * 
         * https://en.wikipedia.org/wiki/Base64
         */
        class Base64Algorithm : public BaseAlgorithm<Base64Algorithm>
        {
        public:
            virtual ~Base64Algorithm() {}

            virtual std::string encode(const std::string& iString);

            virtual std::string decode(const std::string& iString);
        };
        
    }
}

#endif // _BASE64_ALGORITHM_
