#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
	int idade;
	char nome[26];
};


void preenche_vetor(struct Pessoa *vetor){
	printf("Digite o nome: ");
	scanf("%s", &vetor->nome);
			
	printf("Digite a idade: ");
	scanf("%d", &vetor->idade);
}

void preenche_bin (FILE *f, struct Pessoa *vetor){
	fwrite(&vetor->nome, sizeof(char), 26, f);
	fwrite('\0', sizeof(char), 1, f);
	fwrite(&vetor->idade, sizeof(int), 1, f);
}

int main(void){
	struct Pessoa vetor[100];
	
	FILE *f = fopen("ex8.bin" , "wb");
	
	int n;
	printf("Numero de pessoas: ");
	scanf("%s", &n);
	
	fwrite(&n, sizeof(int), 1, f);
	
	int i = 0;
	while (i < n){
		preenche_vetor(&vetor[i]);
		preenche_bin(f, &vetor[i]);
		i++;
	}
	
	fclose(f);
	system("pause");
	return 0;
}