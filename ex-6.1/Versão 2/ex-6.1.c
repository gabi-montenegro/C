#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
#define n 5 //RESPOSTA: (nome=n, propriedade=valor, tempo=pré-processamento)

extern int medias(int *); //RESPOSTA: (nome=medias, propriedade=implementação, tempo=ligação)
//RESPOSTA (nome=medias, propriedade=retorno, tempo=compilação)

void preenche (int *vec){
	for (int i=0;i<n;i++){//RESPOSTA: (nome:for, propriedade=especificação, tempo=design)
		printf("Digite o valor %d ----->", i+1); //RESPOSTA:(nome:'+', propriedade:semântica, tempo=compilação)
		scanf("%d", vec+i);//RESPOSTA: (nome=scanf(), propriedade=implementação, tempo=ligação) APAGA
	}
}


int main(void){
	int vec[n]; //RESPOSTA (nome=vec[n], propriedade=tamanho, tempo=implementação)
	preenche(vec);//RESPOSTA: (nome=preeche(vec), propriedade=, tempo=compilação) APAGA
	int media_total = medias(vec); //RESPOSTA (nome=media_total, propriedade=endereço, tempo=execução)
	printf("\nMedia: %d\n", media_total);//RESPOSTA: (nome=scanf(), propriedade=implementação, tempo=ligação) APAGA
	
	
	/*system("pause");*/
    return 0;
}
	