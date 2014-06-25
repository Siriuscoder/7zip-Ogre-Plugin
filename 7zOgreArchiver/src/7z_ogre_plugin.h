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

#include <7z_ogre_archive.h>

namespace Ogre
{
	namespace Plugin7z
	{
		class Plugin7zArchiver : public Plugin
		{
		public:
			Plugin7zArchiver();
			virtual ~Plugin7zArchiver();

			/** Get the name of the plugin. 
			@remarks An implementation must be supplied for this method to uniquely
				identify the plugin.
			*/
			virtual const String& getName() const;

			/** Perform the plugin initial installation sequence. 
			@remarks An implementation must be supplied for this method. It must perform
			the startup tasks necessary to install any rendersystem customisations 
			or anything else that is not dependent on system initialisation, ie
			only dependent on the core of Ogre. It must not perform any
			operations that would create rendersystem-specific objects at this stage,
			that should be done in initialise().
			*/
			virtual void install();

			/** Perform any tasks the plugin needs to perform on full system
				initialisation.
			@remarks An implementation must be supplied for this method. It is called 
				just after the system is fully initialised (either after Root::initialise
				if a window is created then, or after the first window is created)
				and therefore all rendersystem functionality is available at this
				time. You can use this hook to create any resources which are 
				dependent on a rendersystem or have rendersystem-specific implementations.
			*/
			virtual void initialise();

			/** Perform any tasks the plugin needs to perform when the system is shut down.
			@remarks An implementation must be supplied for this method.
			This method is called just before key parts of the system are unloaded, 
			such as rendersystems being shut down. You should use this hook to free up 
			resources and decouple custom objects from the OGRE system, whilst all the
			instances of other plugins (e.g. rendersystems) still exist.
			*/
			virtual void shutdown();

			/** Perform the final plugin uninstallation sequence. 
			@remarks An implementation must be supplied for this method. It must perform
			the cleanup tasks which haven't already been performed in shutdown()
			(e.g. final deletion of custom instances, if you kept them around incase
			the system was reinitialised). At this stage you cannot be sure what other
			plugins are still loaded or active. It must therefore not perform any
			operations that would reference any rendersystem-specific objects - those
			should have been sorted out in the 'shutdown' method.
			*/
			virtual void uninstall();

		private:

			String mPluginName;
		};
	}
}