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

#include <sstream>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "DateTime.h"
#include "FileInfo.h"

using DateTime::createDateTimeString;


namespace FileInfoLib {

    std::string createErrorMessage(const char* path, int err_code)
    {
        std::stringstream stream;
        stream << "cannot get stats for " << path
            << " - error code is " << err_code << std::flush;

        return stream.str();
    }


    FileInfo::FileInfo(const char* path) :
        errorDetected(false)
    {
        struct stat info;
        int result;

        // Get file stats for path.
        result = stat(path, &info);
        if (result == 0) {
            // Obtained stats successfully.
            exists = true;

            lastModifiedTime = info.st_mtime;
            sizeInBytes = info.st_size;

            if (S_ISREG(info.st_mode) != 0) {
                fileType = FileType::RegularFile;
            }
            else if ((S_IFDIR & info.st_mode) != 0) {
                fileType = FileType::Directory;
            }
            else {
                fileType = FileType::Other;
            }
        }
        else if (errno == ENOENT) {
            exists = false;
        }
        else {
            // Failed to get stats.
            errorDetected = true;
            errorMessage = createErrorMessage(path, errno);
        }
    } 


    std::string fileInfoToCSV(const FileInfo& fileInfo)
    {
        std::stringstream dest;
        if (fileInfo.isErrorDetected()) {
            dest << ",,,," << fileInfo.getErrorMessage() << std::flush;
            return dest.str();
        }

        if (fileInfo.fileExists()) {
            dest << "Y,";
        }
        else {
            dest << "N,,,," << std::flush;
            return dest.str();
        }

        dest << fileTypeToString(fileInfo.getFileType()) << ",";
        
        dest << "\"" << createDateTimeString(fileInfo.getLastModifiedTime())
            << "\",";

        if (fileInfo.getFileType() == FileType::RegularFile) {
            dest << fileInfo.getSizeInBytes();
        }

        dest << "," << std::flush;
        return dest.str();
    }


    std::string fileTypeToString(FileType fileType)
    {
        switch (fileType)
        {
            case FileType::RegularFile: {
                return "Regular File";
            }
            case FileType::Directory: {
                return "Directory";
            }
            default: {
                return "Other than regular file or directory";
            }
        }
    }

}
