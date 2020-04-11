/// File: Include\Nexus\Graphics\GLDevice.hpp.
///
/// Summary:  Declares the gl device class.

#ifndef __NEXUS_GRAPHICS_GLDEVICE_HPP__
#define __NEXUS_GRAPHICS_GLDEVICE_HPP__

#include <queue>
#include <Nexus\Math\Vector4.hpp>
#include <Nexus\Graphics\GLMessage.hpp>

namespace Nexus::Graphics
{
/// Summary:  The gldevice default framebuffer clear color.
const Math::Vector4f GLDEVICE_DEFAULT_CLEAR_COLOR = { 0.0f, 0.0f, 0.0f, 1.0f };
/// Summary:  Depth of the gldevice default clear.
const float GLDEVICE_DEFAULT_CLEAR_DEPTH = 1.0f;
/// Summary:  The gldevice default clear stencil.
const int GLDEVICE_DEFAULT_CLEAR_STENCIL = 0;

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
  /// Summary:  The color to clear the color buffer.
  Math::Vector4f mClearColor;

  /// Summary:  The value for clearing the depth buffer.
  float mClearDepth;

  /// Summary:  The value to clear the stencil buffer with.
  int mClearStencil;

  /// Summary:  Queue of messages.
  std::queue<GLMessage> mMessageQueue;

public:
  /// Function: GLDevice::GLDevice
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  GLDevice() noexcept;

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
  /// Function: PopMessage
  ///
  /// Summary:  Pops a message or returns a GLMESSAGE_NONE if there is no message.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  A GLMessage.
  GLMessage PopMessage() noexcept;

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
  /// Function: PushMessage
  ///
  /// Summary:  Pushes a message onto the queue.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// message -   The message.
  void PushMessage(const GLMessage& message) noexcept;

  /// Function: SetClearColor
  ///
  /// Summary:  Sets clear color for ClearColorBuffer calls.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Parameters:
  /// clearColor -  The clear color.
  void SetClearColor(const Math::Vector4f& clearColor) noexcept;

  /// Function: SetClearDepth
  ///
  /// Summary:  Sets clear depth for ClearDepthBuffer calls.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// clearDepth -  Depth of the clear.
  void SetClearDepth(const float& clearDepth) noexcept;

  /// Function: SetClearStencil
  ///
  /// Summary:  Sets clear stencil for ClearStencilBuffer calls.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// clearStencil -  The clear stencil.
  void SetClearStencil(const int& clearStencil) noexcept;

  /// Function: SetViewport
  ///
  /// Summary:  Sets the viewport for subsequent drawcalls.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// x -         An int to process.
  /// y -         An int to process.
  /// width -     The width.
  /// height -    The height.
  void SetViewport(const int& x, const int& y, const int& width, const int& height) noexcept;

public:
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

  /// Function: GetClearDepth
  ///
  /// Summary:  Gets clear depth.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Returns:  The clear depth.
  const float& GetClearDepth() const noexcept;

  /// Function: GetClearStencil
  ///
  /// Summary:  Gets clear stencil.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Returns:  The clear stencil.
  const int& GetClearStencil() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLDevice.hpp
