/// File: Include\Nexus\Graphics\GLDevice.hpp.
///
/// Summary:  Declares the gl device class.

#ifndef __NEXUS_GRAPHICS_GLDEVICE_HPP__
#define __NEXUS_GRAPHICS_GLDEVICE_HPP__

#include <queue>
#include <Nexus\Graphics\GLMessage.hpp>
#include <Nexus\Graphics\GLTextureUnit.hpp>
#include <Nexus\Graphics\GLTextureCache.hpp>

namespace Nexus::Graphics
{
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
  /// Summary:  Queue of messages.
  std::queue<GLMessage> mMessageQueue;
  /// Summary:  The texture units.
  std::vector<GLTextureUnit*> mTextureUnits;
  /// Summary:  The texture cache instance.
  GLTextureCache mTextureCache;

  /// Summary:  The alpha interpol for in between interpolation between states during rendering.
  double mAlpha;

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

  /// Function: Viewport
  ///
  /// Summary:  Viewports.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// x -         An int to process.
  /// y -         An int to process.
  /// w -         An int to process.
  /// h -         An int to process.
  void Viewport(const int& x, const int& y, const int& w, const int& h) noexcept;

  /// Function: ClearColor
  ///
  /// Summary:  Clears the color.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// r -         A float to process.
  /// g -         A float to process.
  /// b -         A float to process.
  /// a -         A float to process.
  void ClearColor(const float& r, const float& g, const float& b, const float& a) noexcept;

  /// Function: ClearColor
  ///
  /// Summary:  Clears the color using default values.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  void ClearColor() noexcept;

  /// Function: ClearDepth
  ///
  /// Summary:  Clears the depth described by depth.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// depth -   The depth.
  void ClearDepth(const float& depth) noexcept;

  /// Function: ClearDepth
  ///
  /// Summary:  Clears the depth using default value.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  void ClearDepth() noexcept;

  /// Function: ClearStencil
  ///
  /// Summary:  Clears the stencil described by stencil.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// stencil -   The stencil.
  void ClearStencil(const int& stencil) noexcept;

  /// Function: ClearStencil
  ///
  /// Summary:  Clears the stencil buffer using default value.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  void ClearStencil() noexcept;

public:
  /// Function: SetAlpha
  ///
  /// Summary:  Sets alpha interpol.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/22/2020.
  ///
  /// Parameters:
  /// alpha -   The alpha interpol.
  void SetAlpha(const double& alpha) noexcept;

public:
  /// Function: GetTextureUnits
  ///
  /// Summary:  Gets texture units.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Returns:  Null if it fails, else the texture units.
  std::vector<GLTextureUnit*>& GetTextureUnits() noexcept;

  /// Function: GetTextureCache
  ///
  /// Summary:  Gets texture cache.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Returns:  The texture cache.
  GLTextureCache& GetTextureCache() noexcept;

  /// Function: GetAlphaInterpol
  ///
  /// Summary:  Gets alpha interpol.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/22/2020.
  ///
  /// Returns:  The alpha interpol.
  const double& GetAlpha() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLDevice.hpp
