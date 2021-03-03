# CmpLastModified program

This program compares the last modified dates of two files.


## How to build the program

Use the **Makefile** in the **../build** folder. See the README file in the
**../build** folder for more information.

The source files for the program are in the folder **..\src**.
        

## How to run the program

On the command line type **CmpLastModified** (**CmpLastModified.exe**
on Windows) followed by the names or paths of the two files whose last modified
dates are to be compared. For example:


            CmpLastModified.exe results1.log results2.log
        

The file names can optionally be preceded by **-v** in order to generate 
verbose output. For example:


            CmpLastModified.exe -v results1.log results2.log
        

When the program has finished running it will return one of the following exit
codes:

|Exit code|Meaning                                                       |
|---------|--------------------------------------------------------------|
|1        |1st file on command line modified earlier than 2nd file       |
|2        |1st file on command line modified at the same time as 2nd file|
|3        |1st file on command line modified later than 2nd file         |
|4        |error detected                                                |
        

See **example.cmd** in the same folder as this document for an example of how
to use the program in a Windows command script.

See **example.sh** in the same folder as this document for an example of how
to use the program in a bash shell script. This script runs the program in
verbose mode and redirects the program's output to a file called **cmpinfo**.




    
