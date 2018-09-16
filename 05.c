#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int soma = 0;

    while (n!=0){
        printf("Digite um numero: ");
        scanf("%d", &n);
        soma+=n;
    }

    printf("Soma dos numeros: %d", soma);
    system("pause");
    return 0;
}