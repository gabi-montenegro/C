#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char vetor[3][26]; //3 palavras com 26 caracteres
    
	
	FILE *f = fopen("arq_3.txt", "w");
	
    for (int i = 0; i < 2; i++){
        printf("Digite o nome %d: ", i+1);
        scanf("%s", vetor[i]);
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 26; j++){
			if (j < strlen(vetor[i])){
				fputc(vetor[i][j], f);
			}
			else{
				fputc('-', f);
			}
		}
      
    }
	
	fclose(f);
    system("pause");


    return 0;



}