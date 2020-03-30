/// File: Include\Nexus\Exception.hpp.
///
/// Summary:  Declares the exception class.

#ifndef __NEXUS_EXCEPTION_HPP__
#define __NEXUS_EXCEPTION_HPP__

#include <exception>
#include <string>

namespace Nexus
{
/// Summary:  Size of the exception message buffer.
const unsigned int EXCEPTION_MESSAGE_BUFFER_SIZE = 1024U;

/// Class:  Exception
///
/// Summary:  An exception is thrown when something bad happens.
///
/// Author: jkstpierre
///
/// Date: 3/29/2020
class Exception : std::exception
{
private:
  /// Summary:  The error message to display.
  char mMessage[EXCEPTION_MESSAGE_BUFFER_SIZE];

public:
  /// Function: Exception::Exception
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 3/29/2020.
  ///
  /// Parameters:
  /// format -    The message format for the exception.
  /// ... -       Variable arguments providing additional information.
  Exception(const char* format, ...) noexcept;

  /// Function: Exception::~Exception
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  virtual ~Exception() = default;

public:
  /// Function: ReadMessage
  ///
  /// Summary:  Reads the message.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Returns:  Null if it fails, else the message.
  const char* ReadMessage() const noexcept;
};
}

#endif

// End of Include\Nexus\Exception.hpp
