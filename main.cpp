//main.cpp
//Here is the sample "main.cpp" from the sourcecode provided to us on Titanium
//This is to be made to work with Lunar Lander

/******************************************************************************

Employees:
  Matthew Quinlan
  Will Timani
  Thomas Smith
  Vijay Duggirala
  
Lunar Lander 2020 C++

******************************************************************************/



//not all includes will be needed
#include <exception>
#include <iostream>
#include <memory>
#include <new>
#include <iostream>
#include <locale>

#include "UI/LunarUI.hpp"
#include "UI/UserInterfaceHandler.hpp"


using namespace std;

int main( /*int argc, char argv[] */ )
{

	std::unique_ptr<UI::UserInterfaceHandler> userInterface( new UI::LunarUI ); 
  
  	userInterface->login();
  
  
}
