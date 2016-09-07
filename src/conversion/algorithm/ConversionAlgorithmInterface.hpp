#ifndef _CONVERSION_ALGORITHM_INTERFACE_
#define _CONVERSION_ALGORITHM_INTERFACE_

#include <string>
#include <map>

namespace protobuf_decoder
{
    namespace algorithm
    {
        /**
         * @brief Interface for a conversion algorithm.
         * 
         * Visible functions to caller classes. The main
         * purpose of this interface is to hide the virtual 
         * constructor implementation for the client.
         */
        class ConversionAlgorithmInterface
        {
        public:
            /**
             * @brief Destructor. 
             */
            virtual ~ConversionAlgorithmInterface() {}
            
            /**
             * @brief Encode implementation for algorithm.
             * 
             * @param iString Binary represenation.
             * 
             * @return string Encoded representation.
             */
            virtual std::string encode(const std::string& iString) = 0;

            /**
             * @brief Decode implementation for algorithm.
             * 
             * @param iString Encoded representation.
             * 
             * @return string Binary representation.
             */
            virtual std::string decode(const std::string& iString) = 0;

            /**
             * @brief Name of algorithm.
             * 
             * This is the name that will be seen by the end user.
             * 
             * @return string Name.
             */
            virtual std::string getName() = 0;
        };
        
    }
}

#endif // _CONVERSION_ALGORITHM_INTERFACE_
