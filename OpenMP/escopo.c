#include <stdio.h>
#include <string.h>
#include <omp.h>

int main (void){

    char nome[25] = {"Gabriella"};
    int idade = 20;
    char cidade[3] = {"RJ"};

    #pragma omp parallel firstprivate(nome, idade) shared(cidade)
    {
        strcat(nome, " Montenegro");
        idade += 4;
        printf("Meu nome é %s. Tenho %d anos e moro no %s!\n", nome, idade, cidade);
        
    }
    

    return 0;
}