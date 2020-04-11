/// File: Include\Nexus\Application.hpp.
///
/// Summary:  Declares the application class.

#ifndef __NEXUS_APPLICATION_HPP__
#define __NEXUS_APPLICATION_HPP__

#include <Nexus\Keyboard.hpp>
#include <Nexus\Mouse.hpp>
#include <Nexus\Graphics\GLDevice.hpp>
#include <Nexus\Math\Vector2.hpp>

namespace Nexus
{
/// Summary:  The application default ticks per second.
const unsigned int APPLICATION_DEFAULT_TICKS_PER_SECOND = 50U;
/// Summary:  The application default gl major version.
const unsigned int APPLICATION_DEFAULT_GL_MAJOR_VERSION = 4U;
/// Summary:  The application default gl minor version.
const unsigned int APPLICATION_DEFAULT_GL_MINOR_VERSION = 6U;

/// Class:  Application
///
/// Summary:  An abstract base class for programs wishing to run on Nexus.
///
/// Author: jkstpierre
///
/// Date: 3/29/2020
class Application
{
private:
  /// Summary:  The window.
  void* mWindow;

  /// Summary:  The OpenGL context.
  void* mContext;

  /// Summary:  True if game loop is running.
  bool mRunning;

  /// Summary:  The ticks per second.
  unsigned int mTicksPerSecond;

  /// Summary:  The keyboard.
  Keyboard mKeyboard;

  /// Summary:  The mouse.
  Mouse mMouse;

  /// Summary:  The gl device.
  Graphics::GLDevice mGLDevice;

public:
  /// Function: Application::Application
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 3/29/2020.
  ///
  /// Parameters:
  /// windowName -        Name of the window.
  /// windowWidth -       Width of the window.
  /// windowHeight -      Height of the window.
  /// windowFullscreen -  True to window fullscreen mode.
  /// windowUseVSync -    True to window v synchronize.
  Application(const char* windowName, const unsigned int& windowWidth,
              const unsigned int& windowHeight, const bool& windowFullscreen,
              const bool& windowUseVSync);

  /// Function: Application::~Application
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  virtual ~Application();

public:
  /// Function: Run
  ///
  /// Summary:  Start the program loop.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Returns:  An int.
  int Run();

  /// Function: Stop
  ///
  /// Summary:  Stops the game loop.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  void Stop() noexcept;

  /// Function: OnTick
  ///
  /// Summary:
  ///   Called upon every clock tick for the Application. All application logic
  ///   should exist inside this method.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 3/29/2020.
  ///
  /// Parameters:
  /// deltaTime -   The delta time between ticks.
  virtual void OnTick(const double& deltaTime) = 0;

  /// Function: OnRender
  ///
  /// Summary:
  ///   Called upon every frame for the Application. All rendering logic should
  ///   exist inside this method.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 3/29/2020.
  ///
  /// Parameters:
  /// alpha -   The alpha value used for interpolation.
  virtual void OnRender(const double& alpha) = 0;

public:
  /// Function: SetTicksPerSecond
  ///
  /// Summary:  Sets ticks per second. Will do nothing if ticksPerSecond is 0.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Parameters:
  /// ticksPerSecond -  The ticks per second.
  void SetTicksPerSecond(const unsigned int& ticksPerSecond) noexcept;

  /// Function: SetWindowDimensions
  ///
  /// Summary:  Sets window dimensions.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// windowDimensions -  The window dimensions.
  void SetWindowDimensions(const Math::Vector2i& windowDimensions) noexcept;

public:
  /// Function: IsRunning
  ///
  /// Summary:  Check whether the game loop is running
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Returns:  A reference to a const bool.
  const bool& IsRunning() const noexcept;

  /// Function: GetTicksPerSecond
  ///
  /// Summary:  Gets ticks per second.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The ticks per second.
  const unsigned int& GetTicksPerSecond() const noexcept;

  /// Function: GetWindowDimensions
  ///
  /// Summary:  Gets window dimensions.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The window dimensions.
  Math::Vector2i GetWindowDimensions() const noexcept;

  /// Function: GetKeyboard
  ///
  /// Summary:  Gets the keyboard.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/4/2020.
  ///
  /// Returns:  The keyboard.
  const Keyboard& GetKeyboard() const noexcept;

  /// Function: GetMouse
  ///
  /// Summary:  Gets the mouse.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The mouse.
  const Mouse& GetMouse() const noexcept;

  /// Function: GetGLDevice
  ///
  /// Summary:  Gets gl device.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The gl device.
  Graphics::GLDevice& GetGLDevice() noexcept;
};
}

#endif

// End of Include\Nexus\Application.hpp