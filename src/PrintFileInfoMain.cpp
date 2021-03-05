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

#include <stdlib.h>
#include <iostream>
#include <functional>
#include <string.h>
#include "FileInfo.h"
#include "PrintFileInfo.h"

const char CSV_FLAG[] = "-csv";

typedef std::function<void(const char*, const FileInfoLib::FileInfo&)> PrintFn;


inline void printUsageMessage()
{
    std::cerr << "usage: PrintFileInfo [" << CSV_FLAG
        << "] file1 [file2 [file3..]]" << std::endl;
}


// Return function (lambda expression) to use when printing output
// in CSV format.
inline PrintFn getPrintCsvFn()
{
    return [] (const char* path, const FileInfoLib::FileInfo& fileInfo) {
        printFileInfoCSV(path, fileInfo);
    };
}


// Return function (lambda expression) to use when printing output
// in human-readable text format.
inline PrintFn getPrintTxtFn()
{
    return [] (const char* path, const FileInfoLib::FileInfo& fileInfo) {
        printFileInfo(path, fileInfo);
    };
}


int main(int argc, char* argv[])
{
    // Check that at least one argument supplied.
    if(argc < 2) {
        printUsageMessage();
        return 1;
    }

    // function for printing the output.
    PrintFn pr;
    if (strcasecmp(argv[1], CSV_FLAG) == 0) {
        argc--;
        argv++;
        if(argc < 2) {
            printUsageMessage();
            return 1;
        }
        // Use function that prints output in CSV format.
        pr = getPrintCsvFn();

       FileInfoLib::printCSVHeader();
    }
    else {
        // Use function that prints output in human-readable text
        // format.
        pr = getPrintTxtFn();
    }

    int retCode = 0;
    for (int i = 1; i < argc; i++) {
        FileInfoLib::FileInfo fileInfo(argv[i]);
        pr(argv[i], fileInfo);
        if (fileInfo.isErrorDetected()) {
            retCode = 1;
        }
    }
    return retCode;
}

