//============================== UserAccounts.cpp ============================//

#include <algorithm>    // std::any_of()
#include <memory>       // make_unique<>()

#include "Domain/AccountManagement/UserAccounts.hpp"

#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/SingletonDB.hpp"


namespace Domain::AccountManagement
{
  // Default constructor
  UserAccounts::UserAccounts()
  : _persistentData( TechnicalServices::Persistence::SingletonDB::instance() ),       
    _loggerPtr     ( std::make_unique<TechnicalServices::Logging::Logger>() )   
  {
    _logger << "UserAccounts being used and has been successfully initialized";
  }


  // Destructor
  UserAccounts::~UserAccounts() noexcept
  {
    _logger << "UserAccounts shutdown successfully";
  }



  // Operations
  bool UserAccounts::isAuthenticated( const UserCredentials & credentials )
  {
    try
    {
      UserCredentials credentialsFromDB = _persistentData.findCredentialsByName( credentials.userName );

      // std::set_intersection might be a better choice, but here I'm assuming there will be one and only one role in the passed-in
      // credentials I just need to verify the requested role is in the set of authorized roles.  Someday, if a user can sign in
      // with many roles combined, I may have to revisit this approach.  But for now, this is good enough.
      if(    credentials.userName   == credentialsFromDB.userName
          && credentials.password == credentialsFromDB.password
          && std::any_of( credentialsFromDB.roles.cbegin(), credentialsFromDB.roles.cend(),
                          [&]( const std::string & role ) { return credentials.roles.size() > 0 && credentials.roles[0] == role; }
                        )
        ) return true;
    }
    catch( const TechnicalServices::Persistence::PersistenceHandler::InvalidLogin & ) {}  // Catch and ignore this anticipated condition

    return false;
  }

} // namespace Domain::AccountManagement
