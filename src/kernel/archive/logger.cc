#include "logger.h"


namespace susi {
namespace kernel {

  std::ostream *Logger::ostrm;
  bool Logger::debugEnabled = false;

  void Logger::setStream(
      std::ostream *stream
  )
  {
    Logger::ostrm = stream;
  }


  void Logger::info(
      std::string msg
  )
  {
    Logger::raw("info", DEFAULT_LOGGER_SOURCE, msg);
  }


  void Logger::info(
      std::string src,
      std::string msg
  )
  {
    Logger::raw("info", src, msg);
  }


  void Logger::debug(
      std::string msg
  )
  {
    if (Logger::debugEnabled){
      Logger::raw("DEBUG", DEFAULT_LOGGER_SOURCE, msg);
    }
  }


  void Logger::debug(
      std::string src,
      std::string msg
  )
  {
    if (Logger::debugEnabled){
      Logger::raw("DEBUG", src, msg);
    }
  }


  void Logger::warn(
      std::string msg
  )
  {
    Logger::raw("WARN", DEFAULT_LOGGER_SOURCE, msg);
  }

  void Logger::warn(
      std::string src,
      std::string msg
  )
  {
    Logger::raw("WARN", src, msg);
  }


  void Logger::error(
      std::string msg
  )
  {
    Logger::raw("ERROR", DEFAULT_LOGGER_SOURCE, msg);
  }


  void Logger::error(
      std::string src,
      std::string msg
  )
  {
    Logger::raw("ERROR", src, msg);
  }


  void Logger::raw(
      std::string level,
      std::string src,
      std::string msg
  )
  {
    *Logger::ostrm << level << "#" << src << ": " << msg << "\n";
  }

} // namespace kernel
} // namespace susi
