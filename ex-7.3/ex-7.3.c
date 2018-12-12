#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
	int x, y;
};

void preenche (struct ponto *p1){
	printf("Digite x: ");
	scanf("%d", &(*p1).x);
	printf("Digite y: ");
	scanf("%d", &(*p1).y);
}

void preenche_vetor(struct ponto *vetor, int tamanho){
	int i;
	for (i=0;i<tamanho;i++){
		preenche(vetor+i); 
	}
}

struct ponto *ponto_distante(struct ponto *vetor, int tamanho){
	int i, maior=0,menor;
	struct ponto *p;
	for (i=0;i<tamanho;i++){
		menor=sqrt(pow((vetor+i)->x,2)+ pow((vetor+i)->y,2));
		if (menor>maior){
			maior=menor;
			p=(vetor+i);
		}
	}
	return p;//retornando ponteiro
}

int main (void){
	struct ponto p1;
	//preenche(&p1);
	struct ponto vetor[10];
	preenche_vetor(vetor,10);
	
	struct ponto *distante = ponto_distante(vetor,10);
	printf("Ponto mais distante: (%d,%d)", distante->x, distante->y);
	system("pause");
	return 0;
	
}