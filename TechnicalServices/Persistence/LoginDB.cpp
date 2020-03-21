//===============================LoginDB.cpp==========================//

#include <string>
#include <vector>
#include <memory>     // make_unique()

#include "TechnicalServices/Persistence/LoginDB.hpp"
#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{

	LoginDB::LoginDB()
	: _loggerPtr( std::make_unique<TechnicalServices::Logging::Logger>() )     // will replace these factory calls with abstract factory calls next increment
  	{
    	_logger << "Login DB being used and has been successfully initialized";
  	}

	LoginDB::~LoginDB() noexcept {

		_logger << "Login DB shutdown";

	}

	std::vector<std::string> LoginDB::findRoles(){

		return { "Player", "Admin"};

	}

	UserCredentials LoginDB::findCredentialsByName( const std:: string & name){

		static std::vector<UserCredentials> storedUsers =
		{
			{"Will", "Bill", {"Player", "Admin"}},
			{"Matt", "Batt", {"Player"}}
		};

		for( const auto & user : storedUsers) if(user.userName == name ) return {user.userName, user.password, user.roles};

		std::string message = "cannt find user: " + name;

		_logger << message;

		throw PersistenceHandler::InvalidLogin(message);

	}







}