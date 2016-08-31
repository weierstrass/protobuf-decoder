#ifndef _CONVERSION_EXCEPTION_
#define _CONVERSION_EXCEPTION_

#include <string>
#include <exception>

namespace protobuf_decoder
{
  /**
   * @brief Exception class for functional exceptions.
   *
   * Throw an exception of this type to propagate an error/text
   * to the user.
   */
  struct ConversionException : public std::exception
  {
    /**
     * @brief Constructor
     *
     * @param iText Text message to propagate.
     */
    ConversionException(const std::string& iText) : _text(iText) {}

    /// The text message.
    std::string _text;
  };
}

#endif //_ALGORITHM_EXCEPTION_
