#include "Logger.h"

eLogLevel_t Logger::log_lvl = LOG_INFO;

Logger::Logger()
    : port(NULL) {}

Logger &Logger::getInstance()
{
  static Logger *instance;
  if (instance == NULL)
  {
    instance = new Logger();
  }
  return *instance;
}

size_t Logger::write(const uint8_t *buffer, size_t size)
{
  if (port == NULL)
  {
    return 0;
  }
  return port->write(buffer, size);
}

size_t Logger::write(uint8_t _byte)
{
  if (port == NULL)
  {
    return 0;
  }
  return port->write(_byte);
}

void Logger::begin(uint32_t baudrate)
{
  if (port == NULL)
  {
    return;
  }
  port->begin(baudrate);
}

void Logger::end()
{
  if (port == NULL)
  {
    return;
  }
  port->end();
}

void Logger::setPort(HardwareSerial &_port)
{
  if (port != NULL)
  {
    port->end();
  }
  port = &_port;
}

eLogLevel_t Logger::logLevel() const
{
  return Logger::log_lvl;
}

void Logger::setLogLevel(const eLogLevel_t &_lvl)
{
  Logger::log_lvl = _lvl;
}