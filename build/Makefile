
#   Copyright 2021 Philip Mortimer
#
#   This file is part of Philip Mortimer Example Programs.
#   Philip Mortimer Example Programs is free software: you can redistribute it 
#   and/or modify it under the terms of the GNU General Public License as 
#   published by the Free Software Foundation, either version 3 of the License,
#   or (at your option) any later version.
#
#   Philip Mortimer Example Programs is distributed in the hope that it will be
#   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with Philip Mortimer Example Programs.  If not, see 
#   <https://www.gnu.org/licenses/>.

CXX=g++

SRC_FOLDER=../src
LIB_FOLDER=$(SRC_FOLDER)/lib
CXXFLAGS=-Wall -Wextra -I$(LIB_FOLDER)
VPATH=.:$(SRC_FOLDER):$(LIB_FOLDER)

ifeq ($(OS), Windows_NT)
    CMP_LAST_MODIFIED_EXE=CmpLastModified.exe
    PRINT_FILE_INFO_EXE=PrintFileInfo.exe
    CURR_DATE_TIME_EXE=CurrDateTime.exe

    CLEAN_CMD=echo 'clean' action not currently implemented
    #CLEAN_CMD=del *.o
else
    CMP_LAST_MODIFIED_EXE=CmpLastModified
    PRINT_FILE_INFO_EXE=PrintFileInfo
    CURR_DATE_TIME_EXE=CurrDateTime

    CLEAN_CMD=echo 'clean' action not currently implemented
    #CLEAN_CMD=rm *.o
endif

CMP_LAST_MODIFIED_EXE_PATH=../CmpLastModified/$(CMP_LAST_MODIFIED_EXE)
PRINT_FILE_INFO_EXE_PATH=../PrintFileInfo/$(PRINT_FILE_INFO_EXE)
CURR_DATE_TIME_EXE_PATH=../CurrDateTime/$(CURR_DATE_TIME_EXE)

.PHONY: all
all: CmpLastModified PrintFileInfo CurrDateTime

.PHONY: CmpLastModified
CmpLastModified: $(CMP_LAST_MODIFIED_EXE_PATH)

.PHONY: PrintFileInfo
PrintFileInfo: $(PRINT_FILE_INFO_EXE_PATH)

.PHONY: CurrentDateTime
CurrDateTime: $(CURR_DATE_TIME_EXE_PATH)


$(CMP_LAST_MODIFIED_EXE_PATH): CmpLastModifiedMain.o CmpLastModified.o FileInfo.o PrintFileInfo.o DateTime.o
	$(CXX) -o $@ $^

$(PRINT_FILE_INFO_EXE_PATH): PrintFileInfoMain.o FileInfo.o PrintFileInfo.o DateTime.o
	$(CXX) -o $@ $^

$(CURR_DATE_TIME_EXE_PATH): CurrDateTimeMain.o DateTime.o
	$(CXX) -o $@ $^


CmpLastModifiedMain.o: CmpLastModifiedMain.cpp CmpLastModified.h

CurrDateTimeMain.o: CurrDateTimeMain.cpp DateTime.h

PrintFileInfoMain.o: PrintFileInfoMain.cpp FileInfo.h PrintFileInfo.h

CmpLastModified.o: CmpLastModified.cpp CmpLastModified.h FileInfo.h PrintFileInfo.h

FileInfo.o: FileInfo.cpp FileInfo.h DateTime.h

PrintFileInfo.o: PrintFileInfo.cpp PrintFileInfo.h FileInfo.h DateTime.h

DateTime.o: DateTime.cpp DateTime.h


.PHONY: clean
clean:
	$(CLEAN_CMD)
