/// File: Source\Nexus\Timer.cpp.
///
/// Summary:  Implements the timer class.

#include <Nexus\Timer.hpp>
#include <SDL2\SDL.h>

namespace Nexus
{
Timer::Timer() noexcept : mStartTicks(0), mStopTicks(0)
{
  Reset();
}

void Timer::Reset() noexcept
{
  mStartTicks = mStopTicks = SDL_GetPerformanceCounter();
}

uint64_t Timer::ComputeDeltaTicks() noexcept
{
  mStopTicks = SDL_GetPerformanceCounter();
  uint64_t deltaTicks = mStopTicks - mStartTicks;
  mStartTicks = mStopTicks;

  return deltaTicks;
}

uint64_t Timer::GetFrequency() const noexcept
{
  return SDL_GetPerformanceFrequency();
}
}

// End of Source\Nexus\Timer.cpp
