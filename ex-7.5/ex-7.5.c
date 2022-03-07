#include <stdio.h>
#include <stdlib.h>

struct Produto{
	int id_produto;
	char nome_produto[30];
	float preco;
};

struct Livro{
	char autor[30];
	char genero[30];
	int num_paginas;
    union {
        unsigned long int cod_barras;
        unsigned long int isbn;

}op;
	struct Produto livro;
    short int temp;
};


void preenche2 (struct Livro *p){
	printf("Id: ");
	scanf("%d", &((*p).livro).id_produto);
	printf("Nome do Produto: ");
	scanf(" %[^\n]s", ((*p).livro).nome_produto); 
	printf("Preco: ");
	scanf("%f", &((*p).livro).preco);
	printf("Autor: ");
	scanf(" %[^\n]s", (*p).autor);
	printf("Genero: ");
	scanf(" %[^\n]s", (*p).genero);
	printf("Paginas: ");
	scanf("%d", &(*p).num_paginas);

    printf("[1] para codigo de barras ou [2] para isbn: ");
    scanf("%hd", &(*p).temp);
    
    if ((p->temp) == '1'){
        printf("Codigo de Barras: ");
        scanf("%ld", &((*p).op).cod_barras);
    }else{
        printf("ISBN: ");
        scanf("%ld", &((*p).op).isbn);
    }
}

void imprimir (struct Livro *p){
	printf("\n");
	printf("Id = %02d\n", ((*p).livro).id_produto);
	printf("Nome do Produto = %s\n", ((*p).livro).nome_produto);
	printf("Preco = %.2f\n", ((*p).livro).preco);
	printf("Autor = %s\n", (*p).autor);
	printf("Genero = %s\n", (*p).genero);
	printf("Numero de Paginas = %d\n", (*p).num_paginas);

    if ((p->temp) == '1'){
        printf("Código de Barras: %02ld", p->op.cod_barras);

    }else{
        printf("ISBN: %02ld", p->op.isbn);

    }
	
}

int main(void){
		struct Livro p;
		preenche2 (&p);
		imprimir(&p);
		system("pause");
		return 0;
	
	
}
