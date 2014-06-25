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
#include <7z_ogre_plugin.h>


Ogre::Plugin7z::Plugin7zArchiver *g7zPlugin;

extern "C" void PLUGIN_EXPORT dllStartPlugin(void)
{
	g7zPlugin = OGRE_NEW Ogre::Plugin7z::Plugin7zArchiver();
	Ogre::Root::getSingleton().installPlugin(g7zPlugin);
}

extern "C" void PLUGIN_EXPORT dllStopPlugin(void)
{
	Ogre::Root::getSingleton().uninstallPlugin(g7zPlugin);
	OGRE_DELETE g7zPlugin;
}

