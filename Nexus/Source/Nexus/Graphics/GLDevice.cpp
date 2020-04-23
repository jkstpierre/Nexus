/// File: Source\Nexus\Graphics\GLDevice.cpp.
///
/// Summary:  Implements the gl device class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLDevice.hpp>
#include <Nexus\Graphics\Base\GLDeviceChild.hpp>
#include <Nexus\Exception.hpp>
#include <Nexus\DebugWriter.hpp>

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

GLDevice::GLDevice() noexcept : mAlpha(0.0)
{
  // Setup OpenGL here //

#ifdef _DEBUG
  glEnable(GL_DEBUG_OUTPUT);  // Enable debug output
  glDebugMessageCallback(glMessageCallback, this);  // Setup debug message callback
  glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_OTHER, 0, GL_DEBUG_SEVERITY_NOTIFICATION, -1, "Debugging enabled");
#endif

  // Set the glDevice so renderables and renderers can see it
  Base::GLDeviceChild::SetGLDevice(this);  

  /// Summary:  Allocate maximum number of texture units possible
  mTextureUnits = GLTextureUnit::AllocateTextureUnits(GLTextureUnit::QueryMaxTextureUnits());

  DebugWriter().Write("GLDevice created.\n");
}

GLDevice::~GLDevice() noexcept
{
  // Free resources here

  GLTextureUnit::FreeTextureUnits(mTextureUnits); // Free the texture units

  DebugWriter().Write("GLDevice destroyed.\n");
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

void GLDevice::PushMessage(const GLMessage& message) noexcept
{
  mMessageQueue.push(message);
}

void GLDevice::Viewport(const int& x, const int& y, const int& w, const int& h) noexcept
{
  glViewport(x, y, w, h);
}

void GLDevice::ClearColor(const float& r, const float& g, const float& b, const float& a) noexcept
{
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void GLDevice::ClearColor() noexcept
{
  return ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void GLDevice::ClearDepth(const float& depth) noexcept
{
  glClearDepthf(depth);
  glClear(GL_DEPTH_BUFFER_BIT);
}

void GLDevice::ClearDepth() noexcept
{
  return ClearDepth(1.0f);
}

void GLDevice::ClearStencil(const int& stencil) noexcept
{
  glClearStencil(stencil);
  glClear(GL_STENCIL_BUFFER_BIT);
}

void GLDevice::ClearStencil() noexcept
{
  return ClearStencil(0);
}

void GLDevice::SetAlpha(const double& alpha) noexcept
{
  mAlpha = alpha;
}

std::vector<GLTextureUnit*>& GLDevice::GetTextureUnits() noexcept
{
  return mTextureUnits;
}

GLTextureCache& GLDevice::GetTextureCache() noexcept
{
  return mTextureCache;
}

const double& GLDevice::GetAlpha() const noexcept
{
  return mAlpha;
}
}

// End of Source\Nexus\Graphics\GLDevice.cpp
