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

        virtual std::string decode(const std::string& iEncodedString) = 0;

        virtual void setEncodeAlgorithm(const std::string& iAlgoName) = 0;

        virtual void setMessagePath(const std::string& iMessagePath) = 0;

    };

}

#endif // CONVERSION_INTERFACE_H
