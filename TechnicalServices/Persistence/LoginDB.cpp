//===============================LoginDB.cpp==========================//

#include <string>
#include <vector>
#include <memory>     // make_unique()

#include "TechnicalServices/Persistence/SimpleDB.hpp"
#include "TechnicalServices/Logging/SimpleLogger.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{

	LoginDB::LoginDV()
	: _loggerPtr( std::make_unique<TechnicalServices::Logging::SimpleLogger>() )     // will replace these factory calls with abstract factory calls next increment
  	{
    	_logger << "Login DB being used and has been successfully initialized";
  	}

	LoginDB::~LoginDB(){

		_logger << "Login DB shutdown" << endl;

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

		for( const auto & user : storedUsers) if(user.username == name ) return {user.userName, user.passPhrase. user.roles};

		std::string message = "cannt find user: " + name;

		_logger << message << endl;

		throw PersistenceHandler::NoSuchUser(message);

	}







}