/// File: Include\Nexus\Math\Base\Matrix.hpp.
///
/// Summary:  Declares the matrix class.

#ifndef __NEXUS_MATH_BASE_MATRIX_HPP__
#define __NEXUS_MATH_BASE_MATRIX_HPP__

#include <array>

namespace Nexus::Math::Base
{
/// Class:  Matrix
///
/// Summary:  A column major matrix implementation.
///
/// Author: jkstpierre
///
/// Date: 4/6/2020
///
/// Typeparams:
/// M -         Type of the m.
/// T -         Generic type parameter.
/// N -         Type of the n.
template <class M, typename T, size_t N>
class Matrix
{
private:
  /// Summary:  The data for an NxN matrix.
  std::array<T, N * N> mData;

protected:
  /// Function: Matrix::Matrix
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  Matrix() noexcept = delete;

  /// Function: Matrix::Matrix
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Parameters:
  /// data -  The data.
  Matrix(const std::array<T, N * N>& data) noexcept : mData(data)
  {
    // Ensure M is a matrix inheriting from this class
    static_assert(std::is_base_of<Matrix<M, T, N>, M>::value);
  }

public:
  /// Function: ==
  ///
  /// Summary:  Equality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  True if the parameters are considered equivalent.
  bool operator==(const M& rhs) const noexcept
  {
    bool r = true;

    for ( size_t i = 0; i < N && r; i++ )
    {
      for ( size_t j = 0; j < N && r; j++ )
      {
        r = mData[j * N + i] == rhs.GetData()[j * N + i];
      }
    }

    return r;
  }

  /// Function: !=
  ///
  /// Summary:  Inequality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  True if the parameters are not considered equivalent.
  bool operator!=(const M& rhs) const noexcept
  {
    return !(static_cast<const M&>(*this) == rhs);
  }

  /// Function: +
  ///
  /// Summary:  Addition operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M operator+(const M& rhs) const noexcept
  {
    std::array<T, N * N> data;

    for ( size_t i = 0; i < N; i++ )
    {
      for ( size_t j = 0; j < N; j++ )
      {
        data[j * N + i] = mData[j * N + i] + rhs.GetData()[j * N + i];
      }
    }

    // Return a matrix containing the result of the addition
    return M(data);
  }

  /// Function: +=
  ///
  /// Summary:  Addition assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M& operator +=(const M& rhs) noexcept
  {
    static_cast<M&>(*this) = static_cast<M&>(*this) + rhs;

    return static_cast<M&>(*this);
  }

  /// Function: -
  ///
  /// Summary:  Subtraction operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M operator-(const M& rhs) const noexcept
  {
    std::array<T, N * N> data;

    for ( size_t i = 0; i < N; i++ )
    {
      for ( size_t j = 0; j < N; j++ )
      {
        data[j * N + i] = mData[j * N + i] - rhs.GetData()[j * N + i];
      }
    }

    // Return a matrix containing the result of the subtraction
    return M(data);
  }

  /// Function: -=
  ///
  /// Summary:  Subtraction assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M& operator -=(const M& rhs) noexcept
  {
    static_cast<M&>(*this) = static_cast<M&>(*this) - rhs;

    return static_cast<M&>(*this);
  }

  /// Function: *
  ///
  /// Summary:  Multiply matrix by a scalar
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M operator*(const T& rhs) const noexcept
  {
    std::array<T, N * N> data;

    for ( size_t i = 0; i < N; i++ )
    {
      for ( size_t j = 0; j < N; j++ )
      {
        data[j * N + i] = mData[j * N + i] * rhs;
      }
    }

    return M(data);
  }

  /// Function: *=
  ///
  /// Summary:  Multiplication assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M& operator*=(const T& rhs) noexcept
  {
    static_cast<M&>(*this) = static_cast<M&>(*this)* rhs;

    return rhs;
  }

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
  M operator*(const M& rhs) const noexcept
  {
    std::array<T, N * N> data;

    // Multiply the two matrices
    for ( size_t i = 0; i < N; i++ )
    {
      for ( size_t j = 0; j < N; j++ )
      {
        data[j * N + i] = 0;

        for ( size_t k = 0; k < N; k++ )
        {
          data[j * N + i] += mData[k * N + i] * rhs.GetData()[j * N + k];
        }
      }
    }

    // Return the resulting matrix
    return M(data);
  }

  /// Function: *=
  ///
  /// Summary:  Multiplication assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  M& operator*=(const M& rhs) noexcept
  {
    static_cast<M&>(*this) = static_cast<M&>(*this) * rhs;

    return static_cast<M&>(*this);
  }

public:
  /// Function: GetData
  ///
  /// Summary:  Gets the data.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  Null if it fails, else the data.
  const T* GetData() const noexcept
  {
    return mData.data();
  }

  /// Function: GetSize
  ///
  /// Summary:  Gets the size.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/6/2020
  ///
  /// Returns:  The size.
  size_t GetSize() const noexcept
  {
    return mData.size();
  }
};
}

#endif

// End of Include\Nexus\Math\Base\Matrix.hpp
