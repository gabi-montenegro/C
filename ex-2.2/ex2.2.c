#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1, n2, i;
	printf("Digite n1: ");
	scanf("%d", &n1);
	printf("Digite n2: ");
	scanf("%d", &n2);
	
	if (n1<n2){
	for (i=n1+1;i<n2;i++){
		printf("Numeros do intervalo: %i\n", i);
		
	}
	}else{
		for(i=n1-1;i>n2;i--){
			printf("Numeros do intervalo: %i\n", i);	
		
		}
	
	
	}
	
	system("pause");
	return 0;
}
