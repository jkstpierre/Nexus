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
DebugWriter::DebugWriter() noexcept : mMessage{ NULL }
{}

void DebugWriter::Write(const wchar_t* format, ...) noexcept
{
  // Build string from format in buffer
  va_list args;
  va_start(args, format);
  vswprintf_s(mMessage, sizeof(mMessage), format, args);
  va_end(args);

#ifdef __NEXUS_OS_WINDOWS__
  OutputDebugString(mMessage);  // Output to Windows debug console
#elif
  wprintf(mMessage);  // Output to other consoles
#endif
}
}

// End of Source\Nexus\DebugWriter.cpp
