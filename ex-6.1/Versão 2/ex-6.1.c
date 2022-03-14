#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
#define n 5 //RESPOSTA: (nome=n, propriedade=valor, tempo=pré-processamento)

extern int medias(int *); //RESPOSTA: (nome=medias, propriedade=implementação, tempo=ligação)
//RESPOSTA (nome=medias(), propriedade=tipo de retorno, tempo=compilação)

void preenche (int *vec){
	for (int i=0;i<n;i++){//RESPOSTA: (nome:for, propriedade=especificação, tempo=design)
		printf("Digite o valor %d ----->", i+1); //RESPOSTA:(nome:'+', propriedade:semântica, tempo=compilação)
		scanf("%d", vec+i);//RESPOSTA: (nome=scanf(), propriedade=implementação, tempo=ligação) 
	}
}


int main(void){
	int vec[n]; 
	preenche(vec);//RESPOSTA: (nome=preeche(vec), propriedade=endereço da função, tempo=execução) 
	int media_total = medias(vec); //RESPOSTA (nome=media_total, propriedade=endereço da variável, tempo=execução)
	//RESPOSTA (nome=int, propriedade = tamanho em bytes, tempo = design) 
	printf("\nMedia: %d\n", media_total);//RESPOSTA: (nome=printf(), propriedade=implementação, tempo=ligação)
	
	return 0;
}
	
