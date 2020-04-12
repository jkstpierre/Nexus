/// File: Include\Nexus\Graphics\Base\GLRenderer.hpp.
///
/// Summary:  Declares the gl renderer class.

#ifndef __NEXUS_GRAPHICS_BASE_GLRENDERER_HPP__
#define __NEXUS_GRAPHICS_BASE_GLRENDERER_HPP__

#include <unordered_map>
#include <Nexus\Graphics\GLVertexArray.hpp>
#include <Nexus\Graphics\GLPipeline.hpp>

namespace Nexus::Graphics::Base
{
/// Class:  GLRenderer
///
/// Summary:
///   An abstract base class for renderers. A GLRenderer object stores the common fields needed to
///   render geometry to the screen.
///
/// Author: jkstpierre.
///
/// Date: 4/11/2020.
///
/// Typeparams:
/// T -   Generic type parameter.
template <typename T>
class GLRenderer
{
protected:
  /// Summary:  The vao to save OpenGL state for draw calls.
  Graphics::GLVertexArray mVAO;
  /// Summary:  The buffer to store vertex data.
  Graphics::GLBuffer<T> mVBO;
  /// Summary:  The element buffer to describe the geometry in the vbo.
  Graphics::GLBuffer<unsigned int> mEBO;

  /// Summary:  The programs in use by the renderer.
  std::unordered_map<GLPipelineStage, GLProgram*> mPrograms;
  /// Summary:  The shader pipeline where programs can be swapped in and out.
  GLPipeline mPipeline;

protected:
  /// Function: GLRenderer::GLRenderer
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/12/2020
  GLRenderer() noexcept = default;

  /// Function: GLRenderer::~GLRenderer
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/12/2020
  virtual ~GLRenderer() noexcept = default;

public:
  /// Function: Flush
  ///
  /// Summary:  Draws the remaining geometry to the screen and clears the buffers.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/12/2020.
  virtual void Flush() noexcept = 0;

  /// Function: SetProgram
  ///
  /// Summary:  Sets a program at a given stage. NOTE: This will force a flush to occur.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/12/2020.
  ///
  /// Parameters:
  /// program -   The program to set, if null, no program will be used at the given stage.
  /// stage -     The stage.
  void SetProgram(const GLProgram* program, const GLPipelineStage& stage) noexcept
  {
    Flush();  // Draw all prior geometry using old programs before updating.
    mPrograms[stage] = program; // TODO: Consider changing to erase?
  }

public:
  /// Function: GetVAO
  ///
  /// Summary:  Gets the vao.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/12/2020
  ///
  /// Returns:  The vao.
  const Graphics::GLVertexArray& GetVAO() const noexcept
  {
    return mVAO;
  }

  /// Function: GetProgram
  ///
  /// Summary:
  ///   Gets the program attached to a given stage of the pipeline. Will return null if no program is
  ///   attached at the requested stage.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/12/2020.
  ///
  /// Parameters:
  /// stage -   The stage.
  ///
  /// Returns:  Null if it fails, else the program.
  GLProgram* GetProgram(const GLPipelineStage& stage) noexcept
  {
    if ( mPrograms.find(stage) != mPrograms.end() )
    {
      return mPrograms.at(stage);
    }
    else
    {
      return NULL;
    }
  }
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLRenderer.hpp
