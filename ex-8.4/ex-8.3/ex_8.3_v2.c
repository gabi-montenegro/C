#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escreve_string (FILE *f, char *vetor){
	 for (int i = 0; i < strlen(vetor); i++){
				fputc(vetor[i], f);
			}
			fputc(' ', f);
	}
		
int main(void){
    char vetor[3][26]; //3 palavras com 26 caracteres
    
	
	FILE *f = fopen("arq_3.txt", "w");
	
    for (int i = 0; i < 2; i++){
        printf("Digite o nome %d: ", i+1);
        scanf("%s", vetor[i]);
    }
	
	for (int j = 0; j < 2; j++){
		escreve_string(f, vetor[j]);
	}
	
	fclose(f);
    system("pause");


    return 0;

}