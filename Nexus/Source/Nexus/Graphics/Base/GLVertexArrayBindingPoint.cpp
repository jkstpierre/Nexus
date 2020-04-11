/// File: Source\Nexus\Graphics\Base\GLVertexArrayBindingPoint.cpp.
///
/// Summary:  Implements the gl vertex array binding point class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\Base\GLVertexArrayBindingPoint.hpp>

namespace Nexus::Graphics::Base
{
void GLVertexArrayBindingPoint::SetVertexBuffer(const unsigned int& vao, const unsigned int& vaoBindingIndex, 
                                                const unsigned int& vbo,const unsigned int& offset, const unsigned int& stride) noexcept
{
  glVertexArrayVertexBuffer(vao, vaoBindingIndex, vbo, offset, stride);
}
}

// End of Source\Nexus\Graphics\Base\GLVertexArrayBindingPoint.cpp
