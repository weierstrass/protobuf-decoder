#include "HexAlgorithm.hpp"

#include <boost/algorithm/hex.hpp>

namespace protobuf_decoder
{
    namespace algorithm
    {
        REGISTER_ALGORITHM(HexAlgorithm, "HEX");
        
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
                throw ConversionException("Non hex character detected in input.");
            }
            catch(const boost::algorithm::not_enough_input& iEx)
            {
                throw ConversionException("An even number of characters is needed.");
            }
            
            return aDecodedString;
        }

    }
}
