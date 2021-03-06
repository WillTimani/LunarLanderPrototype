//========================ShopDB.hpp=====================//

#pragma once

#include <memory>    // unique_ptr
#include <string>
#include <vector>

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"



namespace TechnicalServices::Persistence
{

  struct shopObject
  {
    std::string name;
    int price; 
  };


  class ShopDB : public TechnicalServices::Persistence::PersistenceHandler {
  
    public:
      using PersistenceHandler::PersistenceHandler;    // inherit constructors
      ShopDB();

      // Operations 
      std::vector<shopObject> findShopItems();

      // not used
      std::vector<std::string> findRoles()                                       override;  // Returns list of all legal roles
      UserCredentials          findCredentialsByName( const std::string & name ) override;  // Returns credentials for specified user, throws NoSuchUser if user not found


      ~ShopDB() noexcept override;

    private:
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;

      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;

  };
}  // namespace TechnicalServices::Persistence
