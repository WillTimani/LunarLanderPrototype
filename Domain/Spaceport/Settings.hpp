//=======================Settings.hpp======================//

#include <string>
#include <vector>
#include <memory>

#pragma once

#include "Domain/Spaceport/SettingsHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"

namespace Domain::Spaceport
{

	class Settings : public Domain::Spaceport::SettingsHandler{

		public:
      		// Constructors
      		using SettingsHandler::SettingsHandler;  // inherit constructors
      		Settings();


		    // Operations
		    std::vector<std::string> getSettingsOptions() override;
		    std::vector<std::string> getResolutionOptions();
		    void changeResolution(unsigned selection);


		    // Destructor
		    ~Settings() noexcept override;


		private:

			std::vector<std::string> resolutionOptions; 

		    std::unique_ptr<TechnicalServices::Logging::LoggerHandler>            _loggerPtr;
		    TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;


	};



}