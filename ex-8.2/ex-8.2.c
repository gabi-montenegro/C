#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *f = fopen("arq-01.txt", "r");
    
    char str[26];
    int i = 0;

    char temp;
    while ((temp=fgetc(f)) != EOF){
        str[i] = temp;
        i++;
}

    str[i] = '\0';

    printf("Conteudo do arquivo: %s", str);
    
    fclose(f);

	system("pause");
    return 0;



}
