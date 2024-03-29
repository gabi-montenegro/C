#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
//https://stackoverflow.com/questions/19775887/c-fill-a-two-dimensional-array-using-a-helper-function

#define SIZE 10 /* Max size of matrices */
static int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE] = {1};

// void fill_matrix(int **matriz, int N, int num){
//     for(int i = 0; i < N; i++){
//         for (int j = 0; j < N; i++) {
//             //**(matriz+i*N+j) = 1;
//             matriz[i][j] = num;
//         }
//     }
// }

int **preenche(int N){
    int **matriz = (int**) malloc(N* sizeof(int*));
    for(int i = 0; i < N; i++){
        matriz[i] = (int *) malloc(sizeof(int) * N);
    }
    //int (*matriz)[N] = malloc (N * sizeof (*matriz));

    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; i++) {
            matriz[i][j] = 1;
        }
    }
    return matriz;
    
}

int main(void)
{
    int i,j,k,N;
    N=SIZE;


    int **A, **B, **C;

    A = preenche(N);
    B = preenche(N);
    C = preenche(N);




    omp_set_num_threads(4);
    #pragma omp parallel shared(A,B,C,N) private(i,j,k)
    #pragma omp for
        for ( i = 0; i < N; i++ )
        {
            for ( j = 0; j < N; j++ )
            {
                for ( k = 0; k < N; k++ )
                {
                    C[i][j] = C[i][j] + A[i][j] * B[i][j];
                }
            }
        }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d   ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}