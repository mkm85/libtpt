/*
 * compat.h - Compatibility header
 * 
 * Copyright (C) 2002-2004 Isaac W. Foraker (isaac@tazthecat.net)
 * All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Author nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purpose:
 *	Very few compilers are fully standards compliant.  This header is an
 *	attempt to tweak settings on individual compiler environments to make
 *	standard code more portable.
 *
 */

#ifndef include_compat_h
#define include_compat_h

// Microsoft fixes
#ifdef _MSC_VER

// Disable some annoying MSVC++ warnings.
#	if _MSC_VER <= 1200
// Older version of MSVC do not support throw() declaration
#		pragma warning(disable : 4290)
// This is an annoying warning about legal reference modifiers
#		pragma warning(disable : 4181)
#	endif
// Turn off warnings for long symbol names caused by the STL
#	pragma warning(disable : 4786)

#if _MSC_VER < 1900
#   define snprintf _snprintf
#endif
// Import common standard library functions into the std namespace on Microsoft
// Visual C++ 6 or earlier, but only if not already running with the STLPort
// fix.
#	if _MSC_VER <= 1200 && !defined(_STLP_DO_IMPORT_CSTD_FUNCTIONS)
#		include <cstdio>
#		include <cstdlib>
#		include <cstddef>
#		include <cstring>
#		include <cctype>
#		include <ctime>
#		include <cmath>
#ifdef __cplusplus // Only work for C++ sources
namespace std {
	using ::atoi;	using ::atof;
	using ::isalpha; using ::isdigit; using ::isalnum; using ::isgraph;
	using ::isspace; using ::islower; using ::isupper; using ::isxdigit;
	using ::ispunct; using ::isprint; using ::iscntrl; using ::toupper;
	using ::tolower;
	using ::sprintf; using ::printf; using ::sscanf; using ::scanf;
	using ::exit; using ::abort; using ::getenv; using ::system;
	using ::size_t; using ::time_t; using ::clock_t; using ::ptrdiff_t;
	using ::strlen;	using ::strcmp; using ::strncmp; using ::strcpy;
	using ::strncpy; using ::strchr; using ::strrchr; using ::strstr;
	using ::memset; using ::memcpy; using ::memcmp; using ::malloc;
	using ::free; using ::calloc;
	using ::clock; using ::time; using ::asctime; using ::gmtime;
	using ::localtime;
	using ::abs; using ::acos; using ::asin; using ::atan; using ::atan2;
	using ::ceil; using ::cos; using ::cosh; using ::div; using ::exp;
	using ::fabs; using ::floor; using ::fmod; using ::frexp; using ::labs;
	using ::ldexp; using ::ldiv; using ::log; using ::log10;
	using ::modf; using ::pow; using ::sin; using ::sinh; using ::sqrt;
	using ::tan; using ::tanh;
	using ::fopen; using ::fclose; using ::fgets; using ::fread;
	using ::fwrite; using ::fputs; using ::fgetc; using ::fputc;
	using ::fprintf; using ::fscanf; using ::fgetpos; using ::freopen;
}
#endif // __cplusplus
#	endif
#endif

// Fixes for GCC 2.95.x
#if defined(__GNUC__) && (__GNUC__ < 3)
#	include <ctype.h>

// Get rid of those macros defined in <ctype.h> in lieu of real functions.
#	undef isalnum
#	undef isalpha
#	undef iscntrl
#	undef isdigit
#	undef isgraph
#	undef islower
#	undef isprint
#	undef ispunct
#	undef isspace
#	undef isupper
#	undef isxdigit
#	undef tolower
#	undef toupper

#endif // GCC 295

#endif // include_compat_h
