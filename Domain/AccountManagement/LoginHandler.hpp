//========================== LoginHandler.hpp ===========================//
#pragma once

#include <string>

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace Domain::AccountManagement
{
  // Import the User Credentials type from the lower layer and publish it as your own
  using TechnicalServices::Persistence::UserCredentials;

  // Login Handler Package within the Domain Layer Abstract class
  class LoginHandler
  {
    public:
      // Constructors and assignment operations
      LoginHandler()                                                = default;    // default ctor
      LoginHandler( const LoginHandler &  original )                = default;    // copy ctor
      LoginHandler(       LoginHandler && original )                = default;    // move ctor


      // Operations
      virtual bool isAuthenticated( const UserCredentials & credentials ) = 0;

      // Object Factory returning a UserAccounts object
      static std::unique_ptr<LoginHandler> createAccounts();


      // Abstract class destructor
      virtual ~LoginHandler() noexcept = 0;  // must be virtual and pure

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      LoginHandler & operator=( const LoginHandler &  rhs ) = default;    // copy assignment
      LoginHandler & operator=(       LoginHandler && rhs ) = default;    // move assignment
 };





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline LoginHandler::~LoginHandler() noexcept
  {}


} // namespace Domain::AccountManagement
