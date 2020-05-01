//========================== LoginHandler.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/AccountManagement/LoginHandler.hpp"
#include "Domain/AccountManagement/UserAccounts.hpp"

namespace Domain::AccountManagement
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<LoginHandler> LoginHandler::createAccounts()
  {
      return std::make_unique<Domain::AccountManagement::UserAccounts>();
  }

} // namespace Domain::AccountManagement