#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

typedef int bool;
#define true 1
#define false 0
bool eh_primo(int n){
	bool primo=true;
	for (int i=2;i<n;i++){
        if (n%i==0){
            primo=false;
        }

	}

return (primo);
}
//Funcao principal

int main(){
int n;
printf("Digite um numero: ");
scanf("%d", &n);
bool verificacao=eh_primo(n);
if (verificacao==true){
    printf("E primo!\n");
}else{
    printf("Nao e primo!\n");

}
system("pause");
}


