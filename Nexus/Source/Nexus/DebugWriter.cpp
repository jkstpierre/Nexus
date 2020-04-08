/// File: Source\Nexus\DebugWriter.cpp.
///
/// Summary:  Implements the debug writer class.

#include <Nexus\Macros.hpp>
#ifdef __NEXUS_OS_WINDOWS__
#include <Windows.h>
#endif
#include <cstdio>
#include <Nexus\DebugWriter.hpp>

namespace Nexus
{
#ifdef _DEBUG
DebugWriter::DebugWriter() noexcept : mMessage{ NULL }
{}
#else
DebugWriter::DebugWriter() noexcept 
{}
#endif

void DebugWriter::Write(const char* format, ...) noexcept
{
#ifdef _DEBUG
  // Build string from format in buffer
  va_list args;
  va_start(args, format);
  vsnprintf_s(mMessage, DEBUG_WRITER_MESSAGE_BUFFER_SIZE, format, args);
  va_end(args);

#ifdef __NEXUS_OS_WINDOWS__
  OutputDebugStringA(mMessage);  // Output to Windows debug console
#elif
  printf(mMessage);  // Output to other consoles
#endif
#endif
}
}

// End of Source\Nexus\DebugWriter.cpp
