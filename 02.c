#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2;

    prinf("Digite um valor: ");
    scanf("%d", &n1);

    printf("\nDigite outro valor: ");
    scanf("%d", &n2);

    if (n1>n2){
        printf("Maior valor: %d", n1);
    }else{
        printf("Maior valor: %d", n2);

    }

    system("pause");
    return 0;
}