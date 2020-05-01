//========================== Session.cpp =====================================//

#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Spaceport/PlayerSession.hpp"
#include "Domain/Spaceport/AdminSession.hpp"
#include "Domain/Spaceport/Session.hpp"


namespace Domain::Spaceport
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<SessionHandler>  SessionHandler::createSession( const std::string & role )
  {

    if     ( role == "Player"      )    return std::make_unique<Domain::Spaceport::PlayerSession>();
    else if( role == "Admin"     )    return std::make_unique<Domain::Spaceport::AdminSession>();
    else
    {
      throw std::logic_error( "Invalid role requested in function " + std::string(__func__) ); // Oops, should never get here but ...  Throw something
    }
  }

} // namespace Domain::Spaceport