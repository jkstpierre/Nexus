/// File: Source\Nexus\Graphics\GLDevice.cpp.
///
/// Summary:  Implements the gl device class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLDevice.hpp>

namespace Nexus::Graphics
{
/// Function: glMessageCallback
///
/// Summary:  Callback function for OpenGL to send messages back to the GLDevice.
///
/// Author: jkstpierre
///
/// Date: 4/9/2020
///
/// Parameters:
/// source -      Source for the.
/// type -        The type.
/// id -          The identifier.
/// severity -    The severity.
/// length -      The length.
/// message -     The message.
/// userParam -   The user parameter.
///
/// Returns:  A GLAPIENTRY.
void GLAPIENTRY glMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
  GLDevice* device = const_cast<GLDevice*>(static_cast<const GLDevice*>(userParam));
  device->PushMessage(
    GLMessage(static_cast<GLMessageSource>(source), static_cast<GLMessageType>(type), static_cast<GLMessageSeverity>(severity), id, message, length));
}

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
  // Setup OpenGL here
  
#ifdef _DEBUG
  glEnable(GL_DEBUG_OUTPUT);  // Enable debug output
  glDebugMessageCallback(glMessageCallback, this);  // Setup debug message callback
  glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_OTHER, 0, GL_DEBUG_SEVERITY_NOTIFICATION, -1, "Debugging enabled");
#endif
}

void GLDevice::Shutdown() noexcept
{
  // Free resources here
}

GLMessage GLDevice::PopMessage() noexcept
{
  if ( !mMessageQueue.empty() )
  {
    GLMessage msg = mMessageQueue.front();  // Copy pending message
    mMessageQueue.pop();  // Remove from message queue

    return msg; // Return copy
  }
  else
  {
    return GLMESSAGE_NONE;
  }
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

void GLDevice::PushMessage(const GLMessage& message) noexcept
{
  mMessageQueue.push(message);
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
