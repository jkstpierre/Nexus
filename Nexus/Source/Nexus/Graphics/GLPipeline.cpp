/// File: Source\Nexus\Graphics\GLPipeline.cpp.
///
/// Summary:  Implements the gl pipeline class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLPipeline.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics
{
GLPipelineStage operator|(const GLPipelineStage& lhs, const GLPipelineStage& rhs) noexcept
{
  return static_cast<GLPipelineStage>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
}

GLPipelineStage operator&(const GLPipelineStage& lhs, const GLPipelineStage& rhs) noexcept
{
  return static_cast<GLPipelineStage>(static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
}

GLPipeline::GLPipeline() noexcept
{
  glCreateProgramPipelines(1, &mGLID);
  DebugWriter().Write("GLPipeline %u created.\n", mGLID);
}

GLPipeline::~GLPipeline() noexcept
{
  glDeleteProgramPipelines(1, &mGLID);
  DebugWriter().Write("GLPipeline %u destroyed.\n", mGLID);
}

void GLPipeline::UseProgramStage(const GLProgram* program, const GLPipelineStage& stage) noexcept
{
  glUseProgramStages(mGLID, static_cast<GLbitfield>(stage), program ? program->GetGLID() : NULL);
}
}

// End of Source\Nexus\Graphics\GLPipeline.cpp
