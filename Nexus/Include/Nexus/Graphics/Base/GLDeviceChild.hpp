/// File: Include\Nexus\Graphics\Base\GLDeviceChild.hpp.
///
/// Summary:  Declares the gl device child class.

#ifndef __NEXUS_GRAPHICS_BASE_GLDEVICECHILD_HPP__
#define __NEXUS_GRAPHICS_BASE_GLDEVICECHILD_HPP__

#include <Nexus\Graphics\GLDevice.hpp>

namespace Nexus::Graphics::Base
{
/// Class:  GLDeviceChild
///
/// Summary:
///   A child of the GLDevice. This class allows for children to have access to the active GLDevice
///   instance.
///
/// Author: jkstpierre.
///
/// Date: 4/20/2020.
class GLDeviceChild
{
  // Grant GLDevice friendship so it can set the glDevice pointer
  friend class Nexus::Graphics::GLDevice;

protected:
  /// Summary:  The gl device.
  static GLDevice* glDevice;

protected:
  /// Function: GLDeviceChild::GLDeviceChild
  ///
  /// Summary:  Default constructor.
  ///  
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  GLDeviceChild() noexcept = default;
  
public:
  /// Function: GLDeviceChild::~GLDeviceChild
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  virtual ~GLDeviceChild() noexcept = default;

private:
  /// Function: SetGLDevice
  ///
  /// Summary:  Sets gl device for all children inheriting from this class
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Parameters:
  /// glDevice -  [in,out] If non-null, the gl device.
  static void SetGLDevice(GLDevice* glDevice) noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLDeviceChild.hpp
