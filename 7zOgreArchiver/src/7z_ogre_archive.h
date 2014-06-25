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

#include <7z_ogre.h>

#include <7z.h>
#include <7zCrc.h>
#include <7zFile.h>
#include <7zVersion.h>

namespace Ogre
{
	namespace Plugin7z
	{
		class Archive7z : public Archive
		{
		public:

			typedef Ogre::map<String, int32>::type file_index_t;
			typedef struct file_index_value
			{
				String fullName;
				int32 index;

				file_index_value(file_index_t::value_type &pair) :
					fullName(pair.first), index(pair.second)
				{}

				file_index_value() : 
					index(0)
				{}

			} file_index_value_t;

			typedef Ogre::vector<file_index_value_t>::type index_match_t;

		public:

			Archive7z(const String& name, const String& archType);

			virtual ~Archive7z();


			/// Returns whether this archive is case sensitive in the way it matches files
			virtual bool isCaseSensitive(void) const
			{ return false; }

			/** Loads the archive.
			@remarks
			    This initializes all the internal data of the class.
			@warning
			    Do not call this function directly, it is meant to be used
			    only by the ArchiveManager class.
			*/
			virtual void load();

			/** Unloads the archive.
			@warning
			    Do not call this function directly, it is meant to be used
			    only by the ArchiveManager class.
			*/
			virtual void unload();

			/** Open a stream on a given file. 
			@note
			    There is no equivalent 'close' method; the returned stream
			    controls the lifecycle of this file operation.
			@param filename The fully qualified name of the file
			@param readOnly Whether to open the file in read-only mode or not (note, 
				if the archive is read-only then this cannot be set to false)
			@return A shared pointer to a DataStream which can be used to 
			    read / write the file. If the file is not present, returns a null
				shared pointer.
			*/
			virtual DataStreamPtr open(const String& filename, bool readOnly = true) const;

			/** List all file names in the archive.
			@note
			    This method only returns filenames, you can also retrieve other
			    information using listFileInfo.
			@param recursive Whether all paths of the archive are searched (if the 
			    archive has a concept of that)
			@param dirs Set to true if you want the directories to be listed
			    instead of files
			@return A list of filenames matching the criteria, all are fully qualified
			*/
			virtual StringVectorPtr list(bool recursive = true, bool dirs = false);
			
			/** List all files in the archive with accompanying information.
			@param recursive Whether all paths of the archive are searched (if the 
			    archive has a concept of that)
			@param dirs Set to true if you want the directories to be listed
			    instead of files
			@return A list of structures detailing quite a lot of information about
			    all the files in the archive.
			*/
			virtual FileInfoListPtr listFileInfo(bool recursive = true, bool dirs = false);

			/** Find all file or directory names matching a given pattern
			    in this archive.
			@note
			    This method only returns filenames, you can also retrieve other
			    information using findFileInfo.
			@param pattern The pattern to search for; wildcards (*) are allowed
			@param recursive Whether all paths of the archive are searched (if the 
			    archive has a concept of that)
			@param dirs Set to true if you want the directories to be listed
			    instead of files
			@return A list of filenames matching the criteria, all are fully qualified
			*/
			virtual StringVectorPtr find(const String& pattern, bool recursive = true,
			    bool dirs = false);

			/** Find out if the named file exists (note: fully qualified filename required) */
			virtual bool exists(const String& filename);

			/** Retrieve the modification time of a given file */
			virtual time_t getModifiedTime(const String& filename);


			/** Find all files or directories matching a given pattern in this
			    archive and get some detailed information about them.
			@param pattern The pattern to search for; wildcards (*) are allowed
			@param recursive Whether all paths of the archive are searched (if the 
			archive has a concept of that)
			@param dirs Set to true if you want the directories to be listed
			    instead of files
			@return A list of file information structures for all files matching 
			    the criteria.
			*/
			virtual FileInfoListPtr findFileInfo(const String& pattern, 
			    bool recursive = true, bool dirs = false) const;

		protected:

			index_match_t findMatchIndexes(const String& pattern,
				bool recursive, bool dirs);

		private:

			file_index_t mFileIndex;
			CSzArEx m7zdb;
		};
	}
}