#include "ProtoBufConverterTest.hpp"

#include "../../src/conversion/ProtoBufConverter.hpp"

using namespace protobuf_decoder;

TEST(ProtoBufConverterTest, simpleEncodeTest)
{
    ProtoBufConverter aConverter;

    aConverter.encode("suck it");
    
    EXPECT_EQ(1000, 999+1);	
}
