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
/// Summary:  A matrix.
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
