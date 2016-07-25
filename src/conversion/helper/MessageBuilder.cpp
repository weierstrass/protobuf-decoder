#include "MessageBuilder.hpp"

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include <iostream>

namespace fs = boost::filesystem;

namespace protobuf_decoder
{

    void MyErrorCollector::AddError(
        const std::string & filename,
        int line,
        int column,
        const std::string & message)
    {
        std::cout << "ABAB" << std::endl;
        std::cerr << "File " << filename << " - " << message << std::endl;
    }

    struct MessageFileReader
    {
        MessageFileReader(
            google::protobuf::compiler::Importer& iImporter,
            google::protobuf::DynamicMessageFactory& iMessageFactory) :
            _importer(iImporter), _messageFactory(iMessageFactory) {}

        void operator()(const std::string& iMessageFile)
        {
            // Import message file, ignore if not an accepted message file.
            const google::protobuf::FileDescriptor* aFile = _importer.Import(iMessageFile);
            if (!aFile) // Import successful?
            {
                std::cout << "invalid file: " << iMessageFile << std::endl;
                return;
            }

            // Create descriptor for message type.
            const google::protobuf::Descriptor* aDescriptor = aFile->message_type(0);

            std::cout << aDescriptor->DebugString() << std::endl;

            // Build message from descriptor.
            const google::protobuf::Message* prototype = _messageFactory.GetPrototype(aDescriptor);
            // Append a mutable message to collection.
            _messages.push_back(prototype->New());
        }

        std::vector<google::protobuf::Message*> _messages;
    private:
        google::protobuf::compiler::Importer& _importer;

        google::protobuf::DynamicMessageFactory& _messageFactory;        
    };

    
    std::vector<google::protobuf::Message*> MessageBuilder::getMessages(
        const std::string& iMessagePath)
    {
        // Search for message files in message path.
        fs::path full_path(fs::initial_path<fs::path>());
        full_path = fs::system_complete( fs::path( iMessagePath ) );

        // Verify that the provided path really is existing.
        if ( !fs::exists( full_path ) )
        {
            std::cout << "Message path not found: " << full_path.filename() << std::endl;
            return std::vector<google::protobuf::Message*>();
        }

        // Collect list of potential message files
        std::vector<std::string> aMessageFiles;
        std::for_each(fs::directory_iterator(full_path), fs::directory_iterator(),
                      [&aMessageFiles](fs::directory_entry &iFile)
                      {
                          if (fs::is_regular_file(iFile.status()))
                          {
                              aMessageFiles.push_back(iFile.path().filename().string());
                              std::cout << iFile.path().filename() << "\n";
                          }
                      }
            );
        
        // Set the path of the message files to the source tree.
        _sourceTree.MapPath("", iMessagePath);

       
        return for_each(aMessageFiles.begin(), aMessageFiles.end(),
                 MessageFileReader(_importer, _messageFactory))._messages;
        
    }

    google::protobuf::Message* MessageBuilder::getMessage(const std::string& iMessagePath)
    {
        return getMessages(iMessagePath).front();
    }

}
