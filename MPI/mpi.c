#include "mpi.h"
#include <stdio.h>
int main(int argc,char *argv[])
{
int numtasks, rank, dest, source, count, tag=1;
int rc;
char inmsg, outmsg;
MPI_Status Stat;

MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

double start, end;


if (rank == 0) {
    start = MPI_Wtime();
    dest = 1;
    source = 1;
    outmsg='x';
    MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag,
    MPI_COMM_WORLD);
    MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag,
    MPI_COMM_WORLD, &Stat);
}

else {
    dest = 0;
    source = 0;
    outmsg='y';
    rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source,
    tag, MPI_COMM_WORLD, &Stat);
    rc = MPI_Send(&outmsg, 1, MPI_CHAR, dest,
    tag, MPI_COMM_WORLD);
    end = MPI_Wtime();

}

MPI_Get_count(&Stat, MPI_CHAR, &count);

printf("Task %d: Received %d char(s) from task %d with tag %d outmsg = %c inmsg = %c \n", rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, outmsg, inmsg);

MPI_Barrier(MPI_COMM_WORLD);
if(rank ==1) printf("Tempo: %f", (end-start));
MPI_Finalize();

return 0;
}

//mpicc -o "nome-do-executável" "nome-do-arquivo.c"
//mpirun ./"nome-do-executável"