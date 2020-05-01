//========================== ShopHandler.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Spaceport/ShopHandler.hpp"
#include "Domain/Spaceport/SpaceShop.hpp"

namespace Domain::Spaceport
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<ShopHandler> ShopHandler::createSpaceShop()
  {
      return std::make_unique<SpaceShop>();
  }

} // namespace Domain::Spaceport