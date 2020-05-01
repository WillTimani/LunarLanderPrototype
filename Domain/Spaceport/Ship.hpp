//====================================== Ship.hpp =============================//

#pragma once

namespace Domain::Spaceport
{
  
  class Ship
  {
    public:
      // Constructors
      Ship()                                          = default;        // default ctor
      Ship( const Ship &  original )  = default;        // copy ctor
      Ship(       Ship && original )  = default;        // move ctor

      // Operations
      virtual void activateThrusters() = 0;
      virtual void deactivateThrusters() = 0; 

      // Object Factory returning a Lander Object
      static Ship * createLander();

      // Destructor
      virtual ~Ship() noexcept = 0;

    protected:
      Ship & operator=( const Ship &  rhs ) = default;  // copy assignment
      Ship & operator=(       Ship && rhs ) = default;  // move assignment

  };    // class Ship




  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Ship::~Ship() noexcept
  {}

} // namespace Domain::Spaceport