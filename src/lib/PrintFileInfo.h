/*
    Copyright 2021 Philip Mortimer
    
    This file is part of Philip Mortimer Example Programs.
    Philip Mortimer Example Programs is free software: you can redistribute it 
    and/or modify it under the terms of the GNU General Public License as 
    published by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    Philip Mortimer Example Programs is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Philip Mortimer Example Programs.  If not, see 
    <https://www.gnu.org/licenses/>.
*/

#ifndef FILEINFOPRINTLIB_H_
#define FILEINFOPRINTLIB_H_ 

#include <iostream>
#include "FileInfo.h"


namespace FileInfoLib {

    static const char INDENT[] = "    ";

    static const char CSV_HEADER[] =
        "File path,File exists,File type,Last modified,Size in bytes,Error message";


    void printFileInfo(
        const FileInfo& fileInfo, std::ostream& dest, const char* indent);


    inline void printCSVHeader(std::ostream& dest = std::cout)
    {
        dest << CSV_HEADER << std::endl;
    }


    inline void printFileInfo(
        const char* path, const FileInfo& fileInfo, 
        std::ostream& dest = std::cout)
    {
        dest << path << ":\n";
        printFileInfo(fileInfo, dest, INDENT);
    }


    inline void printFileInfoCSV(
        const char* path, const FileInfo& fileInfo, 
        std::ostream& dest = std::cout)
    {
        dest << path << "," << fileInfoToCSV(fileInfo) << std::endl;
    }

}

#endif // FILEINFOPRINTLIB_H_
 
