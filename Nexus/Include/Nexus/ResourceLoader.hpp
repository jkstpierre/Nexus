/// File: Include\Nexus\ResourceLoader.hpp.
///
/// Summary:  Declares the resource loader class.

#ifndef __NEXUS_RESOURCE_LOADER_HPP__
#define __NEXUS_RESOURCE_LOADER_HPP__

#include <Nexus\Macros.hpp>
#ifdef __NEXUS_OS_WINDOWS__
#include <Windows.h>
#endif

namespace Nexus
{
/// Class:  ResourceLoader
///
/// Summary:  Reads embedded data from within the program binary rather than from disk.
///   TODO: Make this class compile cross platform, current implementation relies on Windows OS.
///
/// Author: jkstpierre.
///
/// Date: 4/8/2020.
class ResourceLoader
{
private:
#ifdef __NEXUS_OS_WINDOWS__
  /// Summary:  The resource.
  HRSRC mResource;
  /// Summary:  Handle of the memory.
  HGLOBAL mMemory;
#endif
  /// Summary:  The size.
  size_t mSize;
  /// Summary:  The data.
  void* mData;
  /// Summary:  The resource id.
  int mResourceID;

public:
  /// Function: ResourceLoader::ResourceLoader
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// resourceID -  Identifier for the resource.
  ResourceLoader(const int& resourceID);

  /// Function: ResourceLoader::~ResourceLoader
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  virtual ~ResourceLoader() noexcept;

public:
  /// Function: GetSize
  ///
  /// Summary:  Gets the size.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The size.
  const size_t& GetSize() const noexcept;

  /// Function: GetData
  ///
  /// Summary:  Gets the data.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  Null if it fails, else the data.
  const void* GetData() const noexcept;

  /// Function: GetResourceID
  ///
  /// Summary:  Gets resource identifier.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The resource identifier.
  const int& GetResourceID() const noexcept;
};
}

#endif

// End of Include\Nexus\ResourceLoader.hpp
