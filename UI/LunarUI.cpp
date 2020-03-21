//LunarUI.cpp

#include <iomanip>                                                                    // setw()
#include <iostream>                                                                   // streamsize
#include <limits>                                                                     // numeric_limits
#include <memory>                                                                     // unique_ptr, make_unique<>()
#include <string>                                                                     // string, getline()
#include <vector>

#include "Domain/AccountManagement/UserAccounts.hpp"                                  // Include for now - will replace next increment

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
  void LunarUI::launch()
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
   }

}
