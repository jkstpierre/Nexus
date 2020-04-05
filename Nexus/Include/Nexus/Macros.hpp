/// File: Include\Nexus\Macros.hpp.
///
/// Summary:  A suite of macros for miscellaneous purposes.

#ifndef __NEXUS_MACROS_HPP__
#define __NEXUS_MACROS_HPP__

/// Summary:  Determine OS.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define __NEXUS_OS_WINDOWS__
#elif __APPLE__
#define __NEXUS_OS_APPLE__
#elif defined(__linux__) || defined(__unix__) || defined (_POSIX_VERSION)
#define __NEXUS_OS_UNIX__
#endif

#endif

// End of Include\Nexus\Macros.hpp
