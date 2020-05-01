#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Domain/Spaceport/Session.hpp"


namespace Domain::Spaceport
{
  class PlayerSession : public Domain::Spaceport::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~PlayerSession() noexcept override;
  }; // class PlayerMenu





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PlayerSession::~PlayerSession() noexcept
  {}


  inline std::vector<std::string> PlayerSession::getCommands()
  {
    return { "Start Mission", "Scoreboard", "Store", "Settings", "Logout"};
  }

} // namespace Domain::Spaceport