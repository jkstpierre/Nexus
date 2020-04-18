/// File: Source\Nexus\ResourceLoader.cpp.
///
/// Summary:  Implements the resource loader class.

#include <Nexus\ResourceLoader.hpp>
#include <Nexus\Exception.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus
{
ResourceLoader::ResourceLoader(const int& resourceID) : mResource(NULL), mMemory(NULL), mSize(0), mData(NULL), mResourceID(resourceID)
{
#ifdef __NEXUS_OS_WINDOWS__
  if ( mResource = FindResource(NULL, MAKEINTRESOURCE(mResourceID), RT_RCDATA); mResource )
  {
    if ( mMemory = LoadResource(NULL, mResource); mMemory )
    {
      mSize = SizeofResource(NULL, mResource);
      mData = LockResource(mMemory);

      DebugWriter().Write("ResourceLoader: Loaded resource %d.\n", mResourceID);
    }
    else
    {
      throw Exception("ResourceLoader Error: Failed to load resouce %d.\n", mResourceID);
    }
  }
  else
  {
    throw Exception("ResourceLoader Error: Failed to find resource %d.\n", mResourceID);
  }
#endif
}

ResourceLoader::~ResourceLoader() noexcept
{
#ifdef __NEXUS_OS_WINDOWS__
  if ( mResource )
  {
    UnlockResource(mMemory);
    FreeResource(mResource);
  }
#endif

  DebugWriter().Write("ResourceLoader: Freed resource %d.\n", mResourceID);
}

const size_t& ResourceLoader::GetSize() const noexcept
{
  return mSize;
}

const void* ResourceLoader::GetData() const noexcept
{
  return mData;
}

const int& ResourceLoader::GetResourceID() const noexcept
{
  return mResourceID;
}
}

// End of Source\Nexus\ResourceLoader.cpp
