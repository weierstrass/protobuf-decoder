#include "ConversionAlgorithm.hpp"

#include <iostream>

namespace protobuf_decoder
{
    namespace algorithm
    {

        ConversionAlgorithm::ConversionAlgorithm(const std::string& iKey)
        {
            // The first time this constructor is called, assume that it is
            // for the static exemplar of this type. The assumption should
            // always be valid. If it turns out not to work a dedicated
            // constructor prototype must be used to register the static
            // exemplars, this will polute the class definition of the
            // top level classes and is better to avoid if possible.
            if (getExemplars().find(iKey) == getExemplars().end())
            {
                std::cout << "Registering " << iKey << std::endl;
                getExemplars()[iKey] = this;
            }
        }
        
        std::shared_ptr<ConversionAlgorithmInterface> ConversionAlgorithm::Create(const std::string& iKey)
        {
            std::map<std::string, ConversionAlgorithm*>& aExemplars = getExemplars();

            std::cout << "size: " << aExemplars.size() << std::endl;
            
            if (aExemplars.find(iKey) != aExemplars.end())
            {
                return aExemplars[iKey]->create();
            }
            else
            {
                std::cerr << "No algorithm registerd for key: " << iKey << std::endl;
            }

            return std::shared_ptr<ConversionAlgorithmInterface>();
        }


        std::map<std::string, ConversionAlgorithm*> &ConversionAlgorithm::getExemplars()
        {
            static std::map<std::string, ConversionAlgorithm*> aExemplars;
            return aExemplars;
        }

        
        std::map<std::string, std::string> ConversionAlgorithm::GetAlgorithms()
        {
            std::map<std::string, std::string> aAlgorithms;

            for(auto aAlgorithm : getExemplars())
            {
                aAlgorithms.insert(std::pair<std::string, std::string>
                                   (aAlgorithm.first, aAlgorithm.second->getName()));
            }

            return aAlgorithms;
        }
       
    }
}
