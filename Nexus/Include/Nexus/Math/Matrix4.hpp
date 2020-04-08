/// File: Include\Nexus\Math\Matrix4.hpp.
///
/// Summary:  Declares the matrix 4 class.

#ifndef __NEXUS_MATH_MATRIX4_HPP__
#define __NEXUS_MATH_MATRIX4_HPP__

#include <Nexus\Math\Base\Matrix.hpp>
#include <Nexus\Math\Vector3.hpp>
#include <Nexus\Math\Vector4.hpp>
#include <Nexus\Math\Constants.hpp>

namespace Nexus::Math
{
/// Class:  Matrix4
///
/// Summary:  A matrix 4.
///
/// Author: jkstpierre
///
/// Date: 4/6/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Matrix{Matrix4{T}, T, 4} - 
template <typename T>
class Matrix4 : public Base::Matrix<Matrix4<T>, T, 4>
{
public:
  /// Function: Matrix4::Matrix4
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  Matrix4() noexcept : Matrix4(1, 0, 0, 0,
                               0, 1, 0, 0,
                               0, 0, 1, 0,
                               0, 0, 0, 1)
  {

  }

  /// Function: Matrix4::Matrix4
  ///
  /// Summary:
  ///   Builds a 4x4 matrix. The arguments are in row major form but internally stored in column
  ///   major order.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/6/2020.
  ///
  /// Parameters:
  /// a11 -       The 11.
  /// a12 -       The 12.
  /// a13 -       The 13.
  /// a14 -       The 14.
  /// a21 -       The 21.
  /// a22 -       The 22.
  /// a23 -       The 23.
  /// a24 -       The 24.
  /// a31 -       The 31.
  /// a32 -       The 32.
  /// a33 -       The 33.
  /// a34 -       The 34.
  /// a41 -       The 41.
  /// a42 -       The 42.
  /// a43 -       The 43.
  /// a44 -       The 44.
  Matrix4(const T& a11, const T& a12, const T& a13, const T& a14,
          const T& a21, const T& a22, const T& a23, const T& a24,
          const T& a31, const T& a32, const T& a33, const T& a34,
          const T& a41, const T& a42, const T& a43, const T& a44) noexcept :
    Base::Matrix<Matrix4<T>, T, 4>({a11, a21, a31, a41,
                                   a12, a22, a32, a42,
                                   a13, a23, a33, a43,
                                   a14, a24, a34, a44})
  {

  }

public:
  /// Function: *
  ///
  /// Summary:  Multiplication operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  Vector4<T> operator*(const Vector4<T>& rhs) const noexcept
  {
    const T* data = Base::Matrix<Matrix4<T>, T, 4>::GetData();

    // Multiply the vector by the matrix
    return Vector4<T>(data[0] * rhs.GetX() + data[4] * rhs.GetY() + data[8] * rhs.GetZ() + data[12] * rhs.GetW(),
                      data[1] * rhs.GetX() + data[5] * rhs.GetY() + data[9] * rhs.GetZ() + data[13] * rhs.GetW(),
                      data[2] * rhs.GetX() + data[6] * rhs.GetY() + data[10] * rhs.GetZ() + data[14] * rhs.GetW(),
                      data[3] * rhs.GetX() + data[7] * rhs.GetY() + data[11] * rhs.GetZ() + data[15] * rhs.GetW());
  }

public:
  /// Function: OrthographicProjectionMatrix
  ///
  /// Summary:  Builds an orthographic projection matrix
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// left -      The left clipping plane.
  /// right -     The right clipping plane.
  /// bottom -    The bottom clipping plane.
  /// top -       The top clipping plane.
  /// zNear -     The near z clipping plane.
  /// zFar -      The far z clipping plane.
  ///
  /// Returns:  A Matrix4.
  static Matrix4 OrthographicProjectionMatrix(const T& left, const T& right, const T& bottom, const T& top, const T& zNear, const T& zFar) noexcept
  {
    return Matrix4(2 / (right - left), 0, 0, 0,
                   0, 2 / (top - bottom), 0, 0,
                   0, 0, -2 / (zFar - zNear), 0,
                   -(right + left) / (right - left), 
                   -(top + bottom) / (top - bottom), 
                   -(zFar + zNear) / (zFar - zNear), 1);
  }

  /// Function: PerspectiveProjectionMatrix
  ///
  /// Summary:  Builds a perspective projection matrix.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/7/2020.
  ///
  /// Parameters:
  /// fov -      The the field of view
  /// aspect -    The aspect ratio.
  /// zNear -     The near z clipping plane.
  /// zFar -      The far z clipping plane.
  ///
  /// Returns:  A Matrix4.
  static Matrix4 PerspectiveProjectionMatrix(const T& fov, const T& aspect, const T& zNear, const T& zFar) noexcept
  {
    return Matrix4((1 / tanf(fov / 2)) / aspect, 0, 0, 0,
                   0, (1 / tanf(fov / 2)), 0, 0,
                   0, 0, (zFar + zNear) / (zNear - zFar), -1,
                   0, 0, (2 * zFar * zNear) / (zNear - zFar), 0);
  }

  /// Function: TranslationMatrix
  ///
  /// Summary:  Build a translation matrix from a 3 component vector
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Returns:  A Matrix4.
  static Matrix4 TranslationMatrix(const Vector3<T>& translation) noexcept
  {
    return Matrix4(1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   translation.GetX(), translation.GetY(), translation.GetZ(), 1);
  }

  /// Function: RotationMatrix
  ///
  /// Summary:
  ///   Build a rotation matrix from a 3 component vector describing the Euler angles (pitch, yaw,
  ///   roll) in degrees.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/7/2020.
  ///
  /// Parameters:
  /// rotation -  The rotation.
  ///
  /// Returns:  A Matrix4.
  static Matrix4 RotationMatrix(const Vector3<T>& rotation) noexcept
  {
    /// Summary:  Calculate pitch, yaw, and roll in radians
    const float pitch = (rotation.GetX() * CONSTANTS_PI) / 180.0f;
    const float yaw   = (rotation.GetY() * CONSTANTS_PI) / 180.0f;
    const float roll  = (rotation.GetZ() * CONSTANTS_PI) / 180.0f;

    /// Summary:  Calculate trigonometric functions once
    const float pitchSin  = sinf(pitch / 2.0f);
    const float pitchCos  = cosf(pitch / 2.0f);
    const float yawSin    = sinf(yaw / 2.0f);
    const float yawCos    = cosf(yaw / 2.0f);
    const float rollSin   = sinf(roll / 2.0f);
    const float rollCos   = cosf(roll / 2.0f);

    // Build the quaternion 
    Vector4f q(
      pitchCos * yawCos * rollSin - pitchSin * yawSin * rollCos,
      pitchSin * yawCos * rollCos + pitchCos * yawSin * rollSin,
      pitchCos * yawSin * rollCos - pitchSin * yawCos * rollSin,
      pitchCos * yawCos * rollCos + pitchSin * yawSin * rollSin
    );

    q = q.Normalize();  // Normalize the quaternion

    // Build the rotation matrix
    return Matrix4(1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z, 
                      2.0f * q.x * q.y - 2.0f * q.z * q.w, 
                      2.0f * q.x * q.z + 2.0f * q.y * q.w, 
                      0.0f,
                   2.0f * q.x * q.y + 2.0f * q.z * q.w, 
                      1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z, 
                      2.0f * q.y * q.z - 2.0f * q.x * q.w, 
                      0.0f,
                   2.0f * q.x * q.z - 2.0f * q.y * q.w, 
                      2.0f * q.y * q.z + 2.0f * q.x * q.w, 
                      1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y, 
                      0.0f,
                   0.0f, 0.0f, 0.0f, 1.0f);
  }

  /// Function: ScaleMatrix
  ///
  /// Summary:  Build a scale matrix from a 3 component vector describing the scale along each axis.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/7/2020.
  ///
  /// Parameters:
  /// scale -   The scale.
  ///
  /// Returns:  A Matrix4.
  static Matrix4 ScaleMatrix(const Vector3<T>& scale) noexcept
  {
    return Matrix4(scale.GetX(), 0, 0, 0,
                   0, scale.GetY(), 0, 0,
                   0, 0, scale.GetZ(), 0,
                   0, 0, 0, 1);
  }

  /// Function: LookAt
  ///
  /// Summary:  Look at.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// eye -       The eye.
  /// at -        The direction to look toward.
  /// up -        The up.
  ///
  /// Returns:  A Matrix4.
  static Matrix4 LookAt(const Vector3<T>& eye, const Vector3<T>& at, const Vector3<T>& up) noexcept
  {
    Vector3<T> P = eye;
    Vector3<T> Z = (Vector3<T>(P - at)).Normalize();
    Vector3<T> Y = up.Normalize();
    Vector3<T> X = Y.Cross(Z).Normalize();
    Y = Z.Cross(X);

    // Build look at matrix
    return Matrix4(X.GetX(), Y.GetX(), Z.GetX(), 0,
                   X.GetY(), Y.GetY(), Z.GetY(), 0,
                   X.GetZ(), Y.GetZ(), Z.GetZ(), 0,
                   -X.Dot(P), -Y.Dot(P), -Z.Dot(P), 1);
  }
};

/// Typedef:  Matrix4<float> Matrix4f
///
/// Summary:  Defines an alias representing the matrix 4f.
typedef Matrix4<float> Matrix4f;

/// Typedef:  Matrix4<int> Matrix4i
///
/// Summary:  Defines an alias representing the matrix 4i.
typedef Matrix4<int> Matrix4i;
}

#endif

// End of Include\Nexus\Math\Matrix4.hpp
