/// File: Include\Nexus\Graphics\Base\GLRenderer.hpp.
///
/// Summary:  Declares the gl renderer class.

#ifndef __NEXUS_GRAPHICS_BASE_GLRENDERER_HPP__
#define __NEXUS_GRAPHICS_BASE_GLRENDERER_HPP__

#include <Nexus\Graphics\GLTextureUnit.hpp>

namespace Nexus::Graphics::Base
{
/// Enum: GLDrawMode
///
/// Summary:  Values that represent gl draw modes.
enum class GLDrawMode : unsigned int
{
  _POINTS = 0x0000,
  _LINES = 0x0001,
  _LINE_LOOP = 0x0002,
  _LINE_STRIP = 0x0003,
  _TRIANGLES = 0x0004,
  _TRIANGLE_STRIP = 0x0005,
  _TRIANGLE_FAN = 0x0006,
  _LINES_ADJACENCY = 0x000A,
  _LINE_STRIP_ADJACENCY = 0x000B,
  _TRIANGLES_ADJACENCY = 0x000C,
  _TRIANGLE_STRIP_ADJACENCY = 0x000D,
  _PATCHES = 0x000E
};

/// Struct: GLDrawArraysIndirectCommand
///
/// Summary:  A gl draw arrays indirect command.
///
/// Author: jkstpierre
///
/// Date: 4/17/2020
struct GLDrawArraysIndirectCommand
{
  /// Summary:  Number of vertices per instance.
  unsigned int count;
  /// Summary:  Number of primitives to render.
  unsigned int primCount;
  /// Summary:  The first vertex to render.
  unsigned int first;
  /// Summary:  The base instance.
  unsigned int baseInstance;
};

/// Struct: GLDrawElementsIndirectCommand
///
/// Summary:  A gl draw elements indirect command.
///
/// Author: jkstpierre
///
/// Date: 4/17/2020
struct GLDrawElementsIndirectCommand
{
  /// Summary:  Number of.
  unsigned int count;
  /// Summary:  Number of primitives.
  unsigned int primCount;
  /// Summary:  The first index.
  unsigned int firstIndex;
  /// Summary:  The base vertex.
  unsigned int baseVertex;
  /// Summary:  The base instance.
  unsigned int baseInstance;
};

/// Class:  GLRenderer
///
/// Summary:
///   A renderer handles the drawing of data to the scene. This class is an abstract base class
///   that must be inherited by any class wishing to process draw calls.
///
/// Author: jkstpierre.
///
/// Date: 4/17/2020.
class GLRenderer
{
private:
  /// Summary:  The texture units.
  std::vector<GLTextureUnit*> mTextureUnits;

protected:
  /// Function: GLRenderer::GLRenderer
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  GLRenderer();

  /// Function: GLRenderer::~GLRenderer
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  virtual ~GLRenderer() noexcept;

protected:
  /// Function: DrawArrays
  ///
  /// Summary:  Draw arrays.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -      The mode.
  /// first -     The first.
  /// count -     Number of.
  void DrawArrays(const GLDrawMode& mode, const int& first, const int& count) noexcept;

  /// Function: DrawArraysIndirect
  ///
  /// Summary:  Draw arrays indirect.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -      The mode.
  /// cmd -       The command.
  void DrawArraysIndirect(const GLDrawMode& mode, const GLDrawArraysIndirectCommand& cmd) noexcept;

  /// Function: DrawArraysInstanced
  ///
  /// Summary:  Draw arrays instanced.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// first -           The first.
  /// count -           Number of.
  /// instanceCount -   Number of instances.
  void DrawArraysInstanced(const GLDrawMode& mode, const int& first, const int& count, const int& instanceCount) noexcept;

  /// Function: DrawArraysInstancedBaseInstance
  ///
  /// Summary:  Draw arrays instanced base instance.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// first -           The first.
  /// count -           Number of.
  /// instanceCount -   Number of instances.
  /// baseInstance -    The base instance.
  void DrawArraysInstancedBaseInstance(const GLDrawMode& mode, const int& first, const int& count, const int& instanceCount, 
                                       const unsigned int& baseInstance) noexcept;

  /// Function: DrawElements
  ///
  /// Summary:  Draw elements.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -      The mode.
  /// count -     Number of.
  /// indices -   The indices.
  void DrawElements(const GLDrawMode& mode, const int& count, const void* indices) noexcept;

  /// Function: DrawElementsBaseVertex
  ///
  /// Summary:  Draw elements base vertex.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -        The mode.
  /// count -       Number of.
  /// indices -     The indices.
  /// baseVertex -  The base vertex.
  void DrawElementsBaseVertex(const GLDrawMode& mode, const int& count, const void* indices, const int& baseVertex) noexcept;

  /// Function: DrawElementsIndirect
  ///
  /// Summary:  Draw elements indirect.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -      The mode.
  /// cmd -       The command.
  void DrawElementsIndirect(const GLDrawMode& mode, const GLDrawElementsIndirectCommand& cmd) noexcept;

  /// Function: DrawElementsInstanced
  ///
  /// Summary:  Draw elements instanced.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// count -           Number of.
  /// indices -         The indices.
  /// instanceCount -   Number of instances.
  void DrawElementsInstanced(const GLDrawMode& mode, const int& count, const void* indices, const int& instanceCount) noexcept;

  /// Function: DrawElementsInstancedBaseInstance
  ///
  /// Summary:  Draw elements instanced base instance.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// count -           Number of.
  /// indices -         The indices.
  /// instanceCount -   Number of instances.
  /// baseInstance -    The base instance.
  void DrawElementsInstancedBaseInstance(const GLDrawMode& mode, const int& count, const void* indices, const int& instanceCount, 
                                         const unsigned int baseInstance) noexcept;

  /// Function: DrawElementsInstancedBaseVertex
  ///
  /// Summary:  Draw elements instanced base vertex.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// count -           Number of.
  /// indices -         The indices.
  /// instanceCount -   Number of instances.
  /// baseVertex -      The base vertex.
  void DrawElementsInstancedBaseVertex(const GLDrawMode& mode, const int& count, const void* indices, const int& instanceCount, 
                                       const int& baseVertex) noexcept;

  /// Function: DrawElementsInstancedBaseVertexBaseInstance
  ///
  /// Summary:  Draw elements instanced base vertex base instance.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// mode -            The mode.
  /// count -           Number of.
  /// indices -         The indices.
  /// instanceCount -   Number of instances.
  /// baseVertex -      The base vertex.
  /// baseInstance -    The base instance.
  void DrawElementsInstancedBaseVertexBaseInstance(const GLDrawMode& mode, const int& count, const void* indices, const int& instanceCount, 
                                                   const int& baseVertex, const int& baseInstance) noexcept;
public:
  /// Function: GetTextureUnits
  ///
  /// Summary:  Gets texture units.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Returns:  Null if it fails, else the texture units.
  std::vector<GLTextureUnit*> GetTextureUnits() noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLRenderer.hpp
