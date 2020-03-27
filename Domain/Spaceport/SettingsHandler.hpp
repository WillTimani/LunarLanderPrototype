//=================SettingsHandler.hpp======================//

#pragma once

#include <string>
#include <vector>


namespace Domain::Spaceport
{

  class SettingsHandler
  {
    public:

      // Constructors
      SettingsHandler() = default; 
      SettingsHandler(const SettingsHandler &  original) = default;                    
      SettingsHandler(SettingsHandler && original) = default;                    

      // Operations
      virtual std::vector<std::string> getSettingsOptions() = 0;
      
      // Destructor
      virtual ~SettingsHandler() noexcept = 0;

    protected:
      SettingsHandler & operator=(const SettingsHandler &  rhs) = default;         
      SettingsHandler & operator=(SettingsHandler && rhs) = default;           
  };

  inline SettingsHandler::~SettingsHandler() noexcept
  {}

}
