#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t, tM, tm, vit, derr, emp, soma, somaM, somam, i;

    somaM=0;
    somam=1000;
    for (i=1;i<=20;i++){
        printf("Digite o numero do time: \n");
        scanf("%d", &t);
        printf("Insira o numero de vitorias: \n");
        scanf("%d", &vit);
        printf("Insira o numero de derrotas: \n");
        scanf("%d", &emp);
        printf("Insira o numero de empates: \n");
        scanf("%d", &emp);


        soma=(vit*3)+(derr*0)+emp;
        if (soma>somaM){
            tM=t;
            somaM=soma;
        }else{
            if (soma<somam){
                tm=t;
                soma=somam;
            }//fim do if

        }//fim do else

    }//fim do for
        printf("Time com maior potuacao: %d \n", tM);
        printf("Time com menor potuacao: %d \n", tm);
    system("pause");
    return 0;
}// fim do programa

//No 07.png, simplifiquei com 3 times.