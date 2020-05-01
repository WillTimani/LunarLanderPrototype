//==================================== AdminMenu ============================//

#pragma once

#include <memory>
#include <string>
#include <vector>


#include "Domain/Spaceport/Session.hpp"


namespace Domain::Spaceport
{
  class AdminSession : public Domain::Spaceport::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
     ~AdminSession() noexcept override;
  }; // class AdminSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline AdminSession::~AdminSession() noexcept
  {}


  inline std::vector<std::string> AdminSession::getCommands()
  {
    return { "Settings", "Scorebaord", "Logout" };
  }

} // namespace Domain::Spaceport