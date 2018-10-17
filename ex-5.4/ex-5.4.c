#include <stdio.h>
#include <stdlib.h>

void troca (int *p1, int *p2){
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
	
}


int main(void){
	int x = 10;
	int y = 20;
	
	troca(&x, &y);
	
	printf ("X ----> %d\nY -----> %d\n", x , y);
	
	system("pause");
	return 0;
}