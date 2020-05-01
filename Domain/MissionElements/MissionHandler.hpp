//====================================== MissionHandler.hpp =============================//

#pragma once

namespace Domain::MissionElements
{
  
  class MissionHandler
  {
    public:
      // Constructors
      MissionHandler()                                          = default;        // default ctor
      MissionHandler( const MissionHandler &  original )  = default;        // copy ctor
      MissionHandler(       MissionHandler && original )  = default;        // move ctor

      // Operations
      virtual void startMission() = 0;
      virtual void endMission() = 0;
      virtual void requestThrusterChange(int c) = 0;

      virtual bool missionStatus() = 0;
      virtual int processTurn() = 0;
      virtual std::string getTurnStatement() = 0;

      static std::unique_ptr<MissionHandler> createMission();

      // Destructor
      virtual ~MissionHandler() noexcept = 0;

    protected:
      MissionHandler & operator=( const MissionHandler &  rhs ) = default;  // copy assignment
      MissionHandler & operator=(       MissionHandler && rhs ) = default;  // move assignment

  };    // class MissionHandler




  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline MissionHandler::~MissionHandler() noexcept
  {}


} // namespace Domain::MissionElements