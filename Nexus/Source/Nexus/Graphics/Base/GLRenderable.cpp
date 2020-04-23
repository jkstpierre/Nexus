/// File: Source\Nexus\Graphics\Base\GLRenderable.cpp.
///
/// Summary:  Implements the gl renderable class.

#include <Nexus\Graphics\Base\GLRenderable.hpp>

namespace Nexus::Graphics::Base
{
GLRenderable::GLRenderable() noexcept : 
  GLRenderable(GLRENDERABLE_DEFAULT_AMBIENT_COLOR, GLRENDERABLE_DEFAULT_POSITION)
{}

GLRenderable::GLRenderable(const glm::vec4& ambientColor, const glm::vec3& position) noexcept :
  mAmbientColor(ambientColor), mPosition(position)
{}

GLRenderableState<glm::vec4>& GLRenderable::GetAmbientColor() noexcept
{
  return mAmbientColor;
}

GLRenderableState<glm::vec3>& GLRenderable::GetPosition() noexcept
{
  return mPosition;
}
}

// End of Source\Nexus\Graphics\Base\GLRenderable.cpp
