/// File: Source\Nexus\Graphics\GLDevice.cpp.
///
/// Summary:  Implements the gl device class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLDevice.hpp>

namespace Nexus::Graphics
{
GLDevice::GLDevice(const unsigned int& glMajorVersion, const unsigned int& glMinorVersion) : mGLVersion{ glMajorVersion, glMajorVersion }, mClearColor(GLDEVICE_DEFAULT_CLEAR_COLOR)
{
  // Do nothing
}

GLDevice::~GLDevice() noexcept
{
  // Do nothing
}

void GLDevice::Initialize()
{
  // Allocate resources here
}

void GLDevice::Shutdown() noexcept
{
  // Free resources here
}

void GLDevice::ClearColorBuffer() noexcept
{
  glClearColor(mClearColor.GetX(), mClearColor.GetY(), mClearColor.GetZ(), mClearColor.GetW());
  glClear(GL_COLOR_BUFFER_BIT);
}

void GLDevice::ClearDepthBuffer() noexcept
{
  glClear(GL_DEPTH_BUFFER_BIT);
}

void GLDevice::ClearStencilBuffer() noexcept
{
  glClear(GL_STENCIL_BUFFER_BIT);
}

void GLDevice::SetClearColor(const Math::Vector4f& clearColor) noexcept
{
  mClearColor = clearColor;
}

const unsigned int& GLDevice::GetGLMajorVersion() const noexcept
{
  return mGLVersion.majorVersion;
}

const unsigned int& GLDevice::GetGLMinorVersion() const noexcept
{
  return mGLVersion.minorVersion;
}

const Math::Vector4f& GLDevice::GetClearColor() const noexcept
{
  return mClearColor;
}
}

// End of Source\Nexus\Graphics\GLDevice.cpp
