#ifndef _CONVERSION_ALGORITHM_
#define _CONVERSION_ALGORITHM_

#include "ConversionAlgorithmInterface.hpp"
#include "../ConversionException.hpp"

#include <memory>
#include <string>
#include <map>

namespace protobuf_decoder
{
    namespace algorithm
    {
        class ConversionAlgorithm : public ConversionAlgorithmInterface
        {
        public:
            ConversionAlgorithm(const std::string& iKey);
            
            virtual ~ConversionAlgorithm() {}
            
            static std::shared_ptr<ConversionAlgorithmInterface> Create(const std::string& iKey);

            virtual std::shared_ptr<ConversionAlgorithmInterface> create() = 0;

            static std::map<std::string, std::string> GetAlgorithms();

        private:
            static std::map<std::string, ConversionAlgorithm*> &getExemplars();
        };
    }
}

#endif //_CONVERSION_ALGORITHM_
