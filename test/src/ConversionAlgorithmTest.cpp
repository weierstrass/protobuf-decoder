#include "ConversionAlgorithmTest.hpp"

#include "../../src/conversion/algorithm/ConversionAlgorithm.hpp"

using protobuf_decoder::algorithm::ConversionAlgorithm;
using protobuf_decoder::algorithm::ConversionAlgorithmInterface;

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
