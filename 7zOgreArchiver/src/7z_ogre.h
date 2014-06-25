/********************************************************************************* 
*	This file is part of 7zip Ogre Plugin
*	Copyright (C) 2014  Sirius (Vdov Nikita)
*
*	Foobar is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*
*	Foobar is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************************/
#pragma once 

#ifdef _MSC_VER
/* disable some warnings */
#pragma warning(disable:4251 4275 4193)
#endif

/*********************************************************************************
*	OGRE (www.ogre3d.org) is made available under the MIT License.
*
*	Copyright (c) 2000-2012 Torus Knot Software Ltd
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in
*	all copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*	THE SOFTWARE.
**********************************************************************************/

#include <Ogre.h>
#include <OgrePlugin.h>
#include <OgreArchive.h>
#include <OgreArchiveFactory.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#	ifdef MAKE_DLL
#		define PLUGIN_EXPORT __declspec(dllexport)
#	else 
#		define PLUGIN_EXPORT __declspec(dllimport)
#	endif

#else 

#	define PLUGIN_EXPORT

#endif