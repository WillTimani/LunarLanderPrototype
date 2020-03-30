//=========================================== SpaceShop.hpp ==============================//

#include <string>
#include <vector>
#include <memory>    // std::unique_ptr

#include "Domain/Spaceport/Shop.hpp"
#include "TechnicalServices/Persistence/ShopDB.hpp"
#include "TechnicalServices/Logging/LoggerHandler.hpp"


#pragma once

namespace Domain::Spaceport
{

	class SpaceShop : public Domain::Spaceport::Shop
	{

		public:
			//Constructors
			using Shop::Shop;
			SpaceShop();

			//Operations
			bool contactTransactionService() override;
			bool purchaseItem(unsigned select) override;
			std::vector<std::string> getOptions();

			//Destructor
			~SpaceShop() noexcept override;

		private:
			//variables
			std::vector<TechnicalServices::Persistence::shopObject> options; 

			std::unique_ptr<TechnicalServices::Persistence::ShopDB>  _database;

			std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;
      		TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;



	};

	inline SpaceShop::~SpaceShop() noexcept
	{}



}