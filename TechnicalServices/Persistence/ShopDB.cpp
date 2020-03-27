//===============================ShopDB.cpp==========================//

#include <string>
#include <vector>
#include <memory>     // make_unique()

#include "TechnicalServices/Persistence/ShopDB.hpp"
#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{
	
	ShopDB::ShopDB()
	: _loggerPtr( std::make_unique<TechnicalServices::Logging::Logger>() )     // will replace these factory calls with abstract factory calls next increment
  	{
    	_logger << "Shop DB being used and has been successfully initialized";
  	}

	ShopDB::~ShopDB() noexcept {

		_logger << "Shop DB shutdown";

	}

	std::vector<shopObject> ShopDB::findShopItems(){

		static std::vector<shopObject> storedItems =
		{
			{"Extra Fuel", 100},
			{"Durability Up", 200}
		};

		return storedItems;
			
	}

	std::vector<std::string> ShopDB::findRoles(){
	}

	UserCredentials ShopDB::findCredentialsByName( const std:: string & name){
	}





}