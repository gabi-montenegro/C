#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

typedef int bool;
#define true 1
#define false 0
int eh_primo(int n){
	bool primo=true;
	for (int i=2;i<n;i++){
        if (n%i==0){
            primo=false;
        }

	}

return primo;
}

int main(void){
int n;
printf("Digite um numero: ");
scanf("%d", &n);
for(int i=1;i<=n;i++){
if (eh_primo(i)){
    printf("%d: E primo!\n",i);
}else{
    printf("%d: Nao e primo!\n",i);

}
}
system("pause");
}
