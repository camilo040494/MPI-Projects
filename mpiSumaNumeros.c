#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sumTotal, maxVal;
	int start, end, size, rank;
	
	maxVal = 10000;
	
	int arreglo[maxVal];
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	start = ((maxVal/size)*rank)+1;
	end = (maxVal/size)*(rank+1);
	
	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
	sum = 0;
	for(i=start; i<= end; i++){
		sum = sum +i;
	}
	
	printf("[%d] Mi subtotal es %d\n",rank, sum);
	sumTotal = 0;
	
	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
		printf("El total es %d\n",sumTotal);
	
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas 
	//printf ("\nTotal: %d\n",sumTotal);

	MPI_Finalize();
	
	return 0;
}