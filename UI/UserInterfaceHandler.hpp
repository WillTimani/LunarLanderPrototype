// UserInterfaceHandler.hpp

#pragma once


namespace UI
{
  // User Interface Layer Abstract class
  class UserInterfaceHandler
  {
    public:
      // Constructors
      UserInterfaceHandler()                                                = default;    // default ctor
      UserInterfaceHandler( const UserInterfaceHandler &  original )        = default;    // copy ctor
      UserInterfaceHandler(       UserInterfaceHandler && original )        = default;    // move ctor

      // Operations
      virtual void login() = 0;

      // Abstract class destructor
      virtual ~UserInterfaceHandler() noexcept = 0;                                       

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      UserInterfaceHandler & operator=( const UserInterfaceHandler  & rhs ) = default;     // copy assignment
      UserInterfaceHandler & operator=(       UserInterfaceHandler && rhs ) = default;     // move assignment
  };


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline UserInterfaceHandler::~UserInterfaceHandler() noexcept
  {}
} // namespace UI