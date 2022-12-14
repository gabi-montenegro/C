#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(void){
    double sum;
    double a[256], b[256];
    int n = 256, i, aux;

    //inicializacao
    for (i=0; i<n; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }

    
    sum = 0;
    int value = 0;
    #pragma omp parallel shared(a,b, sum) private(i, aux) 
    {
        aux = 0.0;
        #pragma omp for 
        for (i=1; i<n; i++){
            aux = aux + a[i]*b[i];
        }
        #pragma omp critical //cada thread de cada vez vai escrever em sum
        sum = sum + aux;
        
    }
    printf ("sum = %f\n", sum);
    
}//main