#include <stdio.h>
#include <stdlib.h>

struct Produto{
	int id_produto;
	char nome_produto[30];
	float preco;
};

struct Livro{
	char nome_livro[30];
	char autor[30];
	char genero[30];
	int num_paginas;
	struct Produto livro;
};


void preenche2 (struct Livro *p){
	printf("Id: ");
	scanf("%d", &((*p).livro).id_produto);

	printf("Nome do Produto: ");
	scanf("%s", ((*p).livro).nome_produto); 

	printf("Nome do livro:  ");
	scanf(" %[^\n]s", (*p).nome_livro);

	printf("Preco: ");
	scanf("%f", &((*p).livro).preco);

	printf("Autor: ");
	scanf(" %[^\n]s", (*p).autor);
   

	printf("Genero: ");
	scanf(" %[^\n]s", (*p).genero);

	printf("Paginas: ");
	scanf("%d", &(*p).num_paginas);
	}
	
void imprimir (struct Livro *p){
	printf("**************************\n");
	printf("Id = %02d\n", ((*p).livro).id_produto);
	printf("Nome do Produto = %s\n", ((*p).livro).nome_produto);
	printf("Preco = %.2f\n", ((*p).livro).preco);
	printf("Nome do Livro = %s\n", (*p).nome_livro);
	printf("Autor = %s\n", (*p).autor);
	printf("Genero = %s\n", (*p).genero);
	printf("Numero de Paginas = %d\n", (*p).num_paginas);
}

int main(void){
		struct Livro p;
		preenche2 (&p);
		imprimir(&p);
		system("pause");
		return 0;
	
	
}
