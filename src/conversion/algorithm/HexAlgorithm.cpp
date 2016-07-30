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

            try
            {
                boost::algorithm::unhex(iString, std::back_inserter(aDecodedString));
            }
            catch(const boost::algorithm::non_hex_input& iEx)
            {
                throw AlgorithmException("Non hex character detected in input.");
            }
            catch(const boost::algorithm::not_enough_input& iEx)
            {
                throw AlgorithmException("An even number of charcters is needed.");
            }
            
            return aDecodedString;
        }

        std::string HexAlgorithm::getName()
        {
            return "HEX";
        }

    }
}
