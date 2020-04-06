/// File: Include\Nexus\Timer.hpp.
///
/// Summary:  Declares the timer class.

#ifndef __NEXUS_TIMER_HPP__
#define __NEXUS_TIMER_HPP__

#include <cinttypes>

namespace Nexus
{
/// Class:  Timer
///
/// Summary:  Measures the temporal distance between two points in CPU clock ticks.
///
/// Author: jkstpierre
///
/// Date: 3/31/2020
class Timer
{
private:
  /// Summary:  The start ticks.
  uint64_t mStartTicks;

  /// Summary:  The stop ticks.
  uint64_t mStopTicks;

public:
  /// Function: Timer::Timer
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  Timer() noexcept;

  /// Function: Timer::~Timer
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  virtual ~Timer() noexcept = default;

public:
  /// Function: Reset
  ///
  /// Summary: Resets the timer. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void Reset() noexcept;

  /// Function: GetTicks
  ///
  /// Summary:  Gets the number of ticks since the last ComputeDeltaTicks().
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The ticks.
  uint64_t ComputeDeltaTicks() noexcept;

public:
  /// Function: GetFrequency
  ///
  /// Summary:  Gets the number of ticks per second.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The frequency.
  uint64_t GetFrequency() const noexcept;
};
}

#endif

// End of Include\Nexus\Timer.hpp
