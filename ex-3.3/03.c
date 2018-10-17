#include <stdio.h>
#include <stdlib.h>


int main(){
	char temps[49];
	int i=0, media,soma=0, tempmaior=0;
	char a;

  //Guardando as temperaturas no vetor
	while(i<=49){
		printf("Digite uma temperatura: ");
		int x;
		scanf("%d", &x);
		a=x;
		temps[i]=a;
		soma+=temps[i];
		i++;
		
	}//fim do while
	media=(soma/i);
	printf("\nMedia das temperaturas: %d", media);

  //Verificando quantas temperaturas estão acima da média
	for(i=0;i<=49;i++){
		if (temps[i]>media){
				tempmaior+=1;
      
    }//fim do if
  }//fim do for
  printf("\nQuantidade de temperaturas acima da media: %d\n", tempmaior);
  system("pause");
  return 0;
}//fim do main

//No 03.png, fiz com 4 temperaturas.
