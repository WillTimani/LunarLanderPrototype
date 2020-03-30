//========================== Lander.cpp ============================//

#include "Domain/Spaceport/Lander.hpp"

namespace Domain::Spaceport
{

	Lander::Lander(){
		speed = 0;
		fuel = 100;
		yPos = 1000;
		thrustersActive = false;

	}

	int Lander::getSpeed(){
		return speed;
	}

	int Lander::getYPos(){
		return yPos;
	}

	void Lander::activateThrusters(){
		thrustersActive = true; 
	}

	void Lander::deactivateThrusters(){
		thrustersActive = false;
	}

	bool Lander::thrusters(){
		return thrustersActive;
	}

	void Lander::move(){
		if(thrustersActive && speed < 3){
			speed++;
		} else if (!thrustersActive){
			speed--;
		}

		yPos += speed; 

	}








}