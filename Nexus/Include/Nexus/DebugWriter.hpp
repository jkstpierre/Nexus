/// File: Include\Nexus\DebugWriter.hpp.
///
/// Summary:  Declares the debug writer class.

#ifndef __NEXUS_DEBUGWRITER_HPP__
#define __NEXUS_DEBUGWRITER_HPP__

namespace Nexus
{
/// Summary:  Size of the debug writer message buffer.
const unsigned int DEBUGWRITER_MESSAGE_BUFFER_SIZE = 1024U;

/// Class:  DebugWriter
///
/// Summary:  Writes output to the debug console.
///
/// Author: jkstpierre
///
/// Date: 3/30/2020
class DebugWriter
{
private:
#ifdef _DEBUG
  /// Summary:  The message[ debug writer message buffer size].
  char mMessage[DEBUGWRITER_MESSAGE_BUFFER_SIZE];
#endif

public:
  /// Function: DebugWriter::DebugWriter
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/30/2020
  DebugWriter() noexcept;

  /// Function: DebugWriter::~DebugWriter
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/30/2020
  virtual ~DebugWriter() noexcept = default;

public:
  /// Function: Write
  ///
  /// Summary:  Writes a formatted string to the console.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/30/2020
  ///
  /// Parameters:
  /// format -    Describes the format to use.
  /// ... -       Variable arguments providing additional information.
  void Write(const char* format, ...) noexcept;
};
}

#endif

// End of Include\Nexus\DebugWriter.hpp
