#ifndef MESSAGE_BUILDER
#define MESSAGE_BUILDER

#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/dynamic_message.h>

namespace protobuf_decoder
{
    class MyErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector
    {
    public:
        virtual void AddError(
            const std::string & filename,
            int line,
            int column,
            const std::string & message);
    };

    
    class MessageBuilder
    {
    public:
        MessageBuilder() : _importer(&_sourceTree, &_errorCollector) {}

        google::protobuf::Message* getMessage(const std::string& iMessagePath);

        std::vector<google::protobuf::Message*> getMessages(const std::string& iMessagePath);
    private:
        google::protobuf::compiler::DiskSourceTree _sourceTree;

        MyErrorCollector _errorCollector;
        
        google::protobuf::compiler::Importer _importer;

        google::protobuf::DynamicMessageFactory _messageFactory;        
    };
}

#endif // MESSAGE_BUILDER
