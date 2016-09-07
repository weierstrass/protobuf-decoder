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
        /**
         * @brief Constructor base for algorithms.
         * 
         * Base in virtual constructor pattern responsible for managing the 
         * creation of algorithm objects from a string key.
         */
        class ConversionAlgorithm : public ConversionAlgorithmInterface
        {
        public:
            /**
             * @brief Constructor
             * 
             * On first call, will register the algorithm and its
             * key in a static table.
             */
            ConversionAlgorithm(const std::string& iKey);
            
            /**
             * @brief Destructor 
             */
            virtual ~ConversionAlgorithm() {}
            
            /**
             * @brief Create algorithm from key.
             * 
             * @note If no algorithm has been registered for key in input
             * an empty shared_ptr will be returned.
             * 
             * @param iKey Key for algorithm.
             * 
             * @return shared_ptr<ConversionAlgorithmInterface> Algorithm.
             */
            static std::shared_ptr<ConversionAlgorithmInterface> Create(const std::string& iKey);

            /**
             * @brief Creation for algorithm.
             * 
             * Should be implemented for each algorithm.
             * 
             * @return std::shared_ptr<ConversionAlgorithmInterface> Algorithm.
             */
            virtual std::shared_ptr<ConversionAlgorithmInterface> create() = 0;

            /**
             * @brief Get all registered algorithms.
             * 
             * @return map<string, string> Name, key pair for all algorithms.
             */
            static std::map<std::string, std::string> GetAlgorithms();

        private:
            /**
             * @brief Get static registration table.
             * 
             * @return map<string, ConversionAlgorithm*> Key, exemplar pair.
             */
            static std::map<std::string, ConversionAlgorithm*> &getExemplars();
        };
    }
}

#endif //_CONVERSION_ALGORITHM_
