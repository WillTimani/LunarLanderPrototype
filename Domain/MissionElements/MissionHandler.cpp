//========================== MissionHandler.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/MissionElements/MissionHandler.hpp"
#include "Domain/MissionElements/Mission.hpp"

namespace Domain::MissionElements
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<MissionHandler> MissionHandler::createMission()
  {
      return std::make_unique<Mission>();
  }

} // namespace Domain::MissionElements