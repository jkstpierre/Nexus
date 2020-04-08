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
#include <Nexus\Exception.hpp>
#include <Nexus\Graphics\GLProgram.hpp>

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
    }

    if ( GetMouse().IsPressed(MouseButton::LEFT) )
    {
      DebugWriter().Write("Position = %d %d\n", GetMouse().GetPosition().GetX(), GetMouse().GetPosition().GetY());
      GetGLDevice().SetClearColor({ 1.0f, 0.0f, 1.0f, 1.0f });
    }

    if ( GetMouse().IsPressed(MouseButton::RIGHT) )
    {
      try
      {
        Graphics::GLProgram program(
          false, 
          Graphics::GLShader(
            Graphics::GLShaderType::VERTEX, 
            "#version 460 core\n\
            layout(location = 0) in vec3 aPos;\
            layout(location = 1) in vec3 aColor;\
            out vec3 col; \
            void main()\
            {\
              gl_Position = vec4(aPos, 1.0);\
              col = aColor;\
            }"
          ),  
          Graphics::GLShader(
            Graphics::GLShaderType::FRAGMENT, 
            "#version 460 core\n\
            out vec4 FragColor;\
            in vec3 col;\
            void main()\
            {\
              FragColor = vec4(col, 1.0f);\
            }"
          )
        );
      }
      catch ( Exception& e )
      {
        DebugWriter().Write(e.ReadMessage());
      }
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
