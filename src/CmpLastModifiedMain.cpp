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
#include <string.h>
#include "CmpLastModified.h"


using CmpLastModified::VERBOSE_FLAG;
using CmpLastModified::Result;
using CmpLastModified::cmpLastModified;


inline void printUsageMessage()
{
    std::cerr << "usage: CmpLastModified [" << VERBOSE_FLAG << "] file1 file2"
        << "\n    use "  << VERBOSE_FLAG << " for verbose output"
        << std::endl;
}


int main(int argc, char* argv[])
{
    // Check that at least one argument supplied.
    if (argc < 2) {
        printUsageMessage();
        return Result::ERROR;
    }

    // Check whether 1st argument is verbose argument.
    bool verbose = false;
    if (strcasecmp(argv[1], VERBOSE_FLAG) == 0) {
        verbose = true;
        argc--;
        argv++;
    }

    // Check that correct number of file arguments supplied.
    if (argc != 3) {
        if (verbose) {
            std::cout << "2 file paths required, " << (argc - 1)
                << " arguments supplied" << std::endl;
        }
        printUsageMessage();
        return Result::ERROR;
    }

    Result result = cmpLastModified(argv[1], argv[2], verbose);
    if (verbose) {
        std::cout << "result code is " << result << std::endl;
    }
    return result;
}

