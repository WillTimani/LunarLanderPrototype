//=========================================== SpaceShop.hpp ==============================//

#include <string>
#include <vector>
#include <memory>    // std::unique_ptr

#include "Domain/Spaceport/ShopHandler.hpp"
#include "TechnicalServices/Persistence/ShopDB.hpp"
#include "TechnicalServices/Logging/LoggerHandler.hpp"


#pragma once

namespace Domain::Spaceport
{

	class SpaceShop : public Domain::Spaceport::ShopHandler
	{

		public:
			//Constructors
			using ShopHandler::ShopHandler;
			SpaceShop();

			//Operations
			bool contactTransactionService() override;
			bool purchaseItem(unsigned select) override;
			std::vector<std::string> getOptions() override;

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