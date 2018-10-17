#include <stdio.h>


int main(){
	int a,b;
	int *p;
	printf("Digite um numero: ");
	scanf("%d", &a);
	printf("Digite outro numero: ");
	scanf("%d", &b);
	
	if (a>b){
		p=&a ;
		
	
	}else{
		p=&b ;
	
	}
	
	*p-=50;
	printf("a: %d\n b:%d\n", a,b);
	
	
	
	
	system("pause");
	return 0;













}