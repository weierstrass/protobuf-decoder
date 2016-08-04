#include "Base64Algorithm.hpp"


namespace protobuf_decoder
{
    namespace algorithm
    {
        REGISTER_ALGORITHM(Base64Algorithm, "BASE 64");
        
        std::string Base64Algorithm::encode(const std::string& iString)
        {
            return "BASE 64";
        }

        std::string Base64Algorithm::decode(const std::string& iString)
        {
            return "BASE 64 decode";
        }
        
    }
}
