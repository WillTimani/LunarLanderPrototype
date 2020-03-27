// Shop.hpp

#pragma once


namespace Domain::Spaceport
{
  // Shop Abstract class
  class Shop
  {
    public:
      // Constructors
      Shop()                                                = default;    // default ctor
      Shop( const Shop &  original )        = default;    // copy ctor
      Shop(       Shop && original )        = default;    // move ctor

      // Operations
      virtual bool contactTransactionService() = 0;
      virtual bool purchaseItem(unsigned selection) = 0;

      // Abstract class destructor
      virtual ~Shop() noexcept = 0;                                        // must be virtual and pure

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      Shop & operator=( const Shop  & rhs ) = default;     // copy assignment
      Shop & operator=(       Shop && rhs ) = default;     // move assignment
  };


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Shop::~Shop() noexcept
  {}
} // namespace UI