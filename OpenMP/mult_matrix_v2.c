#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
//https://stackoverflow.com/questions/19775887/c-fill-a-two-dimensional-array-using-a-helper-function

#define SIZE 100 /* Max size of matrices */
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

// void fill_matrix(int **matriz, int N, int num){
//     for(int i = 0; i < N; i++){
//         for (int j = 0; j < N; i++) {
//             //**(matriz+i*N+j) = 1;
//             matriz[i][j] = num;
//         }
//     }
// }

void preenche(int (*matriz)[SIZE], int N){

    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; i++) {
            matriz[i][j] = 1;
        }
    }
    
}

int main(void)
{
    int i,j,k,N;
    N=20;


    preenche(A, N);
    preenche(B, N);




    omp_set_num_threads(4);
    #pragma omp parallel shared(A,B,C,N) private(i,j,k)
    #pragma omp for
        for ( i = 0; i < N; i++ )
        {
            for ( j = 0; j < N; j++ )
            {
                C[i][j] = 0.0;
                for ( k = 0; k < N; k++ )
                {
                    C[i][j] = C[i][j] + A[i][j] * B[i][j];
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