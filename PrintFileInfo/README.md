# PrintFileInfo program

This program outputs information (e.g. the last modified time) about one or
more files.

## How to build the program

Use the **Makefile** in the **../build** folder. See the README file in the
**../build** folder for more information.

The source files for the program are in the folder **..\src**.
                

## How to run the program

On the command line type **PrintFileInfo** (**PrintFileInfo.exe**
on Windows) followed by the names or paths of one or more files. For example:


            PrintFileInfo.exe results1.log results2.log ..\src\test.cpp
        

It will output the following information for each file:

*   File type (regular file, directory or other).
            
*   String representation of last modified time. 
            
*   Size of file in bytes (regular file only).
            
        
For example:

        PrintFileInfoMain.cpp:
            file type: Regular File
            last modified: Wed, 29-May-2019 - 05:58:36 PM
            size in bytes: 579        
        

If a file does not exist then it will just output a message saying it does not
exist.

If an error is detected when attempting to obtain information about a file it
will just print an error message.

The file names can optionally be preceded by **-csv** in order to generate 
output in CSV (comma separated values) format. For example:


            PrintFileInfo.exe -csv results1.log results2.log ..\src\test.cpp


When the program has finished running it will return exit code 1 if one or
more errors were detected; otherwise it will return exit code 0.


See **example.cmd** in the same folder as this document for an example of how
to use the program in a Windows command script. This script uses the **-csv**
option, and redirects the program's output to the file **fileinfo.csv** which
you can view in a spreadsheet program such as Excel.

See **example.sh** in the same folder as this document for an example of how
to use the program in a bash shell script. This script redirects the program's
output to a file called **fileinfo**.



    
