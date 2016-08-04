#ifndef _BASE_ALGORITHM_
#define _BASE_ALGORITHM_

#include "ConversionAlgorithm.hpp"

#include <iostream>

#define REGISTER_ALGORITHM(CLASS, KEY) \
template <>\
std::string protobuf_decoder::algorithm::BaseAlgorithm<CLASS>::_key(KEY); \
template <>\
CLASS protobuf_decoder::algorithm::BaseAlgorithm<CLASS>::_exemplar{};

namespace protobuf_decoder
{
    namespace algorithm
    {
        template <typename T>
        class BaseAlgorithm : public ConversionAlgorithm
        {
        public:
            BaseAlgorithm() : ConversionAlgorithm(_key) {}

            virtual ~BaseAlgorithm() {}

            std::string getName()
            {
                return _key;
            }
            
            std::shared_ptr<ConversionAlgorithmInterface> create()
            {
                std::cout << "new obj" << std::endl;
                return std::make_shared<T>();
            }

            static std::string _key;

        protected:
            static T _exemplar;

        };
    }
}

#endif // _BASE_ALGORITHM_
