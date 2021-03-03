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
#include "FileInfo.h"
#include "PrintFileInfo.h"
#include "CmpLastModified.h"

using FileInfoLib::FileInfo;
using FileInfoLib::printFileInfo;


namespace CmpLastModified {

    Result cmpLastModified(const char* path1, const char* path2, bool verbose)
    {
        FileInfo fs1(path1);
        FileInfo fs2(path2);

        if (verbose) {
            printFileInfo(path1, fs1);
            printFileInfo(path2, fs2);
        }

        if (fs1.isErrorDetected() || fs2.isErrorDetected()) {
            std::cerr << "error detected getting file info" << std::endl;
            return Result::ERROR;
        }

        if ( (! fs1.fileExists()) || (! fs2.fileExists()) ) {
            std::cerr << "both files must exist" << std::endl;
            return Result::ERROR;
        }

        if( fs1.getLastModifiedTime() < fs2.getLastModifiedTime() ) {
            if (verbose) {
                std::cout << "'" << path1 << "' modified earlier than '"
                    << path2 << "'" << std::endl;
            }
            return Result::FIRST_EARLIER;
        }
        else if( fs1.getLastModifiedTime() > fs2.getLastModifiedTime() ) {
            if (verbose) {
                std::cout << "'" << path1 << "' modified later than '"
                    << path2 << "'" << std::endl;
            }
            return Result::FIRST_LATER;
        }
        else {
            if (verbose) {
                std::cout << "'" << path1 << "' at the same time as '"
                    << path2 << "'" << std::endl;
            }
            return Result::SAME_TIME;
        }
    }

}
