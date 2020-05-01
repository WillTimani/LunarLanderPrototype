//========================== PersistenceHandler.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "TechnicalServices/Persistence/LoginDB.hpp"

namespace TechnicalServices::Persistence
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<PersistenceHandler> PersistenceHandler::createPersistentData()
  {
      return std::make_unique<LoginDB>();
  }

} // namespace TechnicalServices::Persistence