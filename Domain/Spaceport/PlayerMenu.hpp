#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Domain/Spaceport/Menu.hpp"


namespace Domain::Spaceport
{
  class PlayerMenu : public Domain::Spaceport::MenuHandler
  {
    public:
      using MenuHandler::MenuHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~PlayerMenu() noexcept override;
  }; // class PlayerMenu





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline PlayerMenu::~PlayerMenu() noexcept
  {}


  inline std::vector<std::string> PlayerMenu::getCommands()
  {
    return { "Start Mission", "Scoreboard", "Store", "Settings", "Logout"};
  }

} // namespace Domain::Spaceport