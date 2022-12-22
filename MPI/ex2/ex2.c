#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int rank;
    MPI_Status Stat;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char msg2[2], msg[2] = "hi";
    int tam;

    if(rank == 0){
        //recebe as 100 mensagens de cada processo

        FILE *f = fopen("ex2.txt", "w");
        if (f == NULL) printf("failed to open the file");

        if (argc == 2){
            tam = 100;
        }else{
            tam = (argc-1) * 100;
        }
        
        for(int j = 0; j < tam; j++){
            MPI_Recv(&msg2, 2, MPI_CHAR, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &Stat);
            // printf("Id: %d ---- Msg: %s\n", Stat.MPI_SOURCE, msg2);
            fprintf(f,"Id: %d ---- Msg: %s\n", Stat.MPI_SOURCE, msg2);
        }
        
    }else{
        //envia as 100 mensagens para o processo 0
        for(int i = 0; i < 100; i++){
            MPI_Send(&msg, 2, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
        }
    }    
    MPI_Finalize();
    return 0;

}