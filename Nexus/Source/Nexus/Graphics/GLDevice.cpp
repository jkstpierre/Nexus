/// File: Source\Nexus\Graphics\GLDevice.cpp.
///
/// Summary:  Implements the gl device class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLDevice.hpp>

namespace Nexus::Graphics
{
GLDevice::GLDevice(const unsigned int& glMajorVersion, const unsigned int& glMinorVersion) noexcept : 
  mGLVersion{ glMajorVersion, glMajorVersion }, mClearColor(GLDEVICE_DEFAULT_CLEAR_COLOR), 
  mClearDepth(GLDEVICE_DEFAULT_CLEAR_DEPTH), mClearStencil(GLDEVICE_DEFAULT_CLEAR_STENCIL)
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
  glClearDepth(mClearDepth);
  glClear(GL_DEPTH_BUFFER_BIT);
}

void GLDevice::ClearStencilBuffer() noexcept
{
  glClearStencil(mClearStencil);
  glClear(GL_STENCIL_BUFFER_BIT);
}

void GLDevice::SetClearColor(const Math::Vector4f& clearColor) noexcept
{
  mClearColor = clearColor;
}

void GLDevice::SetClearDepth(const float& clearDepth) noexcept
{
  mClearDepth = clearDepth;
}

void GLDevice::SetClearStencil(const int& clearStencil) noexcept
{
  mClearStencil = clearStencil;
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

const float& GLDevice::GetClearDepth() const noexcept
{
  return mClearDepth;
}

const int& GLDevice::GetClearStencil() const noexcept
{
  return mClearStencil;
}
}

// End of Source\Nexus\Graphics\GLDevice.cpp
