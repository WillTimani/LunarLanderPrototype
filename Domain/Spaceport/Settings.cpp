//=====================Settings.cpp==================//

#include <string>
#include <vector>
#include <memory>

#include "Domain/Spaceport/Settings.hpp"

#include "TechnicalServices/Logging/Logger.hpp"

namespace Domain::Spaceport
{


  Settings::Settings()
  : _loggerPtr( std::make_unique<TechnicalServices::Logging::Logger>() )    
  {
  	resolutionOptions =
		{
			{"800 x 600"},
			{"1280 x 720"},
			{"1600 x 900"},
			{"1920 x 1080"},
			{"3840 x 2160"}
		};
    _logger << "Settings being used and has been successfully initialized";
  }

  // Destructor
  Settings::~Settings() noexcept
  {
    _logger << "Settings shutdown successfully";
  }

  std::vector<std::string> Settings::getSettingsOptions(){

  	static std::vector<std::string> options =
		{
			{"Change Resolution"},
			{"Change Volume"}
		};

	return options;

  }

  std::vector<std::string> Settings::getResolutionOptions(){

	return resolutionOptions;

  }

  void Settings::changeResolution(unsigned selection){

  	// resolution to be updated to a persistent database

  	_logger << "Changing resolution to " + resolutionOptions[selection]; 

  }




}