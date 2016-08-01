#include "ConversionAlgorithmTest.hpp"

#include "../../src/conversion/algorithm/ConversionAlgorithm.hpp"

using protobuf_decoder::algorithm::ConversionAlgorithm;
using protobuf_decoder::algorithm::ConversionAlgorithmInterface;
using protobuf_decoder::ConversionException;

TEST_F(ConversionAlgorithmTest, creation)
{
    std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm = ConversionAlgorithm::Create("hex");

    ASSERT_TRUE(aAlgorithm.get() != 0);
}

TEST_F(ConversionAlgorithmTest, nonExistingKey)
{
std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm = ConversionAlgorithm::Create("i hope no one will ever use this as key...");

    ASSERT_TRUE(aAlgorithm.get() == 0);
}

TEST_F(ConversionAlgorithmTest, hex)
{
    const std::string aEncodedString = "6865782069732074686520736869742E";
    const std::string aDecodedString = "hex is the shit.";

    std::shared_ptr<ConversionAlgorithmInterface> aAlgorithm = ConversionAlgorithm::Create("hex");
    
    ASSERT_TRUE(aAlgorithm.get() != 0);

    ASSERT_EQ(aEncodedString, aAlgorithm->encode(aDecodedString));
    ASSERT_EQ(aDecodedString, aAlgorithm->decode(aEncodedString));
}

TEST_F(ConversionAlgorithmTest, getAllAlgorithms)
{
    std::map<std::string, std::string> aAlgorithms = ConversionAlgorithm::GetAlgorithms();

    ASSERT_GE(aAlgorithms.size(), size_t(1));
}

TEST_F(ConversionAlgorithmTest, noHexChar)
{
    try
    {
        ConversionAlgorithm::Create("hex")->decode("HEXZOR");
        FAIL();
    }
    catch(const ConversionException& iEx)
    {
        ASSERT_GE(iEx._text.size(), 1);
    }
    catch(...) { FAIL(); }
}

TEST_F(ConversionAlgorithmTest, oddNumberOfChars)
{
    try
    {
        ConversionAlgorithm::Create("hex")->decode("ODD");
        FAIL();
    }
    catch(const ConversionException& iEx)
    {
        ASSERT_GE(iEx._text.size(), 1);
    }
    catch(...) { FAIL(); }
}
