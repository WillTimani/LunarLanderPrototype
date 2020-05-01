//========================== Shop.hpp =====================================//

#include <vector>

#pragma once


namespace Domain::Spaceport
{
  // Shop Abstract class
  class ShopHandler
  {
    public:
      // Constructors
      ShopHandler()                                                = default;    // default ctor
      ShopHandler( const ShopHandler &  original )        = default;    // copy ctor
      ShopHandler(       ShopHandler && original )        = default;    // move ctor

      // Operations
      virtual bool contactTransactionService() = 0;
      virtual bool purchaseItem(unsigned selection) = 0;
      virtual std::vector<std::string> getOptions() = 0;


      // Object Factory returning a SpaceShop object
      static std::unique_ptr<ShopHandler> createSpaceShop();

      // Abstract class destructor
      virtual ~ShopHandler() noexcept = 0;                                        

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      ShopHandler & operator=( const ShopHandler  & rhs ) = default;     // copy assignment
      ShopHandler & operator=(       ShopHandler && rhs ) = default;     // move assignment
  };


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline ShopHandler::~ShopHandler() noexcept
  {}
} // namespace UI