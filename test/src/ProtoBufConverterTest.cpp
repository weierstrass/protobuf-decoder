#include "ProtoBufConverterTest.hpp"

#include "../../src/conversion/ProtoBufConverter.hpp"
#include "../../src/conversion/ConversionException.hpp"

using namespace protobuf_decoder;
using namespace std;


/**
 * @brief Helper for doing an encode-decode test.
 *
 * @param iMessagePath The path to the message files relative repo root.
 * @param iEncodedString Expected encoded data.
 * @param iDecodedString Expected decoded data.
 */
static void TestEncodeDecode(
    const std::string& iMessagePath,
    const std::string& iEncodedString,
    const std::string& iDecodedString)
{
    ProtoBufConverter aConverter;
    aConverter.setMessagePath(iMessagePath);
    
    EXPECT_EQ(iEncodedString, aConverter.encode(iDecodedString));	
    EXPECT_EQ(iDecodedString, aConverter.decode(iEncodedString));	
    
}

/**
 * Single file in path should be handled.
 */
TEST(ProtoBufConverterTest, singleFileEncoding)
{
    TestEncodeDecode(
        "test/data/message_single_file",
        "0A07616E64726561731017",
        "name: \"andreas\"\nage: 23\n");
}

/**
 * Two (unrelated) files in the same path should both be taken into acount.
 *
 * It should be possible to convert either of the grammars defined
 * in the files. The messages in the files do not reference to each
 * other, the correct file to be used should be automatically
 * detected and the other ignored.
 */
TEST(ProtoBufConverterTest, multiFileConversion1)
{
    TestEncodeDecode( // first file
        "test/data/message_multi_files",
        "0A07616E6472656173",
        "first: \"andreas\"\n");
}
TEST(ProtoBufConverterTest, multiFileConversion2)
{

    TestEncodeDecode( // second file
        "test/data/message_multi_files",
        "08D209",
        "second: 1234\n");    
}

/**
 * The converter should throw ConversionException in case of invalid
 * message path.
 */
TEST(ProtoBufConverterTest, unableParseReadable)
{
    ProtoBufConverter aConverter;
    aConverter.setMessagePath("invalid path");
    
    try
    {
        aConverter.decode("DEADBEEF");
    }
    catch(ConversionException& iEx)
    {
        ASSERT_GE(iEx._text.size(), 1);
    }
    catch(...) { FAIL(); }
}

/**
 * The converter should detect and be able to return all valid
 * message files in the folder given in input.
 */
TEST(ProtoBufConverterTest, retrievePossibleMessages)
{
    ProtoBufConverter aConverter;
    aConverter.setMessagePath("test/data/message_multi_files");

    ASSERT_EQ(size_t(2), aConverter.getMessages().size());

    ASSERT_EQ("First", aConverter.getMessages().front());
}

/**
 * The converter should return the message used after a conversion.
 */
TEST(ProtoBufConverterTest, getMessageTypeEncode) // Encode
{
    ProtoBufConverter aConverter;
    aConverter.setMessagePath("test/data/message_single_file");

    aConverter.encode("name: \"andreas\"\nage: 23\n");
    
    ASSERT_EQ("Person", aConverter.getMessageType());
}
TEST(ProtoBufConverterTest, getMessageTypeDecode) // Decode
{
    ProtoBufConverter aConverter;
    aConverter.setMessagePath("test/data/message_single_file");

    aConverter.decode("0A07616E64726561731017");
    
    ASSERT_EQ("Person", aConverter.getMessageType());
}
