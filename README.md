# MPI-Projects
## Requirements
To compile the projects, you must have open-mpi install and the packages of c. Instructions of installations can be found in the archive [INSTALL-MPI.txt](https://github.com/camilo040494/MPI-Projects/blob/master/INSTALL-MPI.txt)

## Compile
The following commands compiles the calculation of pi (mpiPiCalc.c)
```
mpicc mpiPiCalc.c -o pi
```

To compile any other file, use the command as follows:
```
mpicc $FILE.c -o $NAME_OF_BINARY
```
Where $FILE is the name of the .c file and $NAME_OF_BINARY is the name of the binary.

## Run
Following command runs the pi example with 4 nodes.
```
mpirun --hostfile machinefile -np 4 ./pi
```
To run any other example, just type:
```
mpirun --hostfile machinefile -np $NUMBER_OF_NODES ./$NAME_OF_BINARY
```
Where $NUMBER_OF_NODES is the number of nodes or cores to use, and $NAME_OF_BINARY is the name of the binary file tha was compiled

## C files
This examples where developed to run in a distributed way
### mpiBroadcastSimulated.c
This file simulates the MPI_BCAST method with the MPI_SEND and MPI_RECV interfaces.
### mpiSumaNumeros.c
This program calculates the sum of all the numbers between two numbers.
### mpiPiCalc.c
This program calculates an aproximate of pi with the Monte Carlo's method
### Axb.c
This program calculates the product of a matrix A with a vector b
