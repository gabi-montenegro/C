#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vAtual, v;
    printf("Velocidade atual em (mph): ");
    scanf("%d", &vAtual);

    v = vAtual * 1.6;

    if (v < 80){
        printf("Acelere!\n");
    }else{
        if (v < 100 ){
            printf("Mantenha!\n");
    }   else{
        printf("Desacelere!\n");
    }}

    system("pause");
    return 0;
}