#include "mpi.h"
#include <stdio.h>
//mpirun -n 10 ./exec N "nome-do-arquivo-de-saida"
//https://www.mcs.anl.gov/~itf/dbpp/text/node96.html

int i;
MPI_Status Stat;

void process_1(int *valor) {
    MPI_Send(&valor, 1, MPI_INT, 1, 1, MPI_COMM_WORLD); // processo 0 envia para o processo 1
    // printf("Task %d: Received char(s) from task %d with tag %d \n", rank, Stat.MPI_SOURCE, Stat.MPI_TAG);
}

void process_middle(int *rank, int *valor) { //envia pro i+1
    MPI_Recv(&valor, 1, MPI_INT, i-1, 1, MPI_COMM_WORLD, &Stat);
    *valor = *valor + *rank;
    MPI_Send(&valor, 1, MPI_INT, i+1, 1, MPI_COMM_WORLD);
    MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    MPI_Recv(&valor, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &Stat); // processo 0 recebe dado
    printf("Task %ls: Received char(s) from task %d with tag %d \n", rank, Stat.MPI_SOURCE, Stat.MPI_TAG);
}


void process_n(int *rank, int *valor) {
    MPI_Recv(&valor, 1, MPI_INT, i-1, 1, MPI_COMM_WORLD, &Stat);
    *valor = *valor + *rank;
    MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    MPI_Recv(&valor, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &Stat); // processo 0 recebe dado
    
}


int main(int argc,char *argv[])
{
int rank;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &argc); //numero de processos
MPI_Comm_rank(MPI_COMM_WORLD, &rank); // identificação do processo
int valor = atoi(argv[1]);
int dest = 0;


   

    int num_processos = 4;
    // int dest = 0;
    // int tag = 0;

     

    for (i = 0; i < num_processos; i++){
        if (i == 0) process_1(&valor);
        else if(i == num_processos-1) process_n(&rank, &valor);
        else {
            process_middle(&rank, &valor);
        }
    }


    // for (i=1; i < num_processos; i++) {

    //     MPI_Recv(&valor, 1, MPI_INT, i-1, 1, MPI_COMM_WORLD, &Stat); //processo i recebe dado do processo i-1
    
    //     valor = valor + rank;

    //     if(i == num_processos-1) { //ultimo processo
    //         //envia dado para o processo 0
    //         MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD); //processo i envia para o processo 0

    //         //processo 0 recebe dado
    //         MPI_Recv(&valor, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &Stat); //processo 0 recebe dado do processo i

    //     } else {
    //         MPI_Send(&valor, 1, MPI_INT, i+1, 1, MPI_COMM_WORLD); //processo i envia dado para o processo i+1

    //         MPI_Recv(&valor, 1, MPI_INT, i+2, 1, MPI_COMM_WORLD, &Stat); //processo i recebe dado para o processo i+2

    //         MPI_Send(&valor, 1, MPI_INT, 0, 1, MPI_COMM_WORLD); //processo i envia para o processo 0

    //         MPI_Recv(&valor, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &Stat); //processo 0 recebe dado do processo i
    //     }
        

        //printf("Task %d: Received char(s) from task %d with tag %d \n", rank, Stat.MPI_SOURCE, Stat.MPI_TAG);
    



    

    // if(rank == 0) {
    //     MPI_Send(&valor, 1, MPI_INT, dest+1, rank, MPI_COMM_WORLD); // processo 0 envia para o processo 1
    // } 


    MPI_Finalize();


    return 0;

}