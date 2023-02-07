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
//4 matrizes referentes a 4 processos  
	// cell_t ** p1 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p2 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p3 = (cell_t **) malloc(sizeof(cell_t*)*size);
	// cell_t ** p4 = (cell_t **) malloc(sizeof(cell_t*)*size);

cell_t ** allocate_board (int size) {
	if (rank = argc-1) { //se for p3 (borda), alocar size+1
		size = size + 1;
	} else if (rank != 0){
		size = size + 2;
	}

		cell_t ** board = (cell_t **) malloc(sizeof(cell_t*)*size);
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

	if(rank == 0){
		for (int i = 0; i < size; i++){
			
		}
	}
	
	
	for (i=0; i<size; i++)
		for (j=0; j<size; j++) {
			a = adjacent_to (board, size, i, j);
			if (a == 2) newboard[i][j] = board[i][j];
			if (a == 3) newboard[i][j] = 1;
			if (a < 2) newboard[i][j] = 0;
			if (a > 3) newboard[i][j] = 0;
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
	
	MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int size, steps;
	FILE    *f;
  f = stdin;
	fscanf(f,"%d %d", &size, &steps);
	cell_t ** prev = allocate_board (size);

	cell_t ** p0 = allocate_board(size); //inserir tamanho para o p0
	cell_t ** p1 = allocate_board(size % 4); //inserir tamanho para o p1
	cell_t ** p2 = allocate_board(size % 4); //inserir tamanho para o p2
	cell_t ** p3 = allocate_board(size/argc); //inserir tamanho para o p3

	read_file (f, p0,(size % 4)); //processo 0 le tudo
	fclose(f);
	cell_t ** next = allocate_board (size);
	cell_t ** tmp;
	int i,j;
	#ifdef DEBUG
	printf("Initial \n");
	print(prev,size);
	printf("----------\n");
	#endif

	//p0 contem as informações de todos os outros processos
	int slice = size % 4; //tamanho da fatia dos n-1 processos
	int sliceLast = size/argc; //fatia do ultimo processo  
	int countSlice = 0;
	int k1, k2, k3, k4;

	//trnasferir informações


	// if(rank == 0){
	// 	for (k1 = 0; k1 < slice; k1++){
	// 		p1[k1] = (cell_t *) malloc(sizeof(cell_t)*size);
	// 	}
	// 	//envia o resultado do i para o processo 1
	// 	MPI_Send(&k1, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

	// }

	// if (rank == 1){
	// 	//recebe k do processo 0
	// 	MPI_Recv(&k2, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &Stat);
	// 	//for (int k = k2; k2 < slice)
	// }

	for (i=0; i<steps; i++) {
		play (prev,next,size);
                #ifdef DEBUG
		printf("%d ----------\n", i);
		print (next,size);
		#endif
		tmp = next;
		next = prev;
		prev = tmp;
	}
	print (prev,size);
	free_board(prev,size);
	free_board(next,size);
}