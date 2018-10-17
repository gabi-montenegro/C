#include <stdio.h>
#include <stdlib.h>


void compra(int *conta, int valor){
	*conta-=valor;
}

int main(void){
	
	int minha_conta1;
	int minha_conta2;
	int *p;
	int compras[] = {100, 50, 80, 30, 20};
	
	printf("Digite o valor da conta 1: ");
	scanf("%d", &minha_conta1);
	
	printf("Digite o valor da conta 2: ");
	scanf("%d", &minha_conta2);
	
	int valor;
	for (int i=0; i<5;i++){
		valor = compras[i];
	
	
	
	if (minha_conta1>minha_conta2){
		p=&minha_conta1;
	
	}else{
		p=&minha_conta2;
	
	}
	
	compra(p,valor);
	
	printf("Conta 1: %d ----- Conta 2: %d\n", minha_conta1, minha_conta2);}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
	return 0;
}