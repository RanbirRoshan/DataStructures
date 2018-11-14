

#ifndef ENVIRONMENT_HPP

#define ENVIRONMENT_HPP

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif

#include "Windows.h"

#endif

// Check GCC
#ifdef  __linux__

#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif

#include <cstdlib>
#include <cstring>

typedef __int64_t __int64;
typedef __int32_t __int32;
typedef char byte;

using namespace std;
#endif

#ifdef ENVIRONMENT64

#ifdef __linux__
typedef __int64_t Offset;
#else
typedef __int64 Offset;
#endif
//#define Offset __int64

#endif

#ifdef ENVIRONMENT32

#ifdef __linux__
typedef __int32_t  Offset;
#else
typedef __int32 Offset;
#endif
//#define Offset __int32

#endif


//#include <TCHAR.H>

#endif // !ENVIRONMENT_HPP
