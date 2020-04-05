/// File: Include\Nexus\Application.hpp.
///
/// Summary:  Declares the application class.

#ifndef __NEXUS_APPLICATION_HPP__
#define __NEXUS_APPLICATION_HPP__

#include <Nexus\Keyboard.hpp>
#include <Nexus\Mouse.hpp>

namespace Nexus
{
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

  /// Summary:  The keyboard.
  Keyboard mKeyboard;

  /// Summary:  The mouse.
  Mouse mMouse;

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
  virtual void OnTick(const float& deltaTime) = 0;

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
  virtual void OnRender(const float& alpha) = 0;

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
};
}

#endif

// End of Include\Nexus\Application.hpp