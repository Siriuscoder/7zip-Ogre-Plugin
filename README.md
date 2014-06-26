7zip-Ogre-Plugin
================

![](http://www.ogre3d.org/docs/api/1.9/ogre-logo-wetfloor.gif "Ogre")

About
-----
This library provides functionaly for loading files from 7z archives. Libraty implements OGRE plugin interface, and it can be loaded by OGRE directly. Library also implements Ogre::Archive interface in order to OGRE resource manager could open various resource files in the same way as it do this with filesystem. 

There are many diferent compression algorithm is supported by 7z archiver, see [here](http://www.7-zip.org/7z.html "7z"), but this plugin was designed to support only LZMA and LZMA2 algorithms. This algorithms have a excellent speed and compress characteristics.

Dependencies
------------

Compiling
---------

How to use
----------
