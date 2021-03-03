# Creating the Program Executables

To create the executables enter the following commands on the command line.


To create the executable file for the **CmpLastModified** program enter:

        make CmpLastModified


This will create the executable file **CmpLastModified** (**CmpLastModified.exe** 
on Windows) in the folder **../CmpLastModified**.


To create the executable file for the **PrintFileInfo** program enter:

        make PrintFileInfo


This will create the executable file **PrintFileInfo** (**PrintFileInfo.exe** 
on Windows) in the folder **../PrintFileInfo**.


To create the executable file for the **CurrDateTime** program enter:

        make CurrDateTime


This will create the executable file **CurrDateTime** (**CurrDateTime.exe** 
on Windows) in the folder **../CurrentDateTime**.


To create all the above executables enter:

        make all
    
    
Note that the above information assumes that the make command is 'make'.
The make command might be different on your computer depending on what
software for developing C++ programs is installed - see the 
documentation that came with the software.

Note that you will need to change the value of **CXX** near the top of 
**Makefile** if you are using a C++ compiler other than g++, and you might
need to make other changes to **Makefile**.
