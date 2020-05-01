//========================== Ship.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Spaceport/Ship.hpp"
#include "Domain/Spaceport/Lander.hpp"

namespace Domain::Spaceport
{
  // returns a specialized object specific to the specified role
  Ship *  Ship::createLander()
  {
      return new Lander();
  }

} // namespace Domain::Spaceport