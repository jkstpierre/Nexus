/// File: Source\Nexus\Graphics\Base\GLDeviceChild.cpp.
///
/// Summary:  Implements the gl device child class.

#include <Nexus\Graphics\Base\GLDeviceChild.hpp>

namespace Nexus::Graphics::Base
{
GLDevice* GLDeviceChild::glDevice = nullptr;

void GLDeviceChild::SetGLDevice(GLDevice* glDevice) noexcept
{
  GLDeviceChild::glDevice = glDevice;
}
}

// End of Source\Nexus\Graphics\Base\GLDeviceChild.cpp
