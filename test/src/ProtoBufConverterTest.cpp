#include "ProtoBufConverterTest.hpp"

#include "../../src/conversion/ProtoBufConverter.hpp"

using namespace protobuf_decoder;
using namespace std;


TEST(ProtoBufConverterTest, singleFileEncoding)
{
    const string aDecodedString = "name: \"andreas\"\nage: 23\n";
    const string aEncodedString = "0A07616E64726561731017";
    
    ProtoBufConverter aConverter;
    aConverter.setMessagePath("test/data/message_single_file");
    
    EXPECT_EQ(aEncodedString, aConverter.encode(aDecodedString));	
    EXPECT_EQ(aDecodedString, aConverter.decode(aEncodedString));	
}
