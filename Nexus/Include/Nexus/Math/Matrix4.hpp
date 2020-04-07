/// File: Include\Nexus\Math\Matrix4.hpp.
///
/// Summary:  Declares the matrix 4 class.

#ifndef __NEXUS_MATH_MATRIX4_HPP__
#define __NEXUS_MATH_MATRIX4_HPP__

#include <Nexus\Math\Base\Matrix.hpp>

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
class Matrix4 : Base::Matrix<Matrix4<T>, T, 4>
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
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
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
          const T& a41, const T& a42, const T& a43, const T& a44) noexcept
  {

  }
};
}

#endif

// End of Include\Nexus\Math\Matrix4.hpp
