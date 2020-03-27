#pragma once

#include <memory>
#include <string>
#include <vector>


#include "Domain/Spaceport/Menu.hpp"


namespace Domain::Spaceport
{
  class AdminMenu : public Domain::Spaceport::MenuHandler
  {
    public:
      using MenuHandler::MenuHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~AdminMenu() noexcept override;
  }; // class AdminMenu





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline AdminMenu::~AdminMenu() noexcept
  {}


  inline std::vector<std::string> AdminMenu::getCommands()
  {
    return { "Settings", "Scorebaord", "Logout" };
  }

} // namespace Domain::Spaceport