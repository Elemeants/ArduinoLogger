/**************************************************************************/
/*!
  @file ILogger.h

  This library only provides an interface for logging
  If you use this to do your own logger, should implement write functions
  from Print arduino class

  Written by JPolanco.
*/
/**************************************************************************/
#ifndef INTEFACE_LOGGER_H
#define INTEFACE_LOGGER_H

#include <HardwareSerial.h>
#include <Print.h>

// Local macro for prefix debug msg
#define LOG_DEBUG_PREFIX_MSG "[DEBUG]: "
// Local macro for prefix info msg
#define LOG_INFO_PREFIX_MSG "[INFO ]: "
// Local macro for prefix warn msg
#define LOG_WARN_PREFIX_MSG "[WARN ]: "
// Local macro for prefix error msg
#define LOG_ERROR_PREFIX_MSG "[ERROR]: "

typedef enum
{
  // Log at debug level
  LOG_DEBUG,
  // Log at info level
  LOG_INFO,
  // Log at warning level
  LOG_WARN,
  // Log at error level
  LOG_ERROR,
  // Log at any level
  LOG_MASTER
} eLogLevel_t;

// [Method] Gets the string log representation by log level
const __FlashStringHelper *GetStringLogLevel(eLogLevel_t log_lv);

// [Interface] Provides an interface to use a logger with log levels
struct ILogger : public Print
{
private:
  const char *prefix;
  // [Private Method] Generic internal log for public log methods
  template <typename T>
  size_t log_write(T msg, eLogLevel_t logLvl);
  // [Private Method] Generic internal log for public log methods
  template <typename T>
  size_t log_write(T msg, eLogLevel_t logLvl, int);

protected:
  void printPrefix()
  {
    if (prefix)
    {
      this->print(F("[ "));
      this->print(prefix);
      this->print(F(" ]"));
    }
  }

public:
  virtual void setPrefix(const char *_prefix)
  {
    prefix = _prefix;
  }

  // [Virtual Method] Starts the log port output
  virtual void begin(uint32_t) = 0;
  // [Virtual Method] Ends the log port output
  virtual void end() = 0;

  // [Virtual Getter] Gets the actual log level
  virtual eLogLevel_t logLevel() const = 0;
  // [Virtual Setter] Sets the log level
  virtual void setLogLevel(const eLogLevel_t &) = 0;

  // [Public Method] Logs an message line
  virtual size_t log(const __FlashStringHelper *, eLogLevel_t);
  // [Public Method] Logs an message line
  virtual size_t log(const String &, eLogLevel_t);
  // [Public Method] Logs an message line
  virtual size_t log(const char[], eLogLevel_t);
  // [Public Method] Logs an message line
  virtual size_t log(char, eLogLevel_t);
  // [Public Method] Logs an message line
  virtual size_t log(unsigned char, eLogLevel_t, int = DEC);
  // [Public Method] Logs an message line
  virtual size_t log(int, eLogLevel_t, int = DEC);
  // [Public Method] Logs an message line
  virtual size_t log(unsigned int, eLogLevel_t, int = DEC);
  // [Public Method] Logs an message line
  virtual size_t log(long, eLogLevel_t, int = DEC);
  // [Public Method] Logs an message line
  virtual size_t log(unsigned long, eLogLevel_t, int = DEC);
  // [Public Method] Logs an message line
  virtual size_t log(double, eLogLevel_t, int = 2);
  // [Public Method] Logs an message line
  virtual size_t log(const Printable &, eLogLevel_t);
};

#endif // !INTEFACE_LOGGER_H