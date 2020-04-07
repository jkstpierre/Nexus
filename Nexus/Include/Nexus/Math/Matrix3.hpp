/// File: Include\Nexus\Math\Matrix3.hpp.
///
/// Summary:  Declares the matrix 3 class.

#ifndef __NEXUS_MATH_MATRIX3_HPP__
#define __NEXUS_MATH_MATRIX3_HPP__

#include <Nexus\Math\Base\Matrix.hpp>

namespace Nexus::Math
{
/// Class:  Matrix3
///
/// Summary:  A matrix 3.
///
/// Author: jkstpierre
///
/// Date: 4/6/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Matrix{Matrix3{T}, T, 3} - 
template <typename T>
class Matrix3 : public Base::Matrix<Matrix3<T>, T, 3>
{
public:
  /// Function: Matrix3::Matrix3
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  Matrix3() noexcept : Matrix3(1, 0, 0,
                               0, 1, 0,
                               0, 0, 1)
  {

  }

  /// Function: Matrix3::Matrix3
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
  /// a21 -       The 21.
  /// a22 -       The 22.
  /// a23 -       The 23.
  /// a31 -       The 31.
  /// a32 -       The 32.
  /// a33 -       The 33.
  Matrix3(const T& a11, const T& a12, const T& a13, 
          const T& a21, const T& a22, const T& a23, 
          const T& a31, const T& a32, const T& a33) noexcept :
    Base::Matrix<Matrix3<T>, T, 3>({a11, a21, a31,
                                   a12, a22, a31,
                                   a13, a23, a33})
  {

  }
};

/// Typedef:  Matrix3<float> Matrix3f
///
/// Summary:  Defines an alias representing the matrix 3f.
typedef Matrix3<float> Matrix3f;

/// Typedef:  Matrix3<int> Matrix3i
///
/// Summary:  Defines an alias representing the matrix 3i.
typedef Matrix3<int> Matrix3i;
}

#endif

// End of Include\Nexus\Math\Matrix3.hpp
