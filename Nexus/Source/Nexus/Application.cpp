/// File: Source\Nexus\Application.cpp.
///
/// Summary:  Implements the application class.

#include <GLAD\GL.h>
#include <SDL2\SDL.h>

#include <Nexus\Application.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus {
Application::Application(const char *windowName,
                         const unsigned int &windowWidth,
                         const unsigned int &windowHeight,
                         const bool &windowFullscreen,
                         const bool &windowUseVSync)
    : mWindow(NULL), mRunning(false) {
  // Initialize required SDL subsystems
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0) {
    throw Exception("Error: Failed to initialize SDL2.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Target OpenGL 4.6 core
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  // Setup window flags
  Uint32 flags = 0;
  if (windowFullscreen) {
    flags |= SDL_WINDOW_FULLSCREEN;
  }

  // Create window
  mWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight,
                             SDL_WINDOW_OPENGL | flags);
  if (!mWindow) {
    throw Exception("Error: Failed to create window.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Create OpenGL context
  mContext = SDL_GL_CreateContext((SDL_Window *)mWindow);
  if (!mContext) {
    throw Exception("Error: Failed to create OpenGL context.\n  Reason: %s\n",
                    SDL_GetError());
  }

  // Load OpenGL extensions using GLAD
  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    throw Exception("Error: Failed to load GLAD.\n");
  }

  printf("Nexus online...\n");
}

Application::~Application() {
  // Free the context and window
  SDL_GL_DeleteContext(mContext);
  SDL_DestroyWindow((SDL_Window *)mWindow);
  mWindow = mContext = NULL;

  SDL_Quit(); // Shutdown SDL

  printf("Nexus offline...\n");
}

int Application::Run() {
  if (!IsRunning()) {
    mRunning = true; // Indicate game loop is active

    // Run game loop until shutdown
    while (IsRunning()) {
      // Poll for events
      static SDL_Event e;
      while (SDL_PollEvent(&e)) {
        // Check if user has closed the window
        if (e.type == SDL_QUIT) {
          Stop(); // Stop the game loop
        } else {
        }
      }
    }

    return 0;
  } else {
    return -1;
  }
}

void Application::Stop() noexcept { mRunning = false; }

const bool &Application::IsRunning() const noexcept { return mRunning; }
} // namespace Nexus

// End of Source\Nexus\Application.cpp
