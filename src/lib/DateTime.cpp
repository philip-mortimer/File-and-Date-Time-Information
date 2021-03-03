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

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "DateTime.h"


namespace DateTime {

    std::string createDateTimeString(time_t rawTime)
    {
        const int BUF_LEN = 200;
        char buf[BUF_LEN];

        struct tm* timePtr = localtime(&rawTime);
        strftime(buf, BUF_LEN, "%a, %d-%b-%Y - %I:%M:%S %p", timePtr);

        return std::string(buf);
    }

}
