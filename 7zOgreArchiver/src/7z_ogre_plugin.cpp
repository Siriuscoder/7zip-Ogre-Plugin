#include <7z_ogre_plugin.h>

namespace Ogre
{
	namespace Plugin7z
	{

		Plugin7zArchiver::Plugin7zArchiver() :
			mPluginName("7zArchiver")
		{}

		Plugin7zArchiver::~Plugin7zArchiver() 
		{}

		const String& Plugin7zArchiver::getName() const
		{ 
			return mPluginName;
		}

		void Plugin7zArchiver::install()
		{

		}

		void Plugin7zArchiver::initialise()
		{

		}

		void Plugin7zArchiver::shutdown()
		{

		}

		void Plugin7zArchiver::uninstall()
		{

		}
	}
}