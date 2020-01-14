/**************************************************************************/
/*!
  @file Logger.h

  This library implements logging for HardwareSerial port, implements ILogger
  interface also declared in this library.

  Written by JPolanco.
*/
/**************************************************************************/
#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <HardwareSerial.h>

// [Class] Implements functionality to log into an HardwareSerial data with log levels
// [Implements ILogger]
class Logger : public ILogger
{
private:
// [Constructor] Private constructor
  Logger();
// [Reference] Port where is logging
  HardwareSerial *port;
// [Static Attribute] Global log level
  static eLogLevel_t log_lvl;
  
public:
// [Static Method] Gets an reference to the singleton instance of Logger
  static Logger &getInstance();

// [Override Method] Implements buffer writing into port
  size_t write(const uint8_t *buffer, size_t size) override;
// [Override Method] Implements data writting into port
  size_t write(uint8_t _byte) override;

// [Public Method] Begins serial communication
  void begin(uint32_t) override;
// [Public Method] Ends serial communication
  void end() override;
// [Public Method] Sets the Hardware serial port where is logging 
  void setPort(HardwareSerial &);
// [Public Getter] Gets the log level 
  eLogLevel_t logLevel() const override;
// [Public Setter] Sets the log level
  void setLogLevel(const eLogLevel_t &) override;
// [Public Method] Flush implementation
  void flush() override;
// [Destructor]
  ~Logger() {}
};

#endif // !LOGGER_H