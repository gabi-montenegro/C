#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int rank, tam_vetor, trocas;
    double start, end;
    MPI_Status Stat;

    tam_vetor = atoi(argv[1]);
    trocas = atoi(argv[2]);

    double *vetor1 = malloc(tam_vetor * sizeof(double));
    double *vetor2 = malloc(tam_vetor * sizeof(double));

    for(int i = 0; i < tam_vetor; i++){
        *(vetor1 + i) = -1.0;
        *(vetor2 + i) = -1.0;
    }

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        for (int j = 0; j < tam_vetor; j++) *(vetor1 + j) = 2.0;
        
        for (int k = 0; k < trocas; k++){
            //Send e Recv
            if(k == 0) start = MPI_Wtime();
            MPI_Send(vetor1, tam_vetor, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);
            MPI_Recv(vetor2, tam_vetor, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &Stat);
            // printf("\nProcesso %d - Recebido de %d\n", rank ,Stat.MPI_SOURCE);
            // for (int j = 0; j < tam_vetor; j++) {printf("--- %.1f", vetor2[j]);}
        }
    } else {
        for (int l = 0; l < tam_vetor; l++) *(vetor2 + l) = 4.0;
        
        for (int m = 0; m < trocas; m++){
            //Send e Recv
            MPI_Send(vetor2, tam_vetor, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
            MPI_Recv(vetor1, tam_vetor, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &Stat);
            if(m == 0) end = MPI_Wtime();
            // printf("\nProcesso %d - Recebido de %d\n", rank ,Stat.MPI_SOURCE);
            // for (int j = 0; j < tam_vetor; j++) printf("--- %.1f", vetor1[j]);
        }
        printf("\nTempo gasto para enviar um vetor do tamanho %d entre 2 processos: %f\n", tam_vetor, (end-start));
        
    }

        MPI_Finalize();
        
        

// for (int j = 0; j < argc; j++){
//         if (rank == j){
//             printf("Identificação: %d -----", rank);
//             for (int j = 0; j < tam_vetor; j++) printf("--- %f", vetor2[j]);

//         }
//         MPI_Barrier(MPI_COMM_WORLD);
//     }

    return 0;


}