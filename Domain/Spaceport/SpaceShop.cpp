//SpaceShop.cpp

#include <memory>
#include <string>

#include <Domain/Spaceport/SpaceShop.hpp>

#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/ShopDB.hpp"                          

namespace Domain::Spaceport
{

	SpaceShop::SpaceShop()
	: _loggerPtr( std::make_unique<TechnicalServices::Logging::Logger>() )     // will replace these factory calls with abstract factory calls next increment
  	{
    	_database = std::make_unique<TechnicalServices::Persistence::ShopDB>();
		options = _database->findShopItems();

    	_logger << "SpaceShop being used and has been successfully initialized";
  	}

	std::vector<std::string> SpaceShop::getOptions(){

		std::vector<std::string> definedOptions;

		for(unsigned i = 0; i < options.size(); i++){
			definedOptions.push_back(options[i].name + " : " + std::to_string(options[i].price));
		}

		return definedOptions;

	}

	bool SpaceShop::purchaseItem(unsigned selection){

		if(selection >= options.size()) return false;
		
		if(!contactTransactionService()) return false;
		
		_logger << "Third Party Transaction successful. " + options[selection].name + " has been purchased.";

		options.erase(options.begin() + selection);

		return true;

	}

	bool SpaceShop::contactTransactionService(){
		// insert third party functions here
		// automatically returns successful until functions are added

		return true;
	}







}