#include <stdio.h>
#include <string.h>

int main(void){
	char str[26];
	scanf("%s", str);

	FILE * f = fopen("arq-01.txt", "w");

	for (int i=0; i<(strlen(str));i++){
		fputc(str[i],f);
	}

	fclose(f); 





	return 0;
}