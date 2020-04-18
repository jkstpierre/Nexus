/// File: Source\Nexus\Graphics\GLVertexArrayBindingPoint.cpp.
///
/// Summary:  Implements the gl vertex array binding point class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArrayBindingPoint.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLVertexArrayBindingPoint::GLVertexArrayBindingPoint(const unsigned int& vaoGLID, const unsigned int& vaoBindingPointIndex) noexcept :
  mVertexArrayGLID(vaoGLID), 
  mBindingPointIndex(vaoBindingPointIndex),
  mVertexBufferGLID(GLVERTEXARRAYBINDINGPOINT_DEFAULT_VERTEX_BUFFER_GLID)
{
  // Set initial state
  SetDivisor(GLVERTEXARRAYBINDINGPOINT_DEFAULT_DIVISOR);
  SetVertexBuffer(nullptr);

  DebugWriter().Write("GLVertexArrayBindingPoint %u created for GLVertexArray %u.\n", 
                      mBindingPointIndex, mVertexArrayGLID);
}

GLVertexArrayBindingPoint::~GLVertexArrayBindingPoint() noexcept
{
  // Reset state
  SetDivisor(GLVERTEXARRAYBINDINGPOINT_DEFAULT_DIVISOR);
  SetVertexBuffer(nullptr);

  DebugWriter().Write("GLVertexArrayBindingPoint %u destroyed for GLVertexArray %u.\n",
                      mBindingPointIndex, mVertexArrayGLID);
}

std::vector<GLVertexArrayBindingPoint*> GLVertexArrayBindingPoint::AllocateVertexArrayBindingPoints(const unsigned int& vaoGLID, 
                                                                                                    const unsigned int& count)
{
  // Get the max number of binding points for a given vertex array object
  unsigned int maxBindingPoints = QueryMaxVertexArrayBindingPoints();

  // Ensure requested number of binding points can be allocated
  if ( count <= maxBindingPoints )
  {
    std::vector<GLVertexArrayBindingPoint*> bindingPoints;

    for ( unsigned int i = 0; i < count; i++ )
    {
      bindingPoints.push_back(new GLVertexArrayBindingPoint(vaoGLID, i));
    }

    return bindingPoints;
  }
  // Throw exception if invalid number of binding points were requested
  else
  {
    throw Exception("GLVertexArrayBindingPoint Error: Cannot allocated %u binding points. Maximum is %u.\n", 
                    count, maxBindingPoints);
  }
}

void GLVertexArrayBindingPoint::FreeVertexArrayBindingPoints(std::vector<GLVertexArrayBindingPoint*>& bindingPoints) noexcept
{
  for ( auto& bindingPoint : bindingPoints )
  {
    delete bindingPoint;
  }

  bindingPoints.clear();
}

unsigned int GLVertexArrayBindingPoint::QueryMaxVertexArrayBindingPoints() noexcept
{
  int maxBindings;
  glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &maxBindings);

  return maxBindings;
}

void GLVertexArrayBindingPoint::SetDivisor(const unsigned int& divisor) noexcept
{
  glVertexArrayBindingDivisor(mVertexArrayGLID, mBindingPointIndex, divisor);
}

const unsigned int& GLVertexArrayBindingPoint::GetVertexArrayGLID() const noexcept
{
  return mVertexArrayGLID;
}

const unsigned int& GLVertexArrayBindingPoint::GetBindingPointIndex() const noexcept
{
  return mBindingPointIndex;
}

const unsigned int& GLVertexArrayBindingPoint::GetVertexBufferGLID() const noexcept
{
  return mVertexBufferGLID;
}
}

// End of Source\Nexus\Graphics\GLVertexArrayBindingPoint.cpp
