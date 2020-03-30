//========================== Lander.hpp =================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Spaceport/Ship.hpp"

#pragma once

namespace Domain::Spaceport
{

	class Lander : public Domain::Spaceport::Ship
	{
		public:
			// Constructors
			Lander();

			// Operations 
			void activateThrusters();
			void deactivateThrusters();
			bool thrusters();
			void move();
			int getYPos();
			int getSpeed();

			// Destructor
			~Lander() noexcept override; 

		private:
			int speed;
			int fuel;
			//int xPos;
			int yPos;
			bool thrustersActive;


	}; // class Lander

	inline Lander::~Lander() noexcept
	{}

}