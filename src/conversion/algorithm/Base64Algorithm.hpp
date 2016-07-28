#ifndef _BASE64_ALGORITHM_
#define _BASE64_ALGORITHM_

#include "BaseAlgorithm.hpp"


namespace protobuf_decoder
{
    namespace algorithm
    {

        class Base64Algorithm : public BaseAlgorithm<Base64Algorithm>
        {
        public:
            virtual ~Base64Algorithm() {}

            virtual std::string encode(const std::string& iString);

            virtual std::string decode(const std::string& iString);

            virtual std::string getName();
        };
        
    }
}

#endif // _BASE64_ALGORITHM_
