#include <stdio.h>
#include <string.h>

void escreve_string (FILE *f, char *str){
	for (int i=0; i<(strlen(str));i++){
		fputc(str[i],f);
	}
}




int main(void){
	char str[26];
	scanf("%s", str);

	FILE * f = fopen("arq-01.txt", "w");
	
	escreve_string(f, str);
	fclose(f); 

	system("pause");

	return 0;
}