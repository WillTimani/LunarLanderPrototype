//========================LoginDB.hpp=====================//

#pragma once

#include <memory>    // unique_ptr
#include <string>
#include <vector>

#include "Technical/Logging/LoggerHandler.hpp"
#include "Technical/Persistence/PersistenceHandler.hpp"




namespace Technical::Persistence
{
  class LoginDB : public Technical::Persistence::PersistenceHandler
  {
    public:
      using PersistenceHandler::PersistenceHandler;    // inherit constructors
      LoginDB();


      // Operations
      std::vector<std::string> findRoles()                                       override;  // Returns list of all legal roles
      UserCredentials          findCredentialsByName( const std::string & name ) override;  // Returns credentials for specified user, throws NoSuchUser if user not found


      ~SimpleDB() noexcept override;

    private:
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;

      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;

  };
}  // namespace TechnicalServices::Persistence