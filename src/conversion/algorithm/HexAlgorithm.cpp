#include "HexAlgorithm.hpp"

#include <boost/algorithm/hex.hpp>

namespace protobuf_decoder
{
    namespace algorithm
    {
        REGISTER_ALGORITHM(HexAlgorithm, "hex");
        
        std::string HexAlgorithm::encode(const std::string& iString)
        {
            std::string aEncodedString;
            boost::algorithm::hex(iString, std::back_inserter(aEncodedString));
            
            return aEncodedString;
        }

        std::string HexAlgorithm::decode(const std::string& iString)
        {
            std::string aDecodedString;
            boost::algorithm::unhex(iString, std::back_inserter(aDecodedString));

            return aDecodedString;
        }

        std::string HexAlgorithm::getName()
        {
            return "HEX";
        }

    }
}
