// Created on: 2007-09-04
// Created by: Andrey BETENEV
// Copyright (c) 2007-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and / or modify it
// under the terms of the GNU Lesser General Public version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

//! @file
//! Implementation of some atomic operations (elementary operations
//! with data that cannot be interrupted by parallel threads in the
//! multithread process) on various platforms
//!
//! By the moment, only operations necessary for reference counter
//! in Standard_Transient objects are implemented.
//!
//! This is preffered to use fixed size types "int32_t" / "int64_t" for
//! correct function declarations however we leave "int" assuming it is 32bits for now.

#ifndef _Standard_Atomic_HeaderFile
#define _Standard_Atomic_HeaderFile

#include <Standard_Macro.hxx>

//! Increments atomically integer variable pointed by theValue
//! and returns resulting incremented value.
inline int Standard_Atomic_Increment (volatile int* theValue);

//! Decrements atomically integer variable pointed by theValue
//! and returns resulting decremented value.
inline int Standard_Atomic_Decrement (volatile int* theValue);

// Platform-dependent implementation
#if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
// gcc explicitly defines the macros __GCC_HAVE_SYNC_COMPARE_AND_SWAP_*
// starting with version 4.4+, although built-in functions
// are available since 4.1.x. However unless __GCC_HAVE_SYNC_COMPARE_AND_SWAP_*
// are defined, linking may fail without specifying -march option when
// building for 32bit architecture on 64bit (using -m32 option). To avoid
// making -march mandatory, check for __GCC_HAVE_SYNC_COMPARE_AND_SWAP_* is
// enforced.

int Standard_Atomic_Increment (volatile int* theValue)
{
  return __sync_add_and_fetch (theValue, 1);
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return __sync_sub_and_fetch (theValue, 1);
}

#elif (defined(_WIN32) || defined(__WIN32__))
  #ifdef _MSC_VER
    extern "C" {
      long _InterlockedIncrement(long volatile* lpAddend);
      long _InterlockedDecrement(long volatile* lpAddend);
    }
  #else
    extern "C" {
      Standard_IMPORT long __stdcall InterlockedIncrement ( long volatile *lpAddend);
      Standard_IMPORT long __stdcall InterlockedDecrement ( long volatile *lpAddend);
    }
    #define _InterlockedIncrement InterlockedIncrement
    #define _InterlockedDecrement InterlockedDecrement
  #endif

// WinAPI function or MSVC intrinsic
// Note that we safely cast int* to long*, as they have same size and endian-ness

int Standard_Atomic_Increment (volatile int* theValue)
{
  return _InterlockedIncrement (reinterpret_cast<volatile long*>(theValue));
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return _InterlockedDecrement (reinterpret_cast<volatile long*>(theValue));
}

#elif defined(__APPLE__)
// use atomic operations provided by MacOS

#include <libkern/OSAtomic.h>

int Standard_Atomic_Increment (volatile int* theValue)
{
  return OSAtomicIncrement32Barrier (theValue);
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return OSAtomicDecrement32Barrier (theValue);
}

#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64))
// use x86 / x86_64 inline assembly (compatibility with alien compilers / old GCC)

inline int Standard_Atomic_Add (volatile int* theValue, int theVal)
{
  // C equivalent:
  // *theValue += theVal;
  // return *theValue;

  int previous;
  __asm__ __volatile__
  (
    "lock xadd %0,%1"
  : "=q"(previous), "=m"(*theValue) //output
  : "0"(theVal), "m"(*theValue) //input
  : "memory" //clobbers
  );
  return previous + theVal;
}

int Standard_Atomic_Increment (volatile int* theValue)
{
  return Standard_Atomic_Add (theValue, 1);
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return Standard_Atomic_Add (theValue, -1);
}

#elif defined(__hpux) && defined(HAVE_ATOMIC_H)
//on hpux please install 'HP-UX Atomic APIs' bundle

#include <atomic.h>

int Standard_Atomic_Increment (volatile int* theValue)
{
  return atomic_inc_32(theValue);
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return atomic_dec_32 (theValue);
}

#else

#ifndef IGNORE_NO_ATOMICS
  #error "Atomic operation isn't implemented for current platform!"
#endif
int Standard_Atomic_Increment (volatile int* theValue)
{
  return ++(*theValue);
}

int Standard_Atomic_Decrement (volatile int* theValue)
{
  return --(*theValue);
}

#endif

#endif //_Standard_Atomic_HeaderFile
