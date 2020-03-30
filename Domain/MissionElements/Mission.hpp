//===================================== Mission.hpp ================================//

#pragma once 

#include <memory>    // std::unique_ptr
#include <string>

#include "Domain/MissionElements/MissionHandler.hpp"
#include "Domain/Spaceport/Lander.hpp"
#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::MissionElements
{
	class Mission : public Domain::MissionElements::MissionHandler 
	 {
	    public:
	      // Constructors
	      Mission();

	      // Operations
	      void startMission();
	      void endMission();
	      bool missionStatus();
	      int processTurn();
	      void requestThrusterChange(int c);
	      std::string getTurnStatement();

	     ~Mission() noexcept override;

	    private:
	    	// variables

	    	int terrainLevel; 
	    	bool inMission;

	    	std::unique_ptr<Domain::Spaceport::Lander> _instanceLander;


	  }; // class Mission


	  /*****************************************************************************
	  ** Inline implementations
	  ******************************************************************************/
	  inline Mission::~Mission() noexcept
	  {}


}  // namespace Domain::Spaceport