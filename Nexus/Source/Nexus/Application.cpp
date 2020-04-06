/// File: Source\Nexus\Application.cpp.
///
/// Summary:  Implements the application class.

#include <GLAD\GL.h>
#include <SDL2\SDL.h>
#include <Nexus\Application.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Exception.hpp>
#include <Nexus\Timer.hpp>

namespace Nexus
{
Application::Application(const char* windowName, const unsigned int& windowWidth,
                         const unsigned int& windowHeight, const bool& windowFullscreen,
                         const bool& windowUseVSync)
  : mWindow(NULL), mContext(NULL), mRunning(false), mTicksPerSecond(APPLICATION_DEFAULT_TICKS_PER_SECOND), 
  mGLDevice(APPLICATION_DEFAULT_GL_MAJOR_VERSION, APPLICATION_DEFAULT_GL_MINOR_VERSION)
{
  // Initialize required SDL subsystems
  if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0 )
  {
    throw Exception("Error: Failed to initialize SDL2.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Target OpenGL 4.6 core
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GetGLDevice().GetGLMajorVersion());
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GetGLDevice().GetGLMinorVersion());
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  // Setup window flags
  Uint32 flags = 0;
  if ( windowFullscreen )
  {
    flags |= SDL_WINDOW_FULLSCREEN;
  }

  // Create window
  mWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, windowWidth,
                             windowHeight, SDL_WINDOW_OPENGL | flags);
  if ( !mWindow )
  {
    throw Exception("Error: Failed to create window.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Create OpenGL context
  mContext = SDL_GL_CreateContext((SDL_Window*)mWindow);
  if ( !mContext )
  {
    throw Exception("Error: Failed to create OpenGL context.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Check for vertical sync
  if ( windowUseVSync )
  {
    // Enable vsync
    SDL_GL_SetSwapInterval(1);
  }
  else
  {
    // Disable vsync
    SDL_GL_SetSwapInterval(0);
  }

  // Load OpenGL extensions using GLAD
  if ( !gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) )
  {
    throw Exception("Error: Failed to load GLAD.\n");
  }

  DebugWriter().Write(L"Nexus online...\n");
}

Application::~Application()
{
  // Free the context and window
  SDL_GL_DeleteContext(mContext);
  SDL_DestroyWindow((SDL_Window*)mWindow);
  mWindow = mContext = NULL;

  SDL_Quit(); // Shutdown SDL

  DebugWriter().Write(L"Nexus offline...\n"); 
}

int Application::Run()
{
  if ( !IsRunning() )
  {
    mRunning = true; // Indicate game loop is active

    /// Summary:  The frame timer for keeping the game loop running consistently.
    Timer frameTimer;

    /// Summary:  The accumulator for adding up ticks.
    Uint64 accumulator = 0;

    // Run game loop until shutdown
    while ( IsRunning() )
    {
      // Poll for events
      static SDL_Event e;
      while ( SDL_PollEvent(&e) )
      {
        // Check if user has closed the window
        if ( e.type == SDL_QUIT )
        {
          Stop(); // Stop the game loop
        }
        // Check if user has pressed a key
        else if ( e.type == SDL_KEYDOWN )
        {
          mKeyboard.Press(static_cast<Nexus::Key>(e.key.keysym.sym));
        }
        // Check if user has released a key
        else if ( e.type == SDL_KEYUP )
        {
          mKeyboard.Release(static_cast<Nexus::Key>(e.key.keysym.sym));
        }
        // Check if user has pressed a mouse button
        else if ( e.type == SDL_MOUSEBUTTONDOWN )
        {
          mMouse.Press(static_cast<Nexus::MouseButton>(e.button.button));
        }
        // Check if user has released a mouse button
        else if ( e.type == SDL_MOUSEBUTTONUP )
        {
          mMouse.Release(static_cast<Nexus::MouseButton>(e.button.button));
        }
        // Check if user has moved the mouse
        else if ( e.type == SDL_MOUSEMOTION )
        {
          mMouse.SetPosition(Math::Vector2i(e.motion.x, e.motion.y));
        }
      }

      // Increment the accumulator with this frame's delta ticks
      accumulator += frameTimer.ComputeDeltaTicks(); 
      // Compute number of ticks per update
      const Uint64 ticksPerUpdate = frameTimer.GetFrequency() / GetTicksPerSecond();
      // Process as many updates as required
      while ( accumulator >= ticksPerUpdate )
      {
        OnTick(static_cast<double>(ticksPerUpdate) / frameTimer.GetFrequency());
        accumulator -= ticksPerUpdate;
      }

      {
        // Render the scene for this frame
        
        // Clear all the buffers for the frame
        GetGLDevice().ClearColorBuffer();
        GetGLDevice().ClearDepthBuffer();
        GetGLDevice().ClearStencilBuffer();

        // Render a frame using interpolation
        OnRender(static_cast<double>(accumulator) / ticksPerUpdate);

        /// Summary:  Swap window buffers.
        SDL_GL_SwapWindow((SDL_Window*)mWindow);
      }
    }

    return 0;
  }
  else
  {
    return -1;
  }
}

void Application::SetTicksPerSecond(const unsigned int& ticksPerSecond) noexcept
{
  if ( ticksPerSecond > 0 )
  {
    mTicksPerSecond = ticksPerSecond;
  }
}

void Application::Stop() noexcept
{
  mRunning = false;
}

const bool& Application::IsRunning() const noexcept
{
  return mRunning;
}

const unsigned int& Application::GetTicksPerSecond() const noexcept
{
  return mTicksPerSecond;
}

const Keyboard& Application::GetKeyboard() const noexcept
{
  return mKeyboard;
}

const Mouse& Application::GetMouse() const noexcept
{
  return mMouse;
}

Graphics::GLDevice& Application::GetGLDevice() noexcept
{
  return mGLDevice;
}
}

// End of Source\Nexus\Application.cpp
