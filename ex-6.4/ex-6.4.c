#include <stdio.h>
#include <stdlib.h>

int strlen2(char *str){
	int i=0;
	while (str[i]!='\0'){
		if (str[i]== ' '){
			str[i]=str[i+1];	
		}
		i++;
	}
	return i;
	
}

int main(void){
	char str[50];
	printf("Digite uma string: ");
	scanf("%s", str);
	
	int qtd_string = strlen2(str);
	
	printf("Quantidade de caracteres: %d\n", qtd_string);
	
	system("pause");
	return 0;
}