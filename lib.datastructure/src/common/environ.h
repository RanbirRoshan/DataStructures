

#ifndef ENVIRONMENT_HPP

#define ENVIRONMENT_HPP

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#ifdef ENVIRONMENT64

#define Offset __int64

#endif

#ifdef ENVIRONMENT32

#define Offset __int32

#endif

#endif // !ENVIRONMENT_HPP
