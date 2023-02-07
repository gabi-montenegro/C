CC=cc

FLAGS=-O3

all: life

life-cc: life.c
	@mpicc life.c -o life

life-run: life.c 
	@mpirun -n 4 ./life
clean:
	rm life
