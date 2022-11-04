
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
    int N = 5;
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            A[i][j] = rand() % 3;
            B[i][j] = rand() % 3;
	}
   
    #pragma omp parallel shared(A,B,C,N) private(i,j,k)
    #pragma omp for
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    fim = clock();
    printf("Tempo %f\n", 1000*(double) (fim-ini) / (double) (CLOCKS_PER_SEC));

    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}