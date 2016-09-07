#ifndef _BASE_ALGORITHM_
#define _BASE_ALGORITHM_

#include "ConversionAlgorithm.hpp"

#include <iostream>

/**
 * @brief Macro used to register an algorithm.
 * 
 * A static exemplar of the aglorithm will be added in the
 * ConversionAlgorithm class with the corresponding key provided.
 * ConversionAlgorithm is managing the construction of new algorihtm 
 * objects from the key. (Virtual constructor pattern.)
 */
#define REGISTER_ALGORITHM(CLASS, KEY) \
template <>\
std::string protobuf_decoder::algorithm::BaseAlgorithm<CLASS>::_key(KEY); \
template <>\
CLASS protobuf_decoder::algorithm::BaseAlgorithm<CLASS>::_exemplar{};

namespace protobuf_decoder
{
    namespace algorithm
    {
        /**
         * @brief Base class for new algorithms.
         * 
         * Handles common parts related to the registration
         * of algorithms.
         * 
         * @tparam T Algorithm class (CRTP)
         */
        template <typename T>
        class BaseAlgorithm : public ConversionAlgorithm
        {
        public:
            /**
             * @brief Constructor
             * 
             * Passes on the registration key to the ConversionAlgorithm class
             * that will register the class in its table.
             */
            BaseAlgorithm() : ConversionAlgorithm(_key) {}

            /**
             * @brief Destructor 
             */
            virtual ~BaseAlgorithm() {}

            /**
             * @brief Returns name of algorithm.
             * 
             * Default implemenation, uses the key as name.
             * 
             * @return Name of algorithm.
             */
            std::string getName()
            {
                return _key;
            }
            
            /**
             * @brief Create new algorithm object.
             * 
             * @return shared_ptr<T> Shared pointer to algorithm.
             */
            std::shared_ptr<ConversionAlgorithmInterface> create()
            {
                std::cout << "new obj" << std::endl;
                return std::make_shared<T>();
            }

            /// Key for algorithm. (static since it is used in static registration table.)
            static std::string _key;

        protected:
            /// Static exemplar of algorithm, used in virtual constructor.
            static T _exemplar;

        };
    }
}

#endif // _BASE_ALGORITHM_
