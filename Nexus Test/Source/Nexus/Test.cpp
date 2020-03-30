/// File: Source\Nexus\Test.cpp.
///
/// Summary:  Implements the test class.

#include <Nexus/Application.hpp>

namespace Nexus {

/// Class:  Test
///
/// Summary:  A test program for the Nexus game engine.
///
/// Author: jkstpierre
///
/// Date: 3/29/2020
///
/// See:
/// Application -
class Test : public Application {
public:
  /// Function: Test::Test
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Parameters:
  /// windowName -        Name of the window.
  /// windowWidth -       Width of the window.
  /// windowHeight -      Height of the window.
  /// windowFullscreen -  True to window fullscreen.
  /// windowUseVSync -    True to window use v synchronize.
  Test(const char *windowName, const unsigned int &windowWidth,
       const unsigned int &windowHeight, const bool &windowFullscreen,
       const bool &windowUseVSync)
      : Application(windowName, windowWidth, windowHeight, windowFullscreen,
                    windowUseVSync) {}

  /// Function: Test::~Test
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ~Test() {}

public:
  /// Function: OnTick
  ///
  /// Summary:  Executes the tick action.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Parameters:
  /// deltaTime -   The delta time.
  void OnTick(const float &deltaTime) override {}

  /// Function: OnRender
  ///
  /// Summary:  Executes the render action.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ///
  /// Parameters:
  /// alpha -   The alpha.
  void OnRender(const float &alpha) override {}
};
} // namespace Nexus

/// Function: main
///
/// Summary:  Main entry-point for this application.
///
/// Author: jkstpierre
///
/// Date: 3/29/2020
///
/// Returns:  Exit-code for the process - 0 for success, else an error code.
int main() { return Nexus::Test("Test", 800, 600, false, true).Run(); }

// End of Source\Nexus\Test.cpp
