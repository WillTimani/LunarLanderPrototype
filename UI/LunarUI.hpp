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
 
  class LunarUI : public UI::UserInterfaceHandler
  {
    public:
      // Constructors
      using UserInterfaceHandler::UserInterfaceHandler;  // inherit constructors
      LunarUI();


      // Operations
      void launch(std::string role) override;
      void login() override;


      // Destructor
      ~LunarUI() noexcept override;


    private:
      std::unique_ptr<Domain::AccountManagement::LoginHandler>  _accounts;

      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>            _loggerPtr;
      TechnicalServices::Persistence::PersistenceHandler                  & _persistentData;


      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
  };
} // namespace UI