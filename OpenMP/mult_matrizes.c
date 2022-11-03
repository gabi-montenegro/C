#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
//https://stackoverflow.com/questions/19775887/c-fill-a-two-dimensional-array-using-a-helper-function

#define SIZE 1000 /* Max size of matrices */
//int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void fill_matrix(int **matriz, int N, int num){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; i++) {
            //**(matriz+i*N+j) = 1;
            matriz[i][j] = num;
        }
    }
}


int main(int argc, char *argv[])
{
 int i,j,k,N;
 N=30;
int **matA = (int**) malloc(SIZE * sizeof(int));
int **matB = (int**)malloc(SIZE * sizeof(int));
int **C = (int**)malloc(SIZE * sizeof(int));

for(int i = 0; i < N; i++){
    matA[i] = (int *) malloc(SIZE * sizeof(int));
    matB[i] = (int*) malloc(SIZE * sizeof(int));
    C[i] = (int*) malloc(SIZE * sizeof(int));
}


 fill_matrix(matA, N, 1);
 fill_matrix(matB, N, 1);



#pragma omp parallel shared(matA,matB,C,N) private(i,j,k)
 #pragma omp for
 for ( i = 0; i < N; i++ )
 {
 for ( j = 0; j < N; j++ )
 {
 C[i][j] = 0.0;
 for ( k = 0; k < N; k++ )
 {
 C[i][j] = C[i][j] + matA[i][j] * matB[i][j];
 }
 }
 }

for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        printf("%d\n", C[i][j]);
    }
}

 return 0;
}