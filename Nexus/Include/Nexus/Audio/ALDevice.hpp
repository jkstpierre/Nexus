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
  ALDevice();

  /// Function: ALDevice::~ALDevice
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  virtual ~ALDevice() noexcept;
};
}

#endif

// End of Include\Nexus\Audio\ALDevice.hpp