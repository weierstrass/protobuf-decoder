#include "ConversionAlgorithmTest.hpp"

#include "../../src/conversion/algorithm/ConversionAlgorithm.hpp"

using protobuf_decoder::algorithm::ConversionAlgorithm;
using protobuf_decoder::algorithm::ConversionAlgorithmInterface;
using protobuf_decoder::ConversionException;

static void TestEncodeDecodeAlgorithm(
    const std::string& iKey,
    const std::string& iEncodedString,
    const std::string& iDecodedString)
{
    std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm =
        ConversionAlgorithm::Create(iKey);
    
    ASSERT_TRUE(aAlgorithm.get() != 0);

    ASSERT_EQ(iEncodedString, aAlgorithm->encode(iDecodedString));
    ASSERT_EQ(iDecodedString, aAlgorithm->decode(iEncodedString));
}

TEST(ConversionAlgorithmTest, creation)
{
    std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm =
        ConversionAlgorithm::Create("HEX");
    
    ASSERT_TRUE(aAlgorithm.get() != 0);
}

TEST(ConversionAlgorithmTest, nonExistingKey)
{
    std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm =
    ConversionAlgorithm::Create("i hope no one will ever use this as key...");

    ASSERT_TRUE(aAlgorithm.get() == 0);
}

TEST(ConversionAlgorithmTest, getAllAlgorithms)
{
    std::map<std::string, std::string> aAlgorithms = ConversionAlgorithm::GetAlgorithms();

    ASSERT_GE(aAlgorithms.size(), size_t(1));
}

TEST(ConversionAlgorithmTest, hex)
{
    TestEncodeDecodeAlgorithm(
        "HEX",
        "6865782069732074686520736869742E",
        "hex is the shit.");
}

TEST(ConversionAlgorithmTest, noHexChar)
{
    try
    {
        ConversionAlgorithm::Create("HEX")->decode("HEXZOR");
        FAIL();
    }
    catch(const ConversionException& iEx)
    {
        ASSERT_GE(iEx._text.size(), 1);
    }
    catch(...) { FAIL(); }
}

TEST(ConversionAlgorithmTest, oddNumberOfChars)
{
    try
    {
        ConversionAlgorithm::Create("HEX")->decode("ODD");
        FAIL();
    }
    catch(const ConversionException& iEx)
    {
        ASSERT_GE(iEx._text.size(), 1);
    }
    catch(...) { FAIL(); }
}

TEST(ConversionAlgorithmTest, base64)
{
    TestEncodeDecodeAlgorithm(
        "BASE 64",
        "YmFzZTY0IGlzIHRoZSBzaGl0Lg==",
        "base64 is the shit.");
}
