#include <stdio.h>
#include <stdlib.h>

struct Produto{
	char id_produto;
	char nome[30];
	float preco;
};


void preenche (struct Produto *p){
	printf("Id: ");
	scanf("%c", &(*p).id_produto);
	printf("Nome: ");
	scanf("%s", &(*p).nome);
	printf("Preco: ");
	scanf("%f", &(*p).preco); 
	
}
int main(void){
		struct Produto p;
		preenche(&p);
		printf("\n");
		printf("Id = %c", p.id_produto);
		printf("Nome = %s\n", p.nome);
		printf("Preco = %.2f\n", p.preco);
		system("pause");
		return 0;
	
	
}
