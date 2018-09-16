#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor;

    printf("Digite o valor do celular: ");
    scanf("%d", &valor);

    int real = valor * 3.17;

    if (real<1000){
        printf("\nBom negocio!");
    }else{
        printf("\nMal negocio!");

    }
    system("pause");
    return 0;
}