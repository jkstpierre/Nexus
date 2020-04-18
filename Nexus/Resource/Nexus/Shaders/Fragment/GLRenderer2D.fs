/// File: Resource\Nexus\Shaders\Fragment\GLRenderer2D.fs.
///
/// Summary:  Gl renderer 2D class.


#version 460 core

out vec4 FragColor;

in vec3 color;

void main()
{
  FragColor = vec4(color, 1.0);
}

// End of Resource\Nexus\Shaders\Fragment\GLRenderer2D.fs
