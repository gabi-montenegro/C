#include <stdio.h>
#include <stdlib.h>


int N; 
typedef struct No{
	int Elemento;
    struct No *prox;
}No;
//typedef struct ListaLinear{
//	No *inicio;
//} ListaLinear;

int main(void){
    struct No *no1 = (No*)malloc(sizeof(No));
    struct No *no2 = (No*)malloc(sizeof(No));
    struct No *no3 = (No*)malloc(sizeof(No));
    struct No *no4 = (No*)malloc(sizeof(No));

    no1->Elemento = 1;
    no2->Elemento = 2;
    no3->Elemento = 3;
    no4->Elemento = 4;

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = NULL;

    /* struct No *p = (No*)malloc(sizeof(No));
    p = no1;
    while(p != NULL){
       printf("---%d---\n", p->Elemento);
       p = p->prox; 
    } */

    return 0;
    
}