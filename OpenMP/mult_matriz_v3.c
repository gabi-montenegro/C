#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>


#define SIZE 1000

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int C[SIZE][SIZE];

int main() 
{
    clock_t ini, fim;
    ini = clock();
    int i,j,k;
    int N = 80;
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            A[i][j] = rand() % 3;
            B[i][j] = rand() % 3;
	}
   //foi observado que setando a matriz C como shared há um ganho maior que setando como fisrtprivate. Isso acontece pois cada thread cria uma cópia da matriz C
   //matriz C é private, firstprivate ou shared?
   //as estruturas A, B e N estão sendo lidas
    #pragma omp parallel shared(A,B,N) firstprivate(C) private(i,j,k)
    #pragma omp for
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    fim = clock();
    printf("Tempo %f\n", (double) (fim-ini) / (double) (CLOCKS_PER_SEC)); 

    // for (i= 0; i< N; i++)
    // {
    //     for (j= 0; j< N; j++)
    //     {
    //         printf("%d\t",C[i][j]);
    //     }
    //     printf("\n");
    // }

    //calcular aceleração: antes e depois da melhoria
}
