/// File: Include\Nexus\Graphics\GLDevice.hpp.
///
/// Summary:  Declares the gl device class.

#ifndef __NEXUS_GRAPHICS_GLDEVICE_HPP__
#define __NEXUS_GRAPHICS_GLDEVICE_HPP__

#include <Nexus\Math\Vector4.hpp>

namespace Nexus::Graphics
{
/// Summary:  The gldevice default framebuffer clear color.
const Math::Vector4f GLDEVICE_DEFAULT_CLEAR_COLOR = { 0.0f, 0.0f, 0.0f, 1.0f };

/// Class:  GLDevice
///
/// Summary:
///   Manages the graphics pipeline for Nexus. All graphics objects are built through it and the
///   renderers are managed by it.
///
/// Author: jkstpierre.
///
/// Date: 3/31/2020.
class GLDevice
{
private:
  /// Summary:  An anonymous struct for the currently running version of OpenGL.
  struct
  {
    /// Summary:  The major version.
    unsigned int majorVersion;
    /// Summary:  The minor version.
    unsigned int minorVersion;
  } mGLVersion;

  /// Summary:  The clear color for the default frame buffer.
  Math::Vector4f mClearColor;

public:
  /// Function: GLDevice::GLDevice
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Parameters:
  /// glMajorVersion -  The gl major version.
  /// glMinorVersion -  The gl minor version.
  GLDevice(const unsigned int& glMajorVersion, const unsigned int& glMinorVersion);

  /// Function: GLDevice::~GLDevice
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  virtual ~GLDevice() noexcept;

  /// Function: Initialize
  ///
  /// Summary:  Initializes the GLDevice. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void Initialize();

  /// Function: Shutdown
  ///
  /// Summary:  Shuts down this  and frees any resources it is using.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void Shutdown() noexcept;

public:
  /// Function: ClearColorBuffer
  ///
  /// Summary:  Clears the color buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void ClearColorBuffer() noexcept;

  /// Function: ClearDepthBuffer
  ///
  /// Summary:  Clears the depth buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void ClearDepthBuffer() noexcept;

  /// Function: ClearStencilBuffer
  ///
  /// Summary:  Clears the stencil buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  void ClearStencilBuffer() noexcept;

public:
  /// Function: SetClearColor
  ///
  /// Summary:  Sets clear color.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Parameters:
  /// clearColor -  The clear color.
  void SetClearColor(const Math::Vector4f& clearColor) noexcept;

public:
  /// Function: GetGLMajorVersion
  ///
  /// Summary:  Gets gl major version.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The gl major version.
  const unsigned int& GetGLMajorVersion() const noexcept;

  /// Function: GetGLMinorVersion
  ///
  /// Summary:  Gets gl minor version.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The gl minor version.
  const unsigned int& GetGLMinorVersion() const noexcept;

  /// Function: GetClearColor
  ///
  /// Summary:  Gets clear color.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The clear color.
  const Math::Vector4f& GetClearColor() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLDevice.hpp
