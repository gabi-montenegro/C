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

    #pragma omp parallel for reduction (+:acc) //cada thread vai ter uma versao privada da variavel aac. E ao final, elas fazem um reduction de soma 
    //#pragma omp parallel firstprivate(acc)
    //{ 
        for (int i = 0; i < size; i++) {
            acc += vector[i];
        }
         printf("Resultado dentro da região paralela: %lu\n", acc);
    //}
        printf("Fora da região paralela: %lu\n", acc);
   
    return 0;
}