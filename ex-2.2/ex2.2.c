#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1, n2, i;
	printf("Digite n1: ");
	scanf("%d", &n1);
	printf("Digite n2: ");
	scanf("%d", &n2);
	
	int maior = 0, menor = 0;
	
	if (n1>n2){
		maior = n1;	
		menor = n2;
		
	}else{
		maior = n2;	
		menor = n1;
}

	for (int i=menor+1;i<maior;i++){
		printf("Numeros do intervalo: %i\n", i);
		
	}
	
	system("pause");
	return 0;
}
