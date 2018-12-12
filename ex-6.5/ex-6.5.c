#include <stdio.h>
#include <stdlib.h>


void strjoin(char *str1, char *str2, char *str){
	int cont = 0, i2 = 0;
	
	for(int i = 0; cont!=2;i++){
		if(cont==0){
			str[i] = str1[i];
			if (str[i+1] == '\0'){
				cont = 1;
			}
		} else{
			str[i] = str2[i2];
			if (str[i2] == '\0'){
				cont = 2;
			}
			i2++;
		}
	}
}


int main(void){
	char str_destino[200], str_origem1[26], str_origem2[26];
	printf("Digite uma string: ");
	scanf("%s", str_origem1);
	
	printf("Digite outra string: ");
	scanf("%s", str_origem2);
	
	strjoin(str_origem1, str_origem2, str_destino);
	
	printf("String destino: %s\n" , str_destino);
	
	system("pause");
	return 0;
}