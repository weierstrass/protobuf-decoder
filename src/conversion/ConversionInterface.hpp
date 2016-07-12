#ifndef CONVERSION_INTERFACE_H
#define CONVERSION_INTERFACE_H

#include <string>

namespace protobuf_decoder
{

    /**
     * @brief Interface for conversion implementations.
     */
    class ConversionInterface
    {
    public:

        /**
         * @brief Algorithm to apply on decoded string to encode it.
         *
         * @param iDecodedString The string to encode.
         *
         * @return std::string The encoded string.
         */
        virtual std::string encode(const std::string& iDecodedString) = 0;

        /**
         * @brief Algorithm to apply on encoded string to decode it.
         *
         * @param iEncodedString The string to decode.
         *
         * @return std::string The decoded string.
         */
        virtual std::string decode(const std::string& iEncodedString) = 0;

        /**
         * @brief Sets the encode algorithm to use when encoding.
         *
         * The algorithm is implemented using the bla bla interface.
         *
         * @param iAlgoName The key for the algorithm.
         *
         * @return void
         */
        virtual void setEncodeAlgorithm(const std::string& iAlgoName) = 0;

        /**
         * @brief Sets the path to the proto grammar message files.
         *
         * @param iMessagePath The path to message files.
         *
         * @return void
         */
        virtual void setMessagePath(const std::string& iMessagePath) = 0;

    };

}

#endif // CONVERSION_INTERFACE_H
