//=================PersistenceHandler.hpp======================//

#pragma once

#include <stdexcept>   // domain_error
#include <string>
#include <vector>


namespace TechnicalServices::Persistence
{
  // User Credentials struct definition 
  struct userCredentials
  {
    std::string userName;
    std::string password;
  };

  class PersistenceHandler
  {
    public:
      // Exceptions
      struct InvalidLogin : std::domain_error {using domain_error::domain_error;};


      // Constructors
      PersistenceHandler(); 
      PersistenceHandler(const PersistenceHandler &  original);                    
      PersistenceHandler(PersistenceHandler && original);                    


      // Operations
      virtual userCredentials findCredentialsByName(const std::string & name);   // Returns credentials for specified user, throws NoSuchUser if user not found

      // Destructor
      virtual ~PersistenceHandler() noexcept;

    protected:
      PersistenceHandler & operator=(const PersistenceHandler &  rhs);         
      PersistenceHandler & operator=(PersistenceHandler && rhs);           
  };

}
