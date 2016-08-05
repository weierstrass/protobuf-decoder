#include "Base64Algorithm.hpp"

#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>

namespace protobuf_decoder
{
    namespace algorithm
    {
        REGISTER_ALGORITHM(Base64Algorithm, "BASE 64");
        
        std::string Base64Algorithm::encode(const std::string& iString)
        {
            using namespace boost::archive::iterators;
            using It = base64_from_binary<transform_width<std::string::const_iterator, 6, 8>>;

            // Encode in base 64
            auto aBase64Encoded = std::string(It(std::begin(iString)), It(std::end(iString)));

            // Add padding 
            return aBase64Encoded.append((3 - iString.size() % 3) % 3, '=');
        }

        std::string Base64Algorithm::decode(const std::string& iString)
        {
            using namespace boost::archive::iterators;
            using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;

            // Decode and remove padding.
            return boost::algorithm::trim_right_copy_if(
                std::string(It(std::begin(iString)), It(std::end(iString))),
                [](char c)
                {
                    return c == '\0';
                });
        }

    }
}
