/*
 * The Game of Life
 *
 * a cell is born, if it has exactly three neighbours 
 * a cell dies of loneliness, if it has less than two neighbours 
 * a cell dies of overcrowding, if it has more than three neighbours 
 * a cell survives to the next generation, if it does not die of loneliness 
 * or overcrowding 
 *
 * In this version, a 2D array of ints is used.  A 1 cell is on, a 0 cell is off.
 * The game plays a number of steps (given by the input), printing to the screen each time.  'x' printed
 * means on, space means off.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
typedef unsigned char cell_t; 
int rank;
int argc;
int size, steps;
MPI_Status Stat;
int slice_int, slice_dec;

cell_t ** p0;
cell_t ** p1;
cell_t ** p2;
cell_t ** p3;



//4 matrizes referentes a 4 processos  
	// cell_t ** p1 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p2 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p3 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p4 = (cell_t **) malloc(sizeof(cell_t*)*size);

cell_t ** allocate_board (int size) {
	cell_t ** board;
	board = (cell_t **) malloc(sizeof(cell_t*)*size);

	int	i;

	for (i=0; i<size; i++)
			board[i] = (cell_t *) malloc(sizeof(cell_t)*size);
	return board;
	
}

void free_board (cell_t ** board, int size) {
        int     i;

        for (i=0; i<size; i++)
                free(board[i]);
	free(board);
}


/* return the number of on cells adjacent to the i,j cell */
int adjacent_to (cell_t ** board, int size, int i, int j) {
	int	k, l, count=0;
	
	int sk = (i>0) ? i-1 : i;
	int ek = (i+1 < size) ? i+1 : i;
	int sl = (j>0) ? j-1 : j;
        int el = (j+1 < size) ? j+1 : j;

	for (k=sk; k<=ek; k++)
		for (l=sl; l<=el; l++)
			count+=board[k][l];
	count-=board[i][j];
	
	return count;
}

void play (cell_t ** board, cell_t ** newboard, int size) {
	int	i, j, a;

	// #pragma omp parallel for shared (size, board) private (i, j, newboard)
	/* for each cell, apply the rules of Life */
	
	for (i=0; i<size; i++)
		for (j=0; j<size; j++) {
			a = adjacent_to (board, size, i, j);
			if (a == 2) newboard[i][j] = board[i][j];
			if (a == 3) newboard[i][j] = 1;
			if (a < 2) newboard[i][j] = 0;
			if (a > 3) newboard[i][j] = 0;
		}
}

void fill_threads_vector(cell_t ** p0){
if(rank == 0){
		for (int i = 0; i < size; i++){ // envia os vizinhos tbm
			//for (int j=0; j<size; j++) { //tira o j (vamos enviar o ponteiro de tamanho size)
				if(i >= 0 && i < slice_dec){ //elem 0 à 2
					MPI_Send(&(p0[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD); //processo 0 envia para ele mesmo
					MPI_Recv(&(p0[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 0 recebe dele mesmo
				}else if( i >= slice_dec && i < slice_dec * 2) { // elem 3 a 5
					MPI_Send(&(p0[i]), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD); //processo 0 envia para p1
					// MPI_Recv(p1[i][j], 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 1 recebe de p0
				} else if (i >= slice_dec * 2 && i < slice_dec * 3) { //elem 6 a 8
					MPI_Send(&(p0[i]), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD); //processo 0 envia para p2
					// MPI_Recv(p2[i][j], 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 1 recebe de p0
				} else if(i >= slice_dec * 3 && i < size){ //elem 9 a 10 
					MPI_Send(&(p0[i]), size, MPI_CHAR, 3, 1, MPI_COMM_WORLD); //processo 0 envia para p3
				}
			//}
		}
	}
	//rever lógica dos loops (inserir aqui os vizinhos)
	if (rank == 1){
		for (int i = 0; i < (slice_dec + 2); i++){
			//for (int j=0; j<size; j++) {
				if(i > 0 && i <= slice_dec){ //preeche 1 ate 3
					MPI_Recv(&(p1[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 1 recebe de p0
				}
			//}
		}
	}

	if (rank == 2) {
		for (int i = 0; i < slice_dec + 2; i++){
			//for (int j=0; j<size; j++) {
				if(i > 0 && i <= slice_dec){ //preenche 1 ate 3
					MPI_Recv(&(p2[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 2 recebe de p0
				}
			//}
		}
	}

	if (rank == 3) {
		for (int i = 0; i < slice_int + 1; i++){
			//for (int j=0; j<size; j++) {
				if(i > 0 && i <= slice_int){ //preeche de 1 a 2
					MPI_Recv(&(p3[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //processo 3 recebe de p0
				}
			//}
		}
	}
}

/* print the life board */
void print (cell_t ** board, int size) {
	int	i, j;


	for (j=0; j<size; j++) {
		/* print each column position... */
		for (i=0; i<size; i++) 
			printf ("%c", board[i][j] ? 'x' : ' ');
		/* followed by a carriage return */
		printf ("\n");
	}
}

/* read a file into the life board */
void read_file (FILE * f, cell_t ** board, int size) {
	int	i, j;
	char	*s = (char *) malloc(size+10);
	char c;

	if(rank == 0) { 
		for (j=0; j<size; j++) {
		/* get a string */
		fgets (s, size+10,f);
		/* copy the string to the life board */
		for (i=0; i<size; i++)
		{
			board[i][j] = s[i] == 'x';
		}
		//fscanf(f,"\n");
	}


	} //processo 0 le tudo
	
}

int main (int argc,char *argv[]) {
	int tasks;
	MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &tasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	
	FILE    *f;
  	f = stdin;

	slice_int = size / tasks;
	slice_dec = size % tasks;

//MPI_Send(&(p0[i]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD); //processo 0 envia para ele mesmo

	if (rank == 0) {
		fscanf(f,"%d %d", &size, &steps);
		//printf("size: %d --- steps: %d", size, steps);
	
		for (int i = 1; i < tasks; i++){ 
			MPI_Send(&size, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
			MPI_Send(&steps, 1, MPI_INT, i, 1, MPI_COMM_WORLD);	
			MPI_Send(&slice_int, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
			MPI_Send(&slice_dec, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(&size, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		MPI_Recv(&steps, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		MPI_Recv(&slice_int, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		MPI_Recv(&slice_dec, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
	}
	
	if (rank == 0) {
		cell_t ** prev = allocate_board (size);
		cell_t ** p0 = allocate_board(size); //inserir tamanho para o p0

		MPI_Send(&(prev), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
		MPI_Send(&(prev), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD);
		MPI_Send(&(prev), size, MPI_CHAR, 3, 1, MPI_COMM_WORLD);
		MPI_Recv(&next, size, MPI_INT, 3, 1, MPI_COMM_WORLD, &Stat);
		
	} else if (rank == 1) {
		cell_t ** p1 = allocate_board(slice_dec + 2); //inserir tamanho para o p1

	
		MPI_Recv(&prev, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		MPI_Recv(&next, size, MPI_INT, 3, 1, MPI_COMM_WORLD, &Stat);
		

	} else if (rank == 2) {
		cell_t ** p2 = allocate_board(slice_dec + 2); //inserir tamanho para o p2

		MPI_Recv(&prev, size, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		MPI_Recv(&next, size, MPI_INT, 3, 1, MPI_COMM_WORLD, &Stat);
		

	} else if (rank == 3) {
		cell_t ** p3 = allocate_board(slice_dec); //inserir tamanho para o p3

		cell_t ** next = allocate_board(size);

		
		MPI_Recv(&prev, size, MPI_INT, 0, 1, MPI_COMM_WORLD, &Stat);
		

		MPI_Send(&next, size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat);

	}

	
	
	
	
	cell_t ** tmp;


	read_file (f, p0,size); //processo 0 le tudo
	for (int j=0; j<size; j++) {
		/* get a string */
		/* copy the string to the life board */
		for (int i=0; i<size; i++)
		{
			printf("%c", p0[j][i] ? 'x' : ' ');
		}
		printf("\n");
	}
	fclose(f);

	
	int i,j;
	//#ifdef DEBUG
	printf("Initial \n");
	//print(prev,size);
	printf("----------\n");
	 
	fill_threads_vector(p0);

	

	printf("%d --- %d\n", slice_int, slice_dec);
	printf("%d --- %d\n", tasks, rank);
	printf("size: %d --- step: %d\n", size, steps);

	for (i=0; i<steps; i++) {
		//mandar vizinhos a cada passo
		if (rank == 0) {
			MPI_Send(&(p0[slice_int]), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD); //envia p0[2] para processo 1 (p1[0])
			MPI_Recv(&(p0[slice_dec]), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &Stat); //recebe p1[1] do processo 1 para o processo 0 (p0[3])

			play (p0,next,size);
                //#ifdef DEBUG
			printf("%d ----------\n", i);
			//print (next,size);
			//#endif
			tmp = next;
			next = prev;
			prev = tmp;
		} else if (rank == 1) {
			MPI_Recv(&(p1[0]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &Stat); //recebe p0[2] do processo 0
			MPI_Send(&(p1[1]), size, MPI_CHAR, 0, 1, MPI_COMM_WORLD); //envia p1[1] para processo 0 
			MPI_Send(&(p1[slice_int]), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD); //envia p1[3] para processo 2 
			MPI_Recv(&(p1[slice_dec + 1]), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD, &Stat); //recebe p1[4]

			play (p1,next,size);
                //#ifdef DEBUG
			printf("%d ----------\n", i);
			//print (next,size);
			//#endif
			tmp = next;
			next = prev;
			prev = tmp;
			
		} else if (rank == 2) {
			MPI_Recv(&(p2[0]), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &Stat); 
			MPI_Send(&(p2[1]), size, MPI_CHAR, 1, 1, MPI_COMM_WORLD); 
			MPI_Send(&(p2[slice_int]), size, MPI_CHAR, 3, 1, MPI_COMM_WORLD); 
			MPI_Recv(&(p2[slice_dec + 1]), size, MPI_CHAR, 3, 1, MPI_COMM_WORLD, &Stat); 

			play (p2,next,size);
                //#ifdef DEBUG
			printf("%d ----------\n", i);
			//print (next,size);
			//#endif
			tmp = next;
			next = prev;
			prev = tmp;
		} else {
			MPI_Recv(&(p3[0]), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD, &Stat);
			MPI_Send(&(p3[1]), size, MPI_CHAR, 2, 1, MPI_COMM_WORLD);  

			play (p3,next,size);
                //#ifdef DEBUG
			printf("%d ----------\n", i);
			//print (next,size);
			//#endif
			tmp = next;
			next = prev;
			prev = tmp;
		}
		
	}
	//print (prev,size);
	free_board(prev,size);
	free_board(next,size);


	MPI_Finalize();

 }
