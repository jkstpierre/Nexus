/// File: Source\Nexus\Exception.cpp.
///
/// Summary:  Implements the exception class.

#include <Nexus\Exception.hpp>
#include <cstdarg>

namespace Nexus
{
Exception::Exception(const char* format, ...) noexcept : mMessage{ NULL }
{
  va_list args;
  va_start(args, format);
  vsnprintf_s(mMessage, sizeof(wchar_t) * EXCEPTION_MESSAGE_BUFFER_SIZE, format,
              args);
  va_end(args);
}

const char* Exception::ReadMessage() const noexcept
{
  return mMessage;
}
}

// End of Source\Nexus\Exception.cpp
