#include <stdio.h>
#include <stdlib.h>


int N; //ESTÁTICA
typedef struct No{
	char Chave;
	int Elemento;
    struct No *prox;
}No;
typedef struct ListaLinear{
	No *inicio;
} ListaLinear;

void Exibe(struct ListaLinear *L) {
    //No *p -> PILHA
    //malloc(sizeof(No)) -> HEAP
    struct No *p = (No*)malloc(sizeof(No));
    p = L->inicio;
    while(p != NULL){
        if(p->prox == NULL){
            printf("%c: %d\n", p->Chave, p->Elemento);
        }else{
            printf("%c: %d -> ", p->Chave, p->Elemento);
        }
        
        p = p->prox;
    }
}

//insere no começo da lista
void Insere(struct ListaLinear *L, int c, int ele) {
    //int c, int ele, No *novo -> PILHA
    //malloc(sizeof(No)) -> HEAP
    struct No *novo = (No*)malloc(sizeof(No));
    novo->Chave = c;
    novo->Elemento = ele;
    novo->prox = L->inicio;
    L->inicio = novo;
    N = N+1;
}

int Busca(ListaLinear *L, int c){
    //int c, No *p -> PILHA
    //malloc(sizeof(No)) -> HEAP
    struct No *p = (No*)malloc(sizeof(No));
    p = L->inicio;
    while(p != NULL && p->Chave != c){
        p = p->prox;
    }
    if(p != NULL){
        int elemento = p->Elemento; //PILHA
        free(p);//HEAP
        return elemento;
    }else{
        return -1;
    }

}


//destroi
void Destroi(ListaLinear *L){
    //No *p, No *pprox -> PILHA
    //malloc(sizeof(No)) -> HEAP
    struct No *p = (No*)malloc(sizeof(No)); 
    struct No *pprox = (No*)malloc(sizeof(No));
    pprox = L->inicio;
    while(pprox != NULL) {
        pprox = pprox->prox;
        p = pprox;
        free(p);//HEAP
    }

}

//k-esimo elem
int kEsimo(No *p1, int k) {
    //int k -> PILHA
    if (p1 == NULL){
        return -1;
    }
    if (k == 1) {
        return p1->Elemento;
    }else{
        return kEsimo(p1->prox, k-1);
    }
}

int main(void){
    //ListaLinear *L -> PILHA
    //malloc(sizeof(ListaLinear)) -> HEAP
    struct ListaLinear *L = (ListaLinear*)malloc(sizeof(ListaLinear));
	
    Insere(L, 'A', 1);
    Insere(L, 'B', 2);
    Insere(L, 'C', 3);
    Insere(L, 'D', 4);
    Insere(L, 'E', 5);
    Exibe(L);
  

    printf("Busca do 'C': %d\n", Busca(L, 'C'));
  
    //No *p1 -> PILHA
    //malloc(sizeof(No)) -> HEAP
    struct No *p1 = (No*)malloc(sizeof(No));
    p1 = L->inicio;
    printf("K-Esimo 2: %d\n", kEsimo(p1, 2));

    Destroi(L);

	
	
	
  return 0;
}