#ifndef PROTO_BUF_CONVERTER
#define PROTO_BUF_CONVERTER

#include <vector>
#include <memory>

#include "ConversionInterface.hpp"
#include "helper/MessageBuilder.hpp"

namespace google
{
  namespace protobuf
  {
    class Message;
    class DynamicMessageFactory;
    class Importer;
  }
}

namespace protobuf_decoder
{
  namespace algorithm
  {
    class ConversionAlgorithmInterface;
  }
  
  /**
   * @brief Converter implementation for protobuf data.
   */
  class ProtoBufConverter : public ConversionInterface
  {
  public:
    /**
     * @brief Constructor.
     *
     * @note Defaults the conversion algorithm to HEX.
     */
    ProtoBufConverter();
    
    /**
     * @brief Encodes data in clear using the conversion algorithm.
     *
     * @param iHumanReadable Human readable representation.
     *
     * @return string Binary representation encoded.
     */
    virtual std::string encode(const std::string& iHumanReadable);

    /**
     * @brief Decodes data in binary representation.
     *
     * @param iEncoded Binary data encoded with the current algorithm.
     *
     * @return string Human readable representation.
     */
    virtual std::string decode(const std::string& iEncoded);
    
    /**
     * @brief Set the conversion algorithm to use. E.g. HEX, BASE64 etc.
     *
     * @param iAlgoName Name of algorithm.
     * The name is the name used when registering the algorithm in its
     * implmentation.
     *
     * @return void.
     */
    virtual void setEncodeAlgorithm(const std::string& iAlgoName);
    
    /**
     * @brief Set the path to the grammar files.
     *
     * @param iMessagePath Path to grammar files.
     *
     * @return void.
     */
    virtual void setMessagePath(const std::string& iMessagePath);

    virtual void setMessageType(const std::string& iMessageType);

    virtual std::string getMessageType();
        
    virtual std::map<std::string, std::string> getAlgorithms();

    virtual std::vector<std::string> getMessages();
    
  private:

    /**
     * @brief Returns binary from human readable representation.
     *
     * @param iReadableString Human readable representation.
     * @return std::string Binary representation.
     */
    std::string convertReadableToBinary(const std::string& iReadableString);

    /**
     * @brief Returns human readable representation from binary data.
     *
     * @param iBinaryString Message serialized binary.
     * @return std::string Human readable representation.
     */
    std::string convertBinaryToReadable(const std::string& iBinaryString);

    std::string _messagePath;

    std::vector<google::protobuf::Message*> _messages;

    google::protobuf::Message* _currentMessage;

    MessageBuilder _messageBuilder;

    std::shared_ptr<algorithm::ConversionAlgorithmInterface> _algorithm;
  };
    
}   

#endif // PROTO_BUF_CONVERTER
