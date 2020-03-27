#pragma once

#include <memory>  // unique_ptr
#include <string>
#include <vector>


namespace Domain::Spaceport
{
  class MenuHandler
  {
    public:
      // Constructors and assignment operations
      MenuHandler()                                           = default;  // default ctor
      MenuHandler( const MenuHandler &  original )         = default;  // copy ctor
      MenuHandler(       MenuHandler && original )         = default;  // move ctor

      // Operations
      virtual std::vector<std::string> getCommands() = 0;  // retrieves the list of actions (commands)

      // Object Factory returning a specialized object specific to the specified role
      static std::unique_ptr<MenuHandler> createSession( const std::string & role );

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~MenuHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      MenuHandler & operator=( const MenuHandler &  rhs ) = default;  // copy assignment
      MenuHandler & operator=(       MenuHandler && rhs ) = default;  // move assignment

  };    // class MenuHandler





     /*****************************************************************************
     ** Inline implementations
     ******************************************************************************/
  inline MenuHandler::~MenuHandler() noexcept
  {}

} // namespace Domain::Spaceport