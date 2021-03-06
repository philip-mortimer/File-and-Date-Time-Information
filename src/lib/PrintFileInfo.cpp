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

#include <iostream> 
#include <string>
#include <algorithm>
#include "DateTime.h"
#include "FileInfo.h" 
#include "PrintFileInfo.h" 

using DateTime::createDateTimeString;


namespace FileInfoLib {

    std::string createCommaNumStr(unsigned long n)
    // Return a string representation of n with 3 digit sequences
    // separated by commas e.g. "1,978,802".
    {
        if (n == 0) {
            return "0";
        }
        std::string num_str = "";
        char buf[2];

        unsigned long num = n;
        int digit_count = 0;
        while (num > 0) {
            snprintf(buf, sizeof(buf), "%0u", (unsigned int)(num % 10));
            num_str.push_back(buf[0]);
            num /= 10;
            digit_count++;
            if ((digit_count % 3 == 0) && (num > 0)) {
                num_str.push_back(',');
            }
        }
        reverse(num_str.begin(), num_str.end());
        return num_str;
    }


    void printFileInfo(
        const FileInfo& fileInfo, std::ostream& dest, const char* indent)
    {
        if (fileInfo.isErrorDetected()) {
            dest << indent << fileInfo.getErrorMessage() << std::endl;
            return;
        }
        
        if (! fileInfo.fileExists()) {
            dest << indent << "does not exist" << std::endl;
            return;
        }

        dest << indent << "file type: " 
            << fileTypeToString(fileInfo.getFileType()) << std::endl;
        
        dest << indent << "last modified: " 
            << createDateTimeString(fileInfo.getLastModifiedTime()) 
            << std::endl;
        
        if (fileInfo.getFileType() == FileType::RegularFile) {
            dest << indent << "size in bytes: " 
                << createCommaNumStr(fileInfo.getSizeInBytes()) << std::endl;
        }
    }

}