#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/MissionElements/Mission.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/SingletonDB.hpp"             


namespace Domain::MissionElements
{

	Mission::Mission(){
		inMission = true;
		_instanceLander = std::make_unique<Domain::Spaceport::Lander>();
	}

	void Mission::startMission(){
		terrainLevel = 0;
	}

	void Mission::endMission(){
		inMission = false;
	}


	bool Mission::missionStatus(){
		return inMission;
	}

	int Mission::processTurn(){
		_instanceLander->move();
		if(_instanceLander->getYPos() <= terrainLevel && _instanceLander->getSpeed() >= 8){
			inMission = false;
			return 2; // lander crashed
		} else if(_instanceLander->getYPos() <= terrainLevel && _instanceLander->getSpeed() < 8){
			inMission = false;
			return 1; // successfully landed
		}
		return 0;
	}

	void Mission::requestThrusterChange(int c){
		if(c == 0) _instanceLander->activateThrusters();
		else _instanceLander->deactivateThrusters();

	}

	std::string Mission::getTurnStatement(){
		std::string statement = "Thrusters On: " + std::string(_instanceLander->thrusters() ? "True" : "False");
		statement += " YPos: " + std::to_string(_instanceLander->getYPos());
		statement += " Speed: " + std::to_string(_instanceLander->getSpeed());

		return statement;
	}




}