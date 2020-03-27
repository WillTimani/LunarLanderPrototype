//LunarUI.hpp

#pragma once

#include <memory>    // std::unique_ptr
#include <string>

#include "Domain/AccountManagement/LoginHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

#include "UI/UserInterfaceHandler.hpp"


namespace UI
{
  /*****************************************************************************
  ** Simple UI definition
  **   Simple UI is a console application meant only as a driver to the Domain Layer application. This UI will someday be replaced
  **   by a more sophisticated, user friendly implementation
  ******************************************************************************/
  class LunarUI : public UI::UserInterfaceHandler
  {
    public:
      // Constructors
      using UserInterfaceHandler::UserInterfaceHandler;  // inherit constructors
      LunarUI();


      // Operations
      void launch(std::string role);
      void login() override;


      // Destructor
      ~LunarUI() noexcept override;


    private:
      // These smart pointers hold pointers to lower architectural layer's interfaces
      std::unique_ptr<Domain::AccountManagement::LoginHandler>  _accounts;

      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>            _loggerPtr;
      TechnicalServices::Persistence::PersistenceHandler                  & _persistentData;


      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
  };
} // namespace UI