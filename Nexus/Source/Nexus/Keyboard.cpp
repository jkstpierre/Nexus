/// File: Source\Nexus\Keyboard.cpp.
///
/// Summary:  Implements the keyboard class.

#include <Nexus\Keyboard.hpp>

namespace Nexus
{
void Keyboard::Press(const Key& key) noexcept
{
  mKeys[key] = true;
}

void Keyboard::Release(const Key& key) noexcept
{
  mKeys[key] = false;
}

const bool Keyboard::IsPressed(const Key& key) const noexcept
{
  if ( mKeys.find(key) != mKeys.end() )
  {
    return mKeys.at(key);
  }
  else
  {
    return false;
  }
}
}

// End of Source\Nexus\Keyboard.cpp
