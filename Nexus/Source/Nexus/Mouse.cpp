/// File: Source\Nexus\Mouse.cpp.
///
/// Summary:  Implements the mouse class.

#include <Nexus\Mouse.hpp>

namespace Nexus
{
void Mouse::Press(const MouseButton& button) noexcept
{
  mButtons[button] = true;
}

void Mouse::Release(const MouseButton& button) noexcept
{
  mButtons[button] = false;
}

const bool Mouse::IsPressed(const MouseButton& button) const noexcept
{
  if ( mButtons.find(button) != mButtons.end() )
  {
    return mButtons.at(button);
  }
  else
  {
    return false;
  }
}

void Mouse::SetPosition(const Math::Vector2i& position) noexcept
{
  mPosition = position;
}

const Math::Vector2i& Mouse::GetPosition() const noexcept
{
  return mPosition;
}
}

// End of Source\Nexus\Mouse.cpp
