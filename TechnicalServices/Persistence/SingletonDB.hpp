//====================SingletonDB.hpp=========================//

#pragma once

#include "TechnicalServices/Logging/LoggerHandler.hpp"

#include "TechnicalServices/Persistence/LoginDB.hpp"



namespace TechnicalServices::Persistence
{
  class SingletonDB : public LoginDB
  {
    public:
      SingletonDB            ( const SingletonDB & ) = delete;
      SingletonDB & operator=( const SingletonDB & ) = delete;
      static SingletonDB & instance();

      ~SingletonDB() noexcept override;

    private:
      using LoginDB::LoginDB;        
      SingletonDB();

      std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

      TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;

  };    // class SingletonDB
}  // namespace TechnicalServices::Persistence
