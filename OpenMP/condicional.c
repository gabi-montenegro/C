#ifdef _OPENMP //_OPENMP é true quando compila com a diretiva -fopenmp
#include <omp.h>
#endif 
#include <stdio.h>

int main() {
    #pragma omp parallel 
    { //abre chaves na linha seguinte
        #ifdef _OPENMP
            int np = omp_get_num_threads();
            int iam = omp_get_thread_num();
            printf("Hello from thread %d (total %d)\n", iam, np);
        #endif 

    }

    return 0;
}