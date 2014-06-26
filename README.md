7zip-Ogre-Plugin
================

![](http://www.ogre3d.org/docs/api/1.9/ogre-logo-wetfloor.gif "Ogre")

About
-----
This library provides functionaly for loading files from 7z archives. Libraty implements OGRE plugin interface, and it can be loaded by OGRE directly. Library also implements Ogre::Archive interface in order to OGRE resource manager could open various resource files in the same way as it do this with filesystem. 

There are many diferent compression algorithm is supported by 7z archiver, see [here](http://www.7-zip.org/7z.html "7z"), but this plugin was designed to support only LZMA and LZMA2 algorithms. This algorithms have a excellent speed and compress characteristics. And i hope, this plugin will be usefull for develorers, who used ORGE in theirs projects.

Dependencies
------------

1. OGRE (for compiling and using ogre see [here](http://www.ogre3d.org/tikiwiki/tiki-index.php "OGRE wiki") )
2. Boost Regex (see [here](http://www.boost.org/ "Get Boost") )


Compiling
---------

Currently you can compile plugin using VS2009 or later. Do not forget setup OGRE and boost include paths in project or in global paths settings. Linux build support will be later.   

How to use
----------
