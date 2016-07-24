#include "ProtoBufConverter.hpp"

#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/dynamic_message.h>

#include <boost/algorithm/hex.hpp>

#include <iostream>

using namespace google::protobuf;

namespace protobuf_decoder
{

    class MyErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector
    {
        virtual void AddError(
            const std::string & filename,
            int line,
            int column,
            const std::string & message)
            {
                std::cerr << "File " << filename << " - " << message << std::endl;
            }
    };

    std::string ProtoBufConverter::encode(const std::string& iDecodedString)
    {
        std::string aBinString, aEncodedString;

        aBinString = getBinaryDecodedString(iDecodedString);
        
        boost::algorithm::hex(aBinString, std::back_inserter(aEncodedString));
        
        return aEncodedString;
    }

    std::string ProtoBufConverter::decode(const std::string& iEncodedString)
    {
        std::string aBinString;

        boost::algorithm::unhex(iEncodedString, std::back_inserter(aBinString));

        return convertBinaryToJson(aBinString);
    }

    void ProtoBufConverter::setEncodeAlgorithm(const std::string& iAlgoName)
    {
        
    }

    void ProtoBufConverter::setMessagePath(const std::string& iMessagePath)
    {
        _messagePath = iMessagePath;
    }

    class MessageBuilder
    {
    public:
        MessageBuilder() : _importer(&_sourceTree, &_errorCollector) {}

        google::protobuf::Message* getMessage(const std::string& iMessagePath)
        {
            _sourceTree.MapPath("", iMessagePath);
            const google::protobuf::FileDescriptor* aFile = _importer.Import("single_file.proto");
            if (!aFile) // Import successful?
            {
                std::cout << "no file" << std::endl;
                return 0;
            }       
            const google::protobuf::Descriptor* aDescriptor = aFile->message_type(0);

            std::cout << aDescriptor->DebugString() << std::endl;

            // Build message from descriptor.
            const google::protobuf::Message* prototype = _messageFactory.GetPrototype(aDescriptor);
            return prototype->New();

        }
    private:
        google::protobuf::compiler::DiskSourceTree _sourceTree;

        MyErrorCollector _errorCollector;
        
        google::protobuf::compiler::Importer _importer;

        google::protobuf::DynamicMessageFactory _messageFactory;        
    };
    
    
    std::string ProtoBufConverter::getBinaryDecodedString(const std::string& iDecodedString)
    {
        // Get a message object.
        MessageBuilder aMessageBuilder;
        google::protobuf::Message* aMessage = aMessageBuilder.getMessage(_messagePath);

        if (aMessage)
        {
            // Populate message from json representation in input.
            google::protobuf::TextFormat::ParseFromString(iDecodedString, aMessage);

            // Serialize binary representation of string.
            std::string aBinString;
            aMessage->SerializeToString(&aBinString);

            return aBinString;
        }
        
        return "Something went wrong...";
    }


    std::string ProtoBufConverter::convertBinaryToJson(const std::string& iBinaryString)
    {
        // Get a message object.
        MessageBuilder aMessageBuilder;
        google::protobuf::Message* aMessage = aMessageBuilder.getMessage(_messagePath);

        if (aMessage)
        {
            // Populate message from binary string.
            aMessage->ParseFromString(iBinaryString);

            // Serialize json representation of string.
            std::string aJsonString;
            google::protobuf::TextFormat::PrintToString(*aMessage, &aJsonString);

            return aJsonString;
        }
        
        return "Something went wrong...";
            
    }
}
