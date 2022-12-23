#include "mpi.h"
#include <stdio.h>
#include <string.h>
//mpirun -n 10 ./exec N "nome-do-arquivo-de-saida"
//https://www.mcs.anl.gov/~itf/dbpp/text/node96.html
//https://stackoverflow.com/questions/13305814/when-do-i-need-to-use-mpi-barrier

// FILE *f;

int main(int argc,char *argv[])
{


    int rank, numtasks, valor, valor2;
    MPI_Status Stat;
    valor = atoi(argv[1]);
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);




    int rc;

    if (rank == 0) { //processo 0
        valor = valor + rank;
        MPI_Send(&valor, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

        FILE *f = fopen(argv[2], "w");
        if (f == NULL) printf("failed to open the file");
        
        // printf("Id: 0 ---- Valor: %d\n", valor);
        fprintf(f, "Identificação:  0 |  Valor: %d\n", valor);
        for (int j = 1; j < argc; j++){
            MPI_Recv(&valor2, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &Stat);
            // printf("Id: %d ---- Valor: %d\n", Stat.MPI_SOURCE, valor2);
            fprintf(f, "Identificação:  %d |  Valor: %d\n", Stat.MPI_SOURCE,valor2);
        }
        
        
        
        
    } else if(rank == argc-1) { // processo n
        
        // printf("Num tasks: %d ---- Rank: %d --- Valor: %d --- Sou o ultimo\n", argc, rank, valor);
        MPI_Recv(&valor2, 1, MPI_INT, argc-2, 1, MPI_COMM_WORLD, &Stat); //recebe do penultimo processo
        valor = valor2 + rank;
        rc = MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD); //envia pro Processo 0
        // printf("Id: %d ---- Valor: %d\n", rank, valor2);
        
        
    } else { //processo i
        
        // printf("Num tasks: %d ---- Rank: %d --- Valor: %d\n", argc, rank, valor);
        MPI_Recv(&valor2, 1, MPI_INT, rank-1, 1, MPI_COMM_WORLD, &Stat); //recebe do processo i-1
        valor = valor2 + rank;
        MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD); //envia pro processo 0
        MPI_Send(&valor, 1, MPI_INT, rank+1, 1, MPI_COMM_WORLD); //envia para o processo i+1
        
        // printf("Id: %d ---- Valor: %d\n", rank, valor2);
        
    }

    // for (int j = 1; j < argc; j++){
    //     if (rank == j){
    //         printf("Id: %d ---- Valor: %d\n", rank, valor2);
    //     }
    //     MPI_Barrier(MPI_COMM_WORLD);
    // }

    // snprintf(string, "  %s |   %s |  %s\n", itoa(rank), itoa(Stat.MPI_SOURCE), itoa(valor));
    // // strcat(itoa())
    // MPI_File_write(f, string, strlen(string)+1, MPI_CHAR, MPI_STATUS_IGNORE);

    // if (rank == 0){
    // printf("Num tasks: %d ---- Rank: %d ---- Recebido por: %d --- Valor: %d\n", argc, rank, Stat.MPI_SOURCE, valor);
    // }


    MPI_Finalize();

    return 0;
}