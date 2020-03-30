//========================== UserAccounts.hpp ============================//

#pragma once

#include <memory>    // std::unique_ptr
#include <string>

#include "LoginHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"



namespace Domain::AccountManagement
{
  class UserAccounts : public Domain::AccountManagement::LoginHandler
  {
    public:
      using LoginHandler::LoginHandler;  // inherit constructors
      UserAccounts();

      // Operations
      bool isAuthenticated( const UserCredentials & credentials ) override;


      // Destructor
      ~UserAccounts() noexcept override;


    private:
      TechnicalServices::Persistence::PersistenceHandler &   _persistentData;
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;

      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
  };
} // namespace Domain::AccountManagement
