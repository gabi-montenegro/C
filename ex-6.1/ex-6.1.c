#include <stdio.h>
#include <stdlib.h>

void preenche (int *vec, int n){
	for (int i=0;i<n;i++){
		printf("Digite o valor %d ----->", i+1);
		scanf("%d", vec+1);
	}
}

void medias(int *vec, int n){
	int soma=0;
	
	for (int i=0;i<n;i++){
		soma+=*(vec+1);
}

	int media = (soma/n);
	printf("\nMedia: %d", media);
}


int main(void){
	int vec[100];
	int n;
	printf("Digite o valor de n: ");
	scanf("%d", &n);
	
	
	preenche(vec, n);
	medias(vec,n);
	
	
	system("pause");
	return 0;
}