# L3Cube-assignment
There are two codes in the documents. Both are the solutions to the problem of Birthday Paradox. 
I have used a library called GMP for arbitray precision arithmetic operating on signed integers, rational numbers, and floating-point numbers. There is no practical limit to the precision except the ones implied by the available memory in the machine GMP runs on.
The reason of using this library is that normal double and long double have a limit to the precision which can be set. Thus for some test cases the result truncates. So gmp has been used to improve the precision with which we can get the desired result correctly for all the test cases applicable to our problem. 


***************************************************************************************************************************************

Steps to install gmp on Ubuntu:

1.Download the gmp package from here : https://gmplib.org/
or it has been added in the repository

2.Open Terminal

3.Extract the tar file 

4.Change the directory to the extracted gmp directory

5.Run the following commands:
	./configure
	make
6.Self Tests are run by :
	make check 
	**Do not skip this step

7.make install

If you experience problems, please report them to gmp-bugs@gmplib.org . See Reporting Bugs, for information on what to include in useful bug reports.

****************************************************************************************************************************************

The MPFR library is a C library for multiple-precision floating-point computations with correct rounding.This is to be installed once gmp is installed in your system.

1. Run the following command on the terminal to install mpfr
sudo apt-get install libmpfr-dev libmpfr-doc libmpfr4 libmpfr4-dbg

****************************************************************************************************************************************

Steps to run the code:

1.gcc assgn.c -lmpfr -lgmp 

2. ./a.out

Steps to run the cpp code 

1.g++ withoutgmp.cpp

2. ./a.out
