#include "ProtoBufConverterTest.hpp"

#include "../../src/conversion/ProtoBufConverter.hpp"

using namespace protobuf_decoder;
using namespace std;

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
 * Test that handling of one single message file.
 *
 *
 */
TEST(ProtoBufConverterTest, singleFileEncoding)
{
    TestEncodeDecode(
        "test/data/message_single_file",
        "0A07616E64726561731017",
        "name: \"andreas\"\nage: 23\n");
}

/**
 * Test that two message files are correctly handled.
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
