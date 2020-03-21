//============================Logger.cpp==================================//

#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

#include "TechnicalServices/Logging/LoggerHandler.hpp"


namespace TechnicalServices::Logging
{
  class Logger : public TechnicalServices::Logging::LoggerHandler
  {
    public:
      //Constructors
      using LoggerHandler::LoggerHandler;                       // inherent constructors
      Logger( std::ostream & loggingStream = std::clog);  // default ctor

      // Operations
      Logger & operator<< ( const std::string & message ) override;

      // Destructor
      ~Logger() noexcept override;
  }; // class SimpleLogger






  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Logger::Logger( std::ostream & loggingStream )
  : LoggerHandler(loggingStream)
  {
    // Let's set the buffering behavior of the stream so the order and context of inserted information is preserved. Force the
    // buffer to be flushed after each insertion. One normally doesn't want to do this, but log files are very often viewed in real
    // time as the program executes (e.g. tailing a file).  Waiting for the buffer to fill before seeing the contents may give false
    // information in such cases.
    loggingStream << std::unitbuf;

    *this << "Simple Logger being used and has been successfully initialized";
  }


  inline Logger::~Logger() noexcept
  {
    *this << "Simple Logger shutdown successfully";
  }



  inline Logger & Logger::operator<< ( const std::string & message )
  {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    #pragma warning(suppress : 4996)  // acknowledge and accept that std::localtime is not thread safe (Turn off MSVC++ warning)
    _loggingStream << std::put_time( std::localtime( &now ), "%Y-%m-%d %X" ) << " | ";

    _loggingStream << message << '\n';

    return *this;
  }

} // namespace TechnicalServices::Logging
