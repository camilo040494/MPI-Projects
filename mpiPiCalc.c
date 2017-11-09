#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	double x, y, circle, circleTotal, out;
	int i, start, end, size, rank, max;
	max = 1e9;

	srand(time(NULL));
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	start = (int)(max/size)*rank;
	end = (int)(max/size)*(1+rank);

	//start = pow(10, rank+2);
	//if(rank==0){
	//	start=0;
	//}
	//end = pow(10, rank+3)-1;

	circle = 0;
	for (i = start; i < end; i ++) {
            double x = (double)(rand()) / (double)(RAND_MAX);
            double y = (double)(rand()) / (double)(RAND_MAX);
            if (x * x + y * y <= 1.0) circle ++;
        }

	MPI_Reduce(&circle, &circleTotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	printf("El valor de circle es %lf\n",circle);
	out = 0;
	out=(double)circleTotal / max * 4.0;
	
	if (rank == 0){
		printf("El valor de circleTotal es %lf\n",circleTotal);
		printf("El valor de pi es %lf\n",out);
	}

	MPI_Finalize();

	return 0;
}