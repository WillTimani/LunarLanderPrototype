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

	      // Destructor
	      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
	      virtual ~MissionHandler() noexcept = 0;

	    protected:
	      // Copy assignment operators, protected to prevent mix derived-type assignments
	      MissionHandler & operator=( const MissionHandler &  rhs ) = default;  // copy assignment
	      MissionHandler & operator=(       MissionHandler && rhs ) = default;  // move assignment

  };    // class MissionHandler



  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline MissionHandler::~MissionHandler() noexcept
  {}


} // namespace Domain::Spaceport