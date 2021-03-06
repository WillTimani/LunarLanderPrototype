//============================SingletonDB.cpp==========================//

#include "TechnicalServices/Logging/Logger.hpp"
#include "TechnicalServices/Persistence/SingletonDB.hpp"


namespace TechnicalServices::Persistence
{
  SingletonDB & SingletonDB::instance()
  {
    static SingletonDB theInstance;
    return theInstance;
  }



  SingletonDB::SingletonDB()
  : _loggerPtr( std::make_unique<TechnicalServices::Logging::Logger>() )     
  {
    _logger << "Singleton DB being used and has been successfully initialized";
  }



  SingletonDB::~SingletonDB() noexcept
  {
    _logger << "Singleton DB shutdown successfully";
  }




} // namespace TechnicalServices::Persistence
