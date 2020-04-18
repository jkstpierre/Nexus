/// File: Include\Nexus\Mouse.hpp.
///
/// Summary:  Declares the mouse class.

#ifndef __NEXUS_MOUSE_HPP__
#define __NEXUS_MOUSE_HPP__

#include <unordered_map>
#include <glm\glm.hpp>

namespace Nexus
{
/// Enum: MouseButton
///
/// Summary:  Values that represent mouse buttons.
enum class MouseButton : unsigned int
{
  _LEFT = 0x01,
  _MIDDLE = 0x02,
  _RIGHT = 0x03,
  _X1 = 0x04,
  _X2 = 0x05
};

/// Class:  Mouse
///
/// Summary:  A mouse.
///
/// Author: jkstpierre
///
/// Date: 4/5/2020
class Mouse
{
private:
  /// Summary:  The buttons.
  std::unordered_map<MouseButton, bool> mButtons;

  /// Summary:  The position of the mouse.
  glm::u32vec2 mPosition;

public:
  /// Function: Mouse::Mouse
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  Mouse() = default;

  /// Function: Mouse::~Mouse
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ~Mouse() noexcept = default;

public:
  /// Function: Press
  ///
  /// Summary:  Press the given button.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// button -  The button.
  void Press(const MouseButton& button) noexcept;

  /// Function: Release
  ///
  /// Summary:  Releases the given button.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// button -  The button.
  void Release(const MouseButton& button) noexcept;

  /// Function: IsPressed
  ///
  /// Summary:  Is pressed.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// button -  The button.
  ///
  /// Returns:  A reference to a const bool.
  const bool IsPressed(const MouseButton& button) const noexcept;

public:
  /// Function: SetPosition
  ///
  /// Summary:  Sets a position.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// position -  The position.
  void SetPosition(const glm::u32vec2& position) noexcept;

  /// Function: GetPosition
  ///
  /// Summary:  Gets the position.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The position.
  const glm::u32vec2& GetPosition() const noexcept;
};
}

#endif

// End of Include\Nexus\Mouse.hpp
