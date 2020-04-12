/// File: Include\Nexus\Graphics\GLPipeline.hpp.
///
/// Summary:  Declares the gl pipeline class.

#ifndef __NEXUS_GRAPHICS_GLPIPELINE_HPP__
#define __NEXUS_GRAPHICS_GLPIPELINE_HPP__

#include <Nexus\Graphics\GLProgram.hpp>

namespace Nexus::Graphics
{
/// Enum: GLPipelineStage
///
/// Summary:  Values that represent gl pipeline stages.
enum class GLPipelineStage : unsigned int
{
  _VERTEX_SHADER = 0x00000001,
  _FRAGMENT_SHADER = 0x00000002,
  _GEOMETRY_SHADER = 0x00000004,
  _TESS_CONTROL_SHADER = 0x00000008,
  _TESS_EVALUATION_SHADER = 0x00000010,
  _COMPUTE_SHADER = 0x00000020
};

/// Class:  GLPipeline
///
/// Summary:  A gl pipeline.
///
/// Author: jkstpierre
///
/// Date: 4/8/2020
class GLPipeline : public Base::GLObject
{
public:
  /// Function: GLPipeline::GLPipeline
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  GLPipeline() noexcept;

  /// Function: GLPipeline::~GLPipeline
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  virtual ~GLPipeline() noexcept;

public:
  /// Function: UseProgramStage
  ///
  /// Summary:
  ///   Use a program for a specific stage of the rendering pipeline. If nullptr, no program will be
  ///   used for the given stage.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// program -   The program.
  /// stage -     The stage.
  void UseProgramStage(const GLProgram* program, const GLPipelineStage& stage) noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLPipeline.hpp
