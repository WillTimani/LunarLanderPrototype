#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Spaceport/PlayerMenu.hpp"
#include "Domain/Spaceport/AdminMenu.hpp"
#include "Domain/Spaceport/Menu.hpp"


namespace Domain::Spaceport
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<MenuHandler>  MenuHandler::createSession( const std::string & role )
  {

    if     ( role == "Player"      )    return std::make_unique<Domain::Spaceport::PlayerMenu>();
    else if( role == "Admin"     )    return std::make_unique<Domain::Spaceport::AdminMenu>();
    else
    {
      throw std::logic_error( "Invalid role requested in function " + std::string(__func__) ); // Oops, should never get here but ...  Throw something
    }
  }

} // namespace Domain::Spaceport