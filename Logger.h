/**************************************************************************/
/*!
  @file Logger.h

  This library do an abstraction to help to log msgs with or without context
  to an specific Serial, and show msgs by log level of importance.

  Written by JPolanco.
*/
/**************************************************************************/
#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

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

// Defines the log port where the logger is going to print
// the log data
void log_port(HardwareSerial &serial);

// Begins the log port with specific baudrate
void log_begin(uint32_t baudrate);

// Begins the log with the hardware serial and baudrate
void log_begin(HardwareSerial &serial, uint32_t baudrate);

// Begins the log with the hardware serial and baudrate and log level
void log_begin(HardwareSerial &serial, uint32_t baudrate, eLogLevel_t level);

// Sets the log level
// By default is Warn
void log_level(eLogLevel_t level);

// Prints without context an message without new line
void log(String msg);
// Prints without context an message with log level
void log(String msg, eLogLevel_t level);

// Prints without context an message with new line
void logln(String msg);
// Prints without context an message with new line and log level
void logln(String msg, eLogLevel_t level);

// Prints an debug message
// Example:
// log_d("Hello there is an debug msg");
// Output:
// [DEBUG]: Hello there is an debug msg
void log_d(String msg);

// Prints an info message
// Example:
// log_i("Hello there is an info msg");
// Output:
// [INFO ]: Hello there is an info msg
void log_i(String msg);

// Prints an info message
// Example:
// log_w("Hello there is an warn msg");
// Output:
// [WARN ]: Hello there is an warn msg
void log_w(String msg);

// Prints an info message
// Example:
// log_e("Hello there is an error msg");
// Output:
// [ERROR]: Hello there is an error msg
void log_e(String msg);

#endif // !LOGGER_H