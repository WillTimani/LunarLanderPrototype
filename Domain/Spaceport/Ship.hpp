#pragma once

namespace Domain::Spaceport
{
  // Library Package within the Domain Layer Abstract class
  class Ship
  {
    public:
      // Constructors
      Ship()                                          = default;        // default ctor
      Ship( const Ship &  original )  = default;        // copy ctor
      Ship(       Ship && original )  = default;        // move ctor

      // Operations

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~Ship() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      Ship & operator=( const Ship &  rhs ) = default;  // copy assignment
      Ship & operator=(       Ship && rhs ) = default;  // move assignment

  };    // class Ship





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Ship::~Ship() noexcept
  {}


} // namespace Domain::Spaceport