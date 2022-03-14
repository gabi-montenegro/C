#include <stdio.h>
#include <stdlib.h>
//produto escalar

struct vetor{
    int x, y, z;
};

void preenche (struct vetor *v){
	printf("Digite x: ");
	scanf("%d", &(*v).x);
	printf("Digite y: ");
	scanf("%d", &(*v).y);
    printf("Digite z: ");
	scanf("%d", &(*v).z);
}

int prodEscalar(struct vetor *v1, struct vetor *v2){
	int x = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return x;
}


int main (void){
	struct vetor v1;
    printf("----Vetor 1-----\n");
	preenche(&v1);
    struct vetor v2;
    printf("----Vetor 2------\n");
    preenche(&v2);

	printf("---Produto Escalar----\n");
    int prod = prodEscalar(&v1, &v2);
	printf("%d\n", prod);

	

	//system("pause");
	return 0;
	
}