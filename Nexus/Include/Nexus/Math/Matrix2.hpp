/// File: Include\Nexus\Math\Matrix2.hpp.
///
/// Summary:  Declares the matrix 2 class.

#ifndef __NEXUS_MATH_MATRIX2_HPP__
#define __NEXUS_MATH_MATRIX2_HPP__

#include <Nexus\Math\Base\Matrix.hpp>

namespace Nexus::Math
{
/// Class:  Matrix2
///
/// Summary:  A matrix 2.
///
/// Author: jkstpierre
///
/// Date: 4/6/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Matrix{Matrix2{T}, T, 2} - 
template <typename T>
class Matrix2 : public Base::Matrix<Matrix2<T>, T, 2>
{
public:
  /// Function: Matrix2::Matrix2
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  Matrix2() noexcept : Matrix2(1, 0, 
                               0, 1)
  {

  }

  /// Function: Matrix2::Matrix2
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
  /// a21 -       The 21.
  /// a22 -       The 22.
  Matrix2(const T& a11, const T& a12, 
          const T& a21, const T& a22) noexcept : 
    Base::Matrix<Matrix2<T>, T, 2>({a11, a21, 
                                   a12, a22})
  {

  }
};

/// Typedef:  Matrix2<float> Matrix2f
///
/// Summary:  Defines an alias representing the matrix 2f.
typedef Matrix2<float> Matrix2f;

/// Typedef:  Matrix2<int> Matrix2i
///
/// Summary:  Defines an alias representing the matrix 2i.
typedef Matrix2<int> Matrix2i;
}

#endif

// End of Include\Nexus\Math\Matrix2.hpp
