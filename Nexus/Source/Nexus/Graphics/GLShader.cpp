/// File: Source\Nexus\Graphics\GLShader.cpp.
///
/// Summary:  Implements the gl shader class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLShader.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLShader::GLShader(const GLShaderType& type, const char* source) : mType(type)
{
  // Create a new shader
  mGLID = glCreateShader((GLenum)type);
  if ( mGLID )
  {
    // If shader creation was successful, compile the shader
    glShaderSource(mGLID, 1, &source, GL_NONE);
    glCompileShader(mGLID);

    // Check for errors
    static const unsigned int ERROR_LOG_SIZE = 512U;
    static GLchar errorLog[ERROR_LOG_SIZE];
    static GLint  success;
    glGetShaderiv(mGLID, GL_COMPILE_STATUS, &success);

    if ( !success )
    {
      // If shader failed to compile, get error message, delete the shader, and throw exception
      glGetShaderInfoLog(mGLID, ERROR_LOG_SIZE, GL_NONE, errorLog);
      glDeleteShader(mGLID);
      mGLID = Base::GLOBJECT_GLID_NONE;
      throw Exception("GLShader Error: Failed to compile.\nGLSL %s\n", errorLog);
    }
  }
  else
  {
    // Failed to create a shader handle
    throw Exception("GLShader Error: Failed to create shader of type 0x%x.\n", (GLenum)type);
  }
}

GLShader::~GLShader() noexcept
{
  glDeleteShader(mGLID);
  mGLID = Base::GLOBJECT_GLID_NONE;
}

const GLShaderType& GLShader::GetType() const noexcept
{
  return mType;
}
}

// End of Source\Nexus\Graphics\GLShader.cpp
