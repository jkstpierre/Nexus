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

void Mouse::SetPosition(const glm::u32vec2& position) noexcept
{
  mPosition = position;
}

const glm::u32vec2& Mouse::GetPosition() const noexcept
{
  return mPosition;
}
}

// End of Source\Nexus\Mouse.cpp
