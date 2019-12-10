#include "Logger.h"

// Local macro for prefix debug msg
#define LOG_DEBUG_PREFIX_MSG "[DEBUG]: "
// Local macro for prefix info msg
#define LOG_INFO_PREFIX_MSG "[INFO ]: "
// Local macro for prefix warn msg
#define LOG_WARN_PREFIX_MSG "[WARN ]: "
// Local macro for prefix error msg
#define LOG_ERROR_PREFIX_MSG "[ERROR]: "

namespace
{
// Local HardwareSerial port where is logging
HardwareSerial *log_serial;
// Global Log level for any logging
eLogLevel_t logLvl = LOG_WARN;

// Local auxiliar function to print msg to log port
void internal_log(String msg, eLogLevel_t log_lv, bool printLn = false)
{
  if (log_lv >= logLvl)
  {
    printLn ? log_serial->println(msg) : log_serial->print(msg);
  }
}
}; // namespace

void log_port(HardwareSerial &serial)
{
  log_serial = &serial;
}

void log_begin(uint32_t baudrate)
{
  log_serial->begin(baudrate);
}

void log_begin(HardwareSerial &serial, uint32_t baudrate)
{
  log_begin(serial, baudrate, logLvl);
}

void log_begin(HardwareSerial &serial, uint32_t baudrate, eLogLevel_t level)
{
  log_port(serial);
  log_begin(baudrate);
  log_level(level);
}

void log_level(eLogLevel_t level)
{
  logLvl = level;
}

void log(String msg)
{
  internal_log(msg, LOG_MASTER);
}

void log(String msg, eLogLevel_t level)
{
  internal_log(msg, level);
}

void logln(String msg)
{
  internal_log(msg, LOG_MASTER, true);
}

void logln(String msg, eLogLevel_t level)
{
  internal_log(msg, level, true);
}

void log_d(String msg)
{
  logln(LOG_DEBUG_PREFIX_MSG + msg, LOG_DEBUG);
}

void log_i(String msg)
{
  logln(LOG_INFO_PREFIX_MSG + msg, LOG_INFO);
}

void log_w(String msg)
{
  logln(LOG_WARN_PREFIX_MSG + msg, LOG_WARN);
}

void log_e(String msg)
{
  logln(LOG_ERROR_PREFIX_MSG + msg, LOG_ERROR);
}