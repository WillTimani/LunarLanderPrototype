//=================PersistenceHandler.hpp======================//

#pragma once

#include <stdexcept>   // domain_error
#include <string>
#include <vector>


namespace TechnicalServices::Persistence
{
  // User Credentials struct definition 
  struct UserCredentials
  {
    std::string userName;
    std::string password;
    std::vector<std::string> roles;
  };

  class PersistenceHandler
  {
    public:
      // Exceptions
      struct InvalidLogin : std::domain_error {using domain_error::domain_error;};


      // Constructors
      PersistenceHandler() = default; 
      PersistenceHandler(const PersistenceHandler &  original) = default;                    
      PersistenceHandler(PersistenceHandler && original) = default;                    


      // Operations
      virtual std::vector<std::string> findRoles() = 0; // Returns list of roles
      virtual UserCredentials findCredentialsByName(const std::string & name) = 0;   // Returns credentials for specified user, throws NoSuchUser if user not found

      // Destructor
      virtual ~PersistenceHandler() noexcept = 0;

    protected:
      PersistenceHandler & operator=(const PersistenceHandler &  rhs) = default;         
      PersistenceHandler & operator=(PersistenceHandler && rhs) = default;           
  };

  inline PersistenceHandler::~PersistenceHandler() noexcept
  {}


}
