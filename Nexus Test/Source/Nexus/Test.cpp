/// File: Source\Nexus\Test.cpp.
///
/// Summary:  Implements the test class.

#include <Nexus\Macros.hpp>
#ifdef __NEXUS_OS_WINDOWS__
#include <Windows.h>
#endif
#include <Nexus\Application.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Math\Vector2.hpp>
#include <Nexus\Math\Matrix2.hpp>

namespace Nexus
{
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
class Test : public Application
{
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
  Test(const char* windowName, const unsigned int& windowWidth,
       const unsigned int& windowHeight, const bool& windowFullscreen,
       const bool& windowUseVSync)
    : Application(windowName, windowWidth,
                  windowHeight, windowFullscreen,
                  windowUseVSync)
  {}

  /// Function: Test::~Test
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/29/2020
  ~Test()
  {}

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
  void OnTick(const double& deltaTime) override
  {
    if ( GetKeyboard().IsPressed(Key::ESCAPE) )
    {
      Stop();
      
      Math::Vector2f A;
      Math::Vector2i B(95, 26);

      Math::Matrix2f C;

      const float* data = C.GetData();

      DebugWriter().Write(L"{%f %f %f %f}\n", data[0], data[1], data[2], data[3]);

      A += Math::Vector2f(50.0f, 60.0f) + B;

      DebugWriter().Write(L"Size = %u\nX = %f Y = %f\n", sizeof(A), A.GetX(), A.GetY());
      DebugWriter().Write(L"dt = %lf\n", deltaTime);
    }

    if ( GetMouse().IsPressed(MouseButton::LEFT) )
    {
      DebugWriter().Write(L"Position = %d %d\n", GetMouse().GetPosition().GetX(), GetMouse().GetPosition().GetY());
      GetGLDevice().SetClearColor({ 1.0f, 0.0f, 1.0f, 1.0f });
    }
  }

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
  void OnRender(const double& alpha) override
  {}
};
}

#ifdef __NEXUS_OS_WINDOWS__
/// Function: WinMain
///
/// Summary:  Main entry point for Windows applications
///
/// Author: jkstpierre
///
/// Date: 3/30/2020
///
/// Parameters:
/// hInstance -       The instance.
/// hPrevInstance -   The previous instance.
/// lpCmdLine -       The command line.
/// nCmdShow -        The command show.
///
/// Returns:  An APIENTRY.
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
  return Nexus::Test("Test", 800, 600, false, true).Run();
}

#elif
/// Function: main
///
/// Summary:  Main entry-point for non windows applications
///
/// Author: jkstpierre
///
/// Date: 3/30/2020
///
/// Parameters:
/// argc -      The number of command-line arguments provided.
/// args -      An array of command-line argument strings.
///
/// Returns:  Exit-code for the process - 0 for success, else an error code.
int main(int argc, char** args)
{
  return Nexus::Test("Test", 800, 600, false, true).Run();
}

#endif

// End of Source\Nexus\Test.cpp
