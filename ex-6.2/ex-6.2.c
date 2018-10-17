#include <stdio.h>
#include <stdlib.h>

void preenche(int arr[4][2], int l, int c){
	for (int i=0;i<l;i++){
		for (int j=0;j<c;j++){
			printf("Digite o vetor: [%d][%d]", i+1,j+1);
			scanf("%d", &arr[i][j]);
		}
	}
	
	
}//fim da funcao

float media (int arr[4][2], int l, int c){
	int soma=0;
	for (int i=0;i<l;i++){
		for (int j=0;j<c;j++){
			soma+=arr[i][j];
}
	}
	
	float media_total = soma/(l*c);
	return media_total;
}


int main(void){
	int arr[4][2];
	int l, c;
	
	printf("Digite L: ");
	scanf("%d", &l);
	printf("Digite C: ");
	scanf("%d", &c);
	
	preenche(arr,l,c);
	float medias=media(arr, l, c);
	printf ("Media: %.2f\n", medias);
	
	
	
	
	system("pause");
	return 0;
}