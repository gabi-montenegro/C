#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


void set_vector(int *vector, int size){
    
    for (int i = 0; i < size; i++) {
        vector[i] = 1;
    }
    
}


int main(void){

    int size = 10;
    int *vector = NULL;
    vector = (int *) malloc(sizeof(int)*size);

    set_vector(vector, size);

    unsigned long acc = 0;

    
    //#pragma omp parallel for reduction(+:acc) -> trabalho cooperativo (work sharing)
    //todas as threads fazem a mesma coisa
    #pragma omp parallel shared(size, vector) num_threads(4) reduction (+:acc) //cada thread vai ter uma versao privada da variavel aac. E ao final, elas fazem um reduction de soma 
    //#pragma omp parallel firstprivate(acc)
    { 
        for (int i = 0; i < size; i++) {
            acc += vector[i]; //redução de soma: 10 10 10 10 -> 40
        }
         printf("Numero da thread: %d\n", omp_get_thread_num());
         printf("Resultado dentro da região paralela: %lu\n", acc);
    }
        printf("Fora da região paralela: %lu\n", acc);
   
    return 0;
}