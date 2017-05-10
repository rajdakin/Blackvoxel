/*
 * This file is part of Blackvoxel.
 *
 * Copyright 2010-2014 Laurent Thiebaut & Olivia Merle
 *
 * Blackvoxel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Blackvoxel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
 * ACompileSettings.h
 *
 *  Created on: 21 nov. 2011
 *      Author: laurent
 */

#ifndef A_COMPILESETTINGS_H
#define A_COMPILESETTINGS_H

//#ifndef A_COMPILESETTINGS_H
//#  include "ACompileSettings.h"
//#endif

// Options à inclure : -mfpmath=sse -msse2

#define DEVELOPPEMENT_FORCE_DEV 0 // If you are making development, set it to 1

// Dev options forced ?

#if DEVELOPPEMENT_FORCE_DEV == 1
	#undef DEVELOPPEMENT_ON
	#define DEVELOPPEMENT_ON 1
#endif

#ifndef DEVELOPPEMENT_ON
	#define DEVELOPPEMENT_ON 0
#endif

#ifndef COMPILEOPTION_DEMO
	#  define COMPILEOPTION_DEMO 0
	#endif
#define COMPILEOPTION_VERSIONNUM 201

// Options du jeu

#define COMPILEOPTION_ALLOWSTARTINGSTORAGE 0 // Allow starting storage to be present. Never introduced in the game.
#define COMPILEOPTION_ALLOWJUMPANDBUILD 1 // Jump and build allow building when floating in the air (Like when jumping).


#if DEVELOPPEMENT_ON == 0
	#define COMPILEOPTION_INVENTORY_DEMOCONTENT 0
	#define COMPILEOPTION_ALLOWSAVE 1
	#define COMPILEOPTION_ALLOWSAVEPLAYERSTATE 1
	#define COMPILEOPTION_ALLOWVEHICLE 1
	#define COMPILEOPTION_VERSIONSTRING "VERSION 3.01.01 (c) 2017 LAURENT THIEBAUT & OLIVIA MERLE"
#else
	#define COMPILEOPTION_INVENTORY_DEMOCONTENT 0
	#define COMPILEOPTION_ALLOWSAVE 1
	#define COMPILEOPTION_ALLOWSAVEPLAYERSTATE 1
	#define COMPILEOPTION_ALLOWVEHICLE 1
	#define COMPILEOPTION_VERSIONSTRING "VERSION 3.01.01 : CONFIDENTIAL TESTING (c) LAURENT THIEBAUT & OLIVIA MERLE"
#endif

// Options de debogage

#if DEVELOPPEMENT_ON == 1
#  define COMPILEOPTION_FABDATABASEOUTPUT 1
#  define COMPILEOPTION_BOUNDCHECKING 1
#  define COMPILEOPTION_BOUNDCHECKINGSLOW 1
#  define COMPILEOPTION_FALLAREFATALS 1
#  define COMPILEOPTION_FINETIMINGTRACKING 0
#  define COMPILEOPTION_DEBUGFACILITY 1
#  define COMPILEOPTION_NOMOUSECAPTURE 0
#  define COMPILEOPTION_VOXELPROCESSOR 1
#  define COMPILEOPTION_DONTEMPTYINVENTORYONDEATH 1
#  define COMPILEOPTION_ALPHA_SOUNDS_1 1
#  define COMPILEOPTION_FNX_SOUNDS_1 1
#  define COMPILEOPTION_LOWRESTEXTURING 0
#  define COMPILEOPTION_ANISOTROPICTEXTURINGLEVEL 8
#  ifdef PANDORA
#    undef COMPILEOPTION_LOWRESTEXTURING
#    define COMPILEOPTION_LOWRESTEXTURING 2
#  endif
#  define COMPILEOPTION_VERBOSELOGS 1
#  define COMPILEOPTION_SQUIRRELUNSAFE 1
#  define COMPILEOPTION_SAVEONLYMODIFIED 1
#  define COMPILEOPTION_VOXELSIZEFACTOR 1.0
#  define COMPILEOPTION_EXPERIMENTAL_POOLED_EXTENSIONS 1
#  define COMPILEOPTION_FORCE_SORTED_RENDERING 1
#  define COMPILEOPTION_ADD_MIDLOOP_PHYSIC_ITERATION 1
#  define COMPILEOPTION_HELP_SCREEN 0
#else
#  define COMPILEOPTION_FABDATABASEOUTPUT 0
#  define COMPILEOPTION_BOUNDCHECKING 0
#  define COMPILEOPTION_BOUNDCHECKINGSLOW 0
#  define COMPILEOPTION_FALLAREFATALS 1
#  define COMPILEOPTION_FINETIMINGTRACKING 0
#  define COMPILEOPTION_DEBUGFACILITY 0
#  define COMPILEOPTION_NOMOUSECAPTURE 0
#  define COMPILEOPTION_VOXELPROCESSOR 1
#  define COMPILEOPTION_DONTEMPTYINVENTORYONDEATH 1
#  define COMPILEOPTION_ALPHA_SOUNDS_1 1
#  define COMPILEOPTION_FNX_SOUNDS_1 1
#  define COMPILEOPTION_LOWRESTEXTURING 0
#  define COMPILEOPTION_ANISOTROPICTEXTURINGLEVEL 8
#  ifdef PANDORA 
#    undef COMPILEOPTION_LOWRESTEXTURING
#    define COMPILEOPTION_LOWRESTEXTURING 2
#  endif
#  define COMPILEOPTION_VERBOSELOGS 1
#  define COMPILEOPTION_SQUIRRELUNSAFE 1
#  define COMPILEOPTION_SAVEONLYMODIFIED 1
#  define COMPILEOPTION_VOXELSIZEFACTOR 1.0
#  define COMPILEOPTION_EXPERIMENTAL_POOLED_EXTENSIONS 1
#  define COMPILEOPTION_FORCE_SORTED_RENDERING 0
#  define COMPILEOPTION_ADD_MIDLOOP_PHYSIC_ITERATION 0
#  define COMPILEOPTION_HELP_SCREEN 0
#endif

// Plateformes

// Linux

#ifdef __linux__
//	#define COMPILEOPTION_SAVEFOLDERNAME "Blackvoxel"
//	#define COMPILEOPTION_USEHOMEDIRSTORAGE 1
	#define COMPILEOPTION_WINXPTIMECOMPUTING 0

//	#if DEVELOPPEMENT_ON == 1
//		#define COMPILEOPTION_DATAFILESPATH ""
//	#else
//		#ifndef COMPILEOPTION_DATAFILESPATH
//			#define COMPILEOPTION_DATAFILESPATH "/usr/share/blackvoxel"
//		#endif
//	#endif

// Windows Win32

#elif _WIN32

//	#define COMPILEOPTION_SAVEFOLDERNAME "Blackvoxel"
//	#define COMPILEOPTION_USEHOMEDIRSTORAGE 1
//	#define COMPILEOPTION_DATAFILESPATH ""
	#define COMPILEOPTION_WINXPTIMECOMPUTING 1

#endif

// *************** RASPBERRY PI 2/3 SPECIAL SUPPORT *************************

// At this time, Raspberry PI setting will be enforced automatically for any ARM CPU device.
// This is a shortcut, but at this time, most of these platforms have very limited horsepower and
// this profile is a good base for these devices.

#ifdef __arm__
#define COMPILEOPTION_PLATFORM_RASPBERRY_PI 1
#endif

#ifndef COMPILEOPTION_PLATFORM_RASPBERRY_PI
#define COMPILEOPTION_PLATFORM_RASPBERRY_PI 0
#elif COMPILEOPTION_PLATFORM_RASPBERRY_PI ==1
// RPI Specific options
  #ifndef PANDORA
    #undef COMPILEOPTION_LOWRESTEXTURING
    #define COMPILEOPTION_LOWRESTEXTURING 1
  #endif
  #undef COMPILEOPTION_FORCE_SORTED_RENDERING
  #define COMPILEOPTION_FORCE_SORTED_RENDERING 1
  #undef COMPILEOPTION_ADD_MIDLOOP_PHYSIC_ITERATION
  #define COMPILEOPTION_ADD_MIDLOOP_PHYSIC_ITERATION 1
  #undef COMPILEOPTION_ANISOTROPICTEXTURINGLEVEL
  #define COMPILEOPTION_ANISOTROPICTEXTURINGLEVEL 0

#endif

// End Raspberry pi

#ifndef COMPILEOPTION_DATAFILESPATH
	#error "COMPILEOPTION_DATAFILESPATH is not defined!"
#endif
#ifndef COMPILEOPTION_SAVEFOLDERNAME
	#error "COMPILEOPTION_SAVEFOLDERNAME is not defined!"
#endif
#ifndef COMPILEOPTION_USEHOMEDIRSTORAGE
	#error "COMPILEOPTION_USEHOMEDIRSTORAGE is not defined!"
#endif

#endif /* A_COMPILESETTINGS_H */
