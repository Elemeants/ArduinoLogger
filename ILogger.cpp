#include "ILogger.h"

const __FlashStringHelper *GetStringLogLevel(eLogLevel_t log_lv)
{
  switch (log_lv)
  {
  case LOG_DEBUG:
    return F(LOG_DEBUG_PREFIX_MSG);
  case LOG_INFO:
    return F(LOG_INFO_PREFIX_MSG);
  case LOG_WARN:
    return F(LOG_WARN_PREFIX_MSG);
  case LOG_ERROR:
    return F(LOG_ERROR_PREFIX_MSG);
  default:
    return F("[     ]: ");
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
