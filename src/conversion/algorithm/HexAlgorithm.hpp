#ifndef _HEX_ALGORITHM_
#define _HEX_ALGORITHM_

#include "BaseAlgorithm.hpp"
#include <iostream>

namespace protobuf_decoder
{
    namespace algorithm
    {
        /**
         * @brief Algorithm handling hexadecimal encoding/decoding. 
         */
        class HexAlgorithm : public BaseAlgorithm<HexAlgorithm>
        {
        public:
            virtual ~HexAlgorithm() {}

            virtual std::string encode(const std::string& iString);

            virtual std::string decode(const std::string& iString);
        };
    }
}

#endif //_HEX_ALGORITHM_
