#include <stdio.h>
#include <omp.h>

int main (void){
    int thread_num = 0;

    omp_set_num_threads(2); //definindo o numero de threads

    //bloco paralelo
    #pragma omp parallel 
    { 
        #if _OPENMP
            thread_num = omp_get_thread_num();
        #endif
        printf("Hello World from thread %d\n", thread_num); //capturando id da thread
    }
    //gcc -o helloworld.c --> roda o programa de forma serial
    //gcc -o helloworld.c -fopenmp --> roda de forma paralela

    //export OMP_NUM_THREADS=2 -- essa variavel de ambiente limita o número de threads
    return 0;
}