#include "ILogger.h"

// Local macro for prefix debug msg
#define LOG_DEBUG_PREFIX_MSG "[DEBUG]: "
// Local macro for prefix info msg
#define LOG_INFO_PREFIX_MSG "[INFO ]: "
// Local macro for prefix warn msg
#define LOG_WARN_PREFIX_MSG "[WARN ]: "
// Local macro for prefix error msg
#define LOG_ERROR_PREFIX_MSG "[ERROR]: "

String GetStringLogLevel(eLogLevel_t log_lv) {
  switch (log_lv)
  {
  case LOG_DEBUG: return LOG_DEBUG_PREFIX_MSG;
  case LOG_INFO: return LOG_INFO_PREFIX_MSG;
  case LOG_WARN: return LOG_WARN_PREFIX_MSG;
  case LOG_ERROR: return LOG_ERROR_PREFIX_MSG;
  default: return "[     ]: ";
  }
}

template <typename T>
size_t ILogger::log_write(T msg, eLogLevel_t logLvl)
{
  if (logLvl >= this->logLevel())
  {
    size_t r = this->print(GetStringLogLevel(logLvl));
    r += this->println(msg);
    return r;
  }
  return 0;
}

template <typename T>
size_t ILogger::log_write(T msg, eLogLevel_t logLvl, int base)
{
  if (logLvl >= this->logLevel())
  {
    size_t r = this->print(GetStringLogLevel(logLvl));
    r += this->println(msg);
    return r;
  }
  return 0;
}

size_t ILogger::log(const __FlashStringHelper *msg, eLogLevel_t logLvl)
{
  return this->log_write(msg, logLvl);
}

size_t ILogger::log(const String &msg, eLogLevel_t logLvl)
{
  return this->log_write(msg, logLvl);
}

size_t ILogger::log(const char msg[], eLogLevel_t logLvl)
{
  return this->log_write(msg, logLvl);
}

size_t ILogger::log(char msg, eLogLevel_t logLvl)
{
  return this->log_write(msg, logLvl);
}

size_t ILogger::log(unsigned char msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(int msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(unsigned int msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(long msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(unsigned long msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(double msg, eLogLevel_t logLvl, int base)
{
  
  return this->log_write(msg, logLvl, base);
}

size_t ILogger::log(const Printable &msg, eLogLevel_t logLvl)
{
  return this->log_write<const Printable &>(msg, logLvl);
}
