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

#ifndef CMPLASTMODIFIED_H_
#define CMPLASTMODIFIED_H_

namespace CmpLastModified {

    enum Result {
        FIRST_EARLIER = 1,
        SAME_TIME = 2,
        FIRST_LATER = 3,
        ERROR = 4
    };

    const char VERBOSE_FLAG[] = "-v";

    Result cmpLastModified(
        const char* path1, const char* path2, bool verbose);

}

#endif // CMPLASTMODIFIED_H_

 