# How to create the program executables

## How to create the **CmpLastModified** program executable

Enter the following command on the command line:

        make CmpLastModified


This will create the executable file **CmpLastModified** (**CmpLastModified.exe** 
on Windows) in the folder **../CmpLastModified**.


## How to create the **PrintFileInfo** program executable

Enter the following command on the command line:

        make PrintFileInfo


This will create the executable file **PrintFileInfo** (**PrintFileInfo.exe** 
on Windows) in the folder **../PrintFileInfo**.


## How to create the **CurrDateTime** program executable

Enter the following command on the command line:

        make CurrDateTime


This will create the executable file **CurrDateTime** (**CurrDateTime.exe** 
on Windows) in the folder **../CurrentDateTime**.


## How to create all the program executables

To create all the above executables enter the following command on the command
line:

        make all
    
   
Note that the above information assumes that the make command is 'make'.
The make command might be different on your computer depending on what
software for developing C++ programs is installed - see the 
documentation that came with the software.

Note that you will need to change the value of **CXX** near the top of 
**Makefile** if you are using a C++ compiler other than g++, and you might
need to make other changes to **Makefile**.
