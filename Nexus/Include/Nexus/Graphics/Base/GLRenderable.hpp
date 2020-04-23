/// File: Include\Nexus\Graphics\Base\GLRenderable.hpp.
///
/// Summary:  Declares the gl renderable class.

#ifndef __NEXUS_GRAPHICS_BASE_GLRENDERABLE_HPP__
#define __NEXUS_GRAPHICS_BASE_GLRENDERABLE_HPP__

#include <glm\glm.hpp>
#include <Nexus\Graphics\Base\GLDeviceChild.hpp>

namespace Nexus::Graphics::Base
{
/// Class:  GLRenderableState
///
/// Summary:  Interpolates between a previous and current state for frames
///
/// Author: jkstpierre
///
/// Date: 4/22/2020
///
/// Typeparams:
/// T -   Generic type parameter.
template <typename T>
class GLRenderableState
{
private:
  /// Summary:  The previous.
  T mPrev;
  /// Summary:  The curr.
  T mCurr;

public:
  /// Function: GLRenderableState::GLRenderableState
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Parameters:
  /// state -   The state.
  GLRenderableState(const T& state) noexcept
  {
    Set(state);
  }

  /// Function: GLRenderableState::~GLRenderableState
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  virtual ~GLRenderableState() noexcept = default;

public:
  /// Function: Set
  ///
  /// Summary:  Sets the given state to a starting value.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Parameters:
  /// state -   The state to set.
  void Set(const T& state) noexcept
  {
    mPrev = mCurr = state;
  }

  /// Function: Update
  ///
  /// Summary:  Updates the given newState.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Parameters:
  /// newState -  State of the new.
  void Update(const T& newState) noexcept
  {
    mPrev = mCurr;
    mCurr = newState;
  }

public:
  /// Function: Ref
  ///
  /// Summary:  Reference the current state
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/22/2020.
  ///
  /// Returns:  A reference to a const T.
  const T& Ref() const noexcept
  {
    return mCurr;
  }

  /// Function: Interpolate
  ///
  /// Summary:  Interpolates between the prev and curr state with respect to alpha
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Parameters:
  /// alpha -   The alpha.
  ///
  /// Returns:  A T.
  T Interpolate(const double& alpha) const noexcept
  {
    return (mCurr * alpha) + (mPrev * (1.0 - alpha));
  }
};

/// Summary:  The glrenderable default ambient color.
const glm::vec4 GLRENDERABLE_DEFAULT_AMBIENT_COLOR = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
/// Summary:  The glrenderable default position.
const glm::vec3 GLRENDERABLE_DEFAULT_POSITION = glm::vec3(0.0f, 0.0f, 0.0f);

/// Class:  GLRenderable
///
/// Summary:  Base class for all objects wishing to be drawn by GLRenderer objects to inherit from.
///
/// Author: jkstpierre.
///
/// Date: 4/20/2020.
class GLRenderable : public Base::GLDeviceChild
{
protected:
  /// Summary:  The ambient color for the GLRenderable.
  GLRenderableState<glm::vec4> mAmbientColor;
  /// Summary:  The position.
  GLRenderableState<glm::vec3> mPosition;

protected:
  /// Function: GLRenderable::GLRenderable
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  GLRenderable() noexcept;

  /// Function: GLRenderable::GLRenderable
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/21/2020.
  ///
  /// Parameters:
  /// ambientColor -  The ambient color.
  /// position -      The position.
  GLRenderable(const glm::vec4& ambientColor, const glm::vec3& position) noexcept;

public:
  /// Function: GLRenderable::~GLRenderable
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  virtual ~GLRenderable() noexcept = default;

public:
  /// Function: GetAmbientColor
  ///
  /// Summary:  Gets ambient color.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Returns:  The ambient color.
  GLRenderableState<glm::vec4>& GetAmbientColor() noexcept;

  /// Function: GetPosition
  ///
  /// Summary:  Gets the position.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Returns:  The position.
  GLRenderableState<glm::vec3>& GetPosition() noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLRenderable.hpp
