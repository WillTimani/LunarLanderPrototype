//LunarUI.cpp

#include <iomanip>                                                                    // setw()
#include <iostream>                                                                   // streamsize
#include <limits>                                                                     // numeric_limits
#include <memory>                                                                     // unique_ptr, make_unique<>()
#include <string>                                                                     // string, getline()
#include <vector>

#include "Domain/AccountManagement/UserAccounts.hpp"                                  // Include for now - will replace next increment
#include "Domain/Spaceport/Menu.hpp"
#include "Domain/Spaceport/SpaceShop.hpp"
#include "Domain/Spaceport/Settings.hpp"
#include "Domain/MissionElements/Mission.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Logging/Logger.hpp"                                 // Include for now - will replace next increment
#include "TechnicalServices/Persistence/SingletonDB.hpp"                              // Include for now - will replace next increment

#include "UI/LunarUI.hpp"

namespace UI
{
  // Default constructor
  LunarUI::LunarUI()
  : _accounts      ( std::make_unique<Domain::AccountManagement::UserAccounts>()  ),   // will replace these factory calls with abstract factory calls in the next increment
    _loggerPtr     ( std::make_unique<TechnicalServices::Logging::Logger>() ),   // will replace these factory calls with abstract factory calls in the next increment
    _persistentData( TechnicalServices::Persistence::SingletonDB::instance()      )    // will replace these factory calls with abstract factory calls in the next increment
  {
    _logger << "Lunar UI being used and has been successfully initialized";
  }


  // Destructor
  LunarUI::~LunarUI() noexcept
  {
    _logger << "Lunar UI shutdown successfully";
  }

  // Operations
  void LunarUI::launch(std::string role)
  {

  	std::vector<std::string> roleLegalValues = _persistentData.findRoles();

  	// 4) Fetch functionality options for this role
    std::unique_ptr<Domain::Spaceport::MenuHandler> menuControl = Domain::Spaceport::MenuHandler::createSession( role );

    std::cout << "Main Menu" << std::endl;

    std::vector<std::string> commands = menuControl->getCommands();
    unsigned menuSelection;
    do
    {
      for( unsigned i = 0; i != commands.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << commands[i] << '\n';
      std::cout << "  role (0-" << commands.size()-1 << "): ";
      std::cin  >> menuSelection;
    } while( menuSelection >= commands.size() );

    std::string selectedCommand = commands[menuSelection];
    _logger << "Selected command \"" + selectedCommand + "\" chosen";

    // Command Functionalities 

    // Start Mission
    if(menuSelection == 0)
    {
    	std::unique_ptr<Domain::MissionElements::Mission> missionControl = std::make_unique<Domain::MissionElements::Mission>();;

    	missionControl->startMission();

    	_logger << "Mission Started";

    	unsigned turnSelection;
    	unsigned turnResult;
    	do
    	{
    		std::cout << "0 - Activate thrusters" << std::endl;
    		std::cout << "1 - Deactivate thrusters" << std::endl;
    		std::cout << "2 - End turn" << std::endl;
    		std::cout << "3 - Exit level" << std::endl;
    		std::cin >> turnSelection;
    		if(turnSelection == 0){
    			missionControl->requestThrusterChange(0);
    		} else if (turnSelection == 1){
    			missionControl->requestThrusterChange(1);
    		} else if (turnSelection == 3){
    			missionControl->endMission();
    			break;
    		}

    		turnResult = missionControl->processTurn();
    		std::cout << missionControl->getTurnStatement() << std::endl;

    		if(turnResult == 1){
    			std::cout << "You have successfully landed the lander!" << std::endl;
    		} else if(turnResult == 2){
    			std::cout << "You have failed to land the lander." << std::endl;
    		} 
    	} while(missionControl->missionStatus());

    	_logger << "Mission Ended by Player";

    	this->launch(role);
    	
    } else if (menuSelection == 1){

    } else if (menuSelection == 2) {
    	std::unique_ptr<Domain::Spaceport::SpaceShop> shopControl = std::make_unique<Domain::Spaceport::SpaceShop>();

	    std::vector<std::string> shopOptions = shopControl->getOptions();
    	do{
	   
	    	unsigned itemSelection;

	    	for(int i = 0; i < shopOptions.size(); i++){
	    		std::cout << std::to_string(i) + " - " + shopOptions[i] << std::endl;
	    	}

	    	std::cout << std::to_string(shopOptions.size()) + " - " + "Exit Store" << std::endl;

	    	std::cin >> itemSelection;

	    	if(itemSelection == shopOptions.size()) break;

	    	if(shopControl->purchaseItem(itemSelection)){
	    		std::cout << "Successfully purchased: " + shopOptions[itemSelection] << std::endl;
	    		shopOptions.erase(shopOptions.begin() + itemSelection);
	    	}

	    } while(true);

	    _logger << "Store Exited";

	    this->launch(role);

    } else if (menuSelection == 3) {
    	std::unique_ptr<Domain::Spaceport::Settings> settingsControl = std::make_unique<Domain::Spaceport::Settings>();

    	std::vector<std::string> settingsOptions = settingsControl->getSettingsOptions();
    	do{

    		unsigned settingsSelection;

    		for(int i = 0; i < settingsOptions.size(); i++){
    			std::cout << std::to_string(i) + " - " + settingsOptions[i] << std::endl;
    		}

    		std::cout << std::to_string(settingsOptions.size()) + " - " + "Exit Settings" << std::endl;

    		std::cin >> settingsSelection;

    		if(settingsSelection >= settingsOptions.size()) break;

    		if(settingsSelection == 0){
    			do{
	    			std::vector<std::string> resOptions = settingsControl->getResolutionOptions();
	    			
	    			unsigned resSelect;
	    			for(int i = 0; i < resOptions.size(); i++){
	    				std::cout << std::to_string(i) + " - " + resOptions[i] << std::endl;
	    			}

	    			std::cin >> resSelect;

	    			if(resSelect < resOptions.size()){
	    				settingsControl->changeResolution(resSelect);
	    				break;
	    			}
    			} while(true);
    		}



    	} while(true);

    	_logger << "Settings Exited";

    	this->launch(role);


    } else if (menuSelection == 4) {
    	_logger << "Logging " + role + " out of Lunar Lander";
    	this->login();
    }



  }

  void LunarUI::login()
  {
  		// 1) Fetch Role legal value list

    std::vector<std::string> roleLegalValues = _persistentData.findRoles();
    std::string selectedRole;

    // 2) Present login screen to user and get username, password, and valid role
 
    do
    {
      std::cin.ignore(  std::numeric_limits<std::streamsize>::max(), '\n' );

      std::string userName;
      std::cout << "  name: ";
      std::getline( std::cin, userName );

      std::string passPhrase;
      std::cout << "  pass phrase: ";
      std::getline( std::cin, passPhrase );

      unsigned menuSelection;
      do
      {
        for( unsigned i = 0; i != roleLegalValues.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << roleLegalValues[i] << '\n';
        std::cout << "  role (0-" << roleLegalValues.size()-1 << "): ";
        std::cin  >> menuSelection;
      } while( menuSelection >= roleLegalValues.size() );

      selectedRole = roleLegalValues[menuSelection];


      // 3) Validate user is authorized for this role
      if( _accounts->isAuthenticated( { userName, passPhrase, {selectedRole} } ) )
      {
        _logger << "Login Successful for \"" + userName + "\" as role \"" + selectedRole + "\"";
        break;
      }

      std::cout << "** Login failed\n";
      _logger << "Login failure for \"" + userName + "\" as role \"" + selectedRole + "\"";

    } while( true );

    _logger << "Launching menu";

    this->launch(selectedRole);
  }

}
