#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tamLista;
typedef struct No{
	char Elemento;
    struct No *prox;
}No;
typedef struct ListaLinear{
	No *inicio;
} ListaLinear;

typedef struct NoPilha{
    int Elemento;
    struct NoPilha *prox;
}NoPilha;

typedef struct Pilha{
    NoPilha *inicio;
    int N;
}Pilha;

void tamanho(Pilha *P) {
    return P->N;
}

int topo(Pilha *P){
    return P->inicio->Elemento;
}

void push(Pilha *P, int elem){
    struct NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->Elemento = elem;
    novo->prox = P->inicio;
    P->inicio = novo;
    P->N = P->N + 1;
}

int pop(Pilha *P) {
    if (P->inicio !=  NULL) {
        struct NoPilha *noRemover = (NoPilha*)malloc(sizeof(NoPilha));
        noRemover = P->inicio;
        int x = P->inicio->Elemento;
        P->inicio = P->inicio->prox;
        P->N = P->N + 1;
        free(noRemover);
        return x;
    }
}

void Insere(struct ListaLinear *L, char ele) {
    struct No *novo = (No*)malloc(sizeof(No));
    novo->Elemento = ele;
    novo->prox = L->inicio;
    L->inicio = novo;
    tamLista = tamLista+1;
}

void avalia(ListaLinear *L, Pilha *P){
    struct No *no = (No*)malloc(sizeof(No));
    no = L->inicio;

    for(int i = 0; i < tamLista - 1; i++){
        switch(no->Elemento){
            case '+':
                no = no->prox;
                soma(P);
                break;
            case '-':
                no = no->prox;
                sub(P);
                break;
            case '/':
                no = no->prox;
                div(P);
                break;
            case '*':
                no = no->prox;
                mult(P);
                break;
            default:
                converte(no->Elemento, P);
                no = no->prox;
                break;
    }
    }

    //resultado
    printf("%d", P->inicio->Elemento);

}

void converte(char num, Pilha *P){
    int n;
    switch(num){
        case '0':
            n = 0;
            break; 
        case '1':
            n = 1;
            break;
        case '2':
            n = 2;
            break;
        case '3':
            n = 3;
            break;
        case '4':
            n = 4;
            break;
        case '5':
            n = 5;
            break;
        case '6':
            n = 6;
            break;
        case '7':
            n = 7;
            break;
        case '8':
            n = 8;
            break;
        case '9':
            n = 9;
            break;
    }

    push(P, n);
}

void soma(Pilha *P){
    int n1 = pop(P);
    int n2 = pop(P);
    int numSoma = n1 + n2;
    push(P, numSoma);
}


void sub(Pilha *P){
    int n1 = pop(P);
    int n2 = pop(P);
    int numSub = n1 - n2;
    push(P, numSub);
}

void div(Pilha *P){
    int n1 = pop(P);
    int n2 = pop(P);
    int numDiv = n1 / n2;
    push(P, numDiv);
}

void mult(Pilha *P){
    int n1 = pop(P);
    int n2 = pop(P);
    int numMult = n1 * n2;
    push(P, numMult);
}


int main(void){
     struct ListaLinear *L = (ListaLinear*)malloc(sizeof(ListaLinear));
     struct Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
     Insere(L, '+');
     Insere(L, '1');
     Insere(L, '*');
     Insere(L, '-');
     Insere(L, '5');
     Insere(L, '*');
     Insere(L, '-');
     Insere(L, '1');
     Insere(L, '4');
     Insere(L, '7');
     Insere(L, '3');

    avalia(L, pilha);


    return 0;
}