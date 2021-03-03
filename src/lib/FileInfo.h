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

#ifndef FILEINFO_H_
#define FILEINFO_H_

#include <string>


namespace FileInfoLib {

    enum FileType {
        RegularFile,
        Directory,
        Other
    };

    class FileInfo {
        // Stores file related statistics (at present time last
        // modified, size in bytes and whether file exists).
    public:
        FileInfo(const char* path);

        bool fileExists() const {return exists;}

        FileType getFileType() const {return fileType;};

        time_t getLastModifiedTime() const {return lastModifiedTime;}

        off_t getSizeInBytes() const {return sizeInBytes;}

        // If following method returns true then results of above methods
        // are not defined.
        bool isErrorDetected() const {return errorDetected;}
        const char* getErrorMessage() const {return errorMessage.c_str();}
    private:
        bool exists;

        FileType fileType;

        time_t lastModifiedTime;
        off_t sizeInBytes;

        bool errorDetected;
        std::string errorMessage;
    };

    std::string fileInfoToCSV(const FileInfo& fileInfo);

    std::string fileTypeToString(FileType fileType);

}

#endif // FILEINFO_H_
