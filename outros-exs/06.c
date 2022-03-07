#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, pot;
    int i = 1;
    int soma = 0;

    printf("Digite um numero: ");
    scanf("%d", &n);

    while (i<=n){
        pot = i*i;
        soma+=pot;
        i+=1;
    }

    printf("\nO somatorio e: %d\n", soma );
    system("pause");


    return 0;
}