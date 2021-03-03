::   Copyright 2021 Philip Mortimer

::   This file is part of Philip Mortimer Example Programs.
::   Philip Mortimer Example Programs is free software: you can redistribute it 
::   and/or modify it under the terms of the GNU General Public License as 
::   published by the Free Software Foundation, either version 3 of the License,
::   or (at your option) any later version.

::   Philip Mortimer Example Programs is distributed in the hope that it will be
::   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
::   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
::   GNU General Public License for more details.

::   You should have received a copy of the GNU General Public License
::   along with Philip Mortimer Example Programs.  If not, see 
::   <https://www.gnu.org/licenses/>.

@echo off

set f1=..\src\CmpLastModifiedMain.cpp
set f2=CmpLastModified.exe

CmpLastModified.exe %f1% %f2%

if errorlevel 4 echo error detected && goto end
if errorlevel 3 echo %f1% modified later than %f2% && goto end
if errorlevel 2 echo %f1% modified at same time as %f2% && goto end
if errorlevel 1 echo %f1% modified earlier than %f2% && goto end

:end
pause