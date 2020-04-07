/// File: Include\Nexus\Audio\ALDevice.hpp.
///
/// Summary:  Declares the al device class.

#ifndef __NEXUS_AUDIO_ALDEVICE_HPP__
#define __NEXUS_AUDIO_ALDEVICE_HPP__

namespace Nexus::Audio
{
/// Class:  ALDevice
///
/// Summary:  An al device.
///
/// Author: jkstpierre
///
/// Date: 4/7/2020
class ALDevice
{
public:
  /// Function: ALDevice::ALDevice
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ALDevice() noexcept;

  /// Function: ALDevice::~ALDevice
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  virtual ~ALDevice() noexcept;

public:
  /// Function: Initialize
  ///
  /// Summary:  Initializes this. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  void Initialize();

  /// Function: Shutdown
  ///
  /// Summary:  Shuts down this  and frees any resources it is using.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  void Shutdown() noexcept;
};
}

#endif

// End of Include\Nexus\Audio\ALDevice.hpp