#include <iostream>
#include <time.h> // time
#include <stdlib.h> // srand

using namespace std;

int main(int argc,char *argv[]){
	int i, sum, sumTotal, maxVal;
	int start, end, size, rank;
	
srand(time(NULL));
    cout.precision(10);
    cout << "HelloACM.com rocks!" << endl;
    const int N[] = {1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};

cout << sizeof(N) <<endl;
cout << sizeof(N[0]) <<endl;
cout << (sizeof(N) / sizeof(N[0])) <<endl;

    for (int j = 0; j < (sizeof(N) / sizeof(N[0])); j ++) {
        int circle = 0;
        for (int i = 0; i < N[j]; i ++) {
            double x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            double y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            if (x * x + y * y <= 1.0) circle ++;
        }
 
        cout << N[j] << (char)9 << (char)9 << (double)circle / N[j] * 4.0 << endl;
    }


/**	
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
**/	
	return 0;
}