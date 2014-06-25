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
#include <boost/regex.hpp>
#include <boost/algorithm/string/predicate.hpp>

#include <7z_ogre_archive.h>


namespace Ogre
{
	namespace Plugin7z
	{
		Archive7z::Archive7z(const String& name, const String& archType) : 
			Archive(name, archType)
		{}

		Archive7z::~Archive7z()
		{}

		void Archive7z::load()
		{

		}

		void Archive7z::unload()
		{

		}

		DataStreamPtr Archive7z::open(const String& filename, bool readOnly) const
		{
			MemoryDataStreamPtr uncompressedStream(
				OGRE_NEW_T(MemoryDataStream, MEMCATEGORY_GENERAL)(NULL, 0, false, true), SPFM_DELETE_T);
			return uncompressedStream;
		}


		StringVectorPtr Archive7z::list(bool recursive, bool dirs)
		{
			StringVectorPtr ret(OGRE_NEW_T(StringVector, MEMCATEGORY_GENERAL)(), SPFM_DELETE_T);

			index_match_t match = findMatchIndexes("*", recursive, dirs);
			for(size_t i = 0; i < match.size(); ++i)
				ret.getPointer()->push_back(match[i].fullName);

			return ret;
		}

		FileInfoListPtr Archive7z::listFileInfo(bool recursive, bool dirs)
		{
			FileInfoListPtr ret(OGRE_NEW_T(FileInfoList, MEMCATEGORY_GENERAL)(), SPFM_DELETE_T);
			return ret;
		}

		StringVectorPtr Archive7z::find(const String& pattern, bool recursive, bool dirs)
		{
			StringVectorPtr ret(OGRE_NEW_T(StringVector, MEMCATEGORY_GENERAL)(), SPFM_DELETE_T);

			index_match_t match = findMatchIndexes(pattern, recursive, dirs);
			for(size_t i = 0; i < match.size(); ++i)
				ret.getPointer()->push_back(match[i].fullName);

			return ret;
		}

		bool Archive7z::exists(const String& filename)
		{
			return mFileIndex.find(filename) != mFileIndex.end();
		}

		time_t Archive7z::getModifiedTime(const String& filename)
		{
			return 0;
		}

		FileInfoListPtr Archive7z::findFileInfo(const String& pattern, 
			bool recursive, bool dirs) const
		{
			FileInfoListPtr ret(OGRE_NEW_T(FileInfoList, MEMCATEGORY_GENERAL)(), SPFM_DELETE_T);
			return ret;
		}

		Archive7z::index_match_t Archive7z::findMatchIndexes(const String& pattern,
			bool recursive, bool dirs)
		{
			index_match_t res;

			file_index_t::iterator it = mFileIndex.begin();
			boost::regex expr(pattern);

			for(; it != mFileIndex.end(); ++it)
			{
				if(!recursive && boost::algorithm::contains(it->first, "/"))
					continue;

				if(!dirs && m7zdb.db.Files[it->second].IsDir)
					continue;

				if(boost::regex_match(it->first, expr))
					res.push_back(file_index_value_t(*it));
			}

			return res;
		}
	}
}