#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define reza True;

enum MEMBRO {MAGO, GUERREIRO, SACERDOTE};

struct Personagem {
	char nome[33];
	float altura;
	int idade;
	enum MEMBRO sub;
	union{
			struct {int magia; }; //Mago
			struct {short int ataque; short int defesa; }; //Guerreiro
			struct {bool reza; }; //Sacerdote
	};
};

int main (void){
	
	struct Personagem p1 = {"joao", 1.45, 12, MAGO, {68}};
	struct Personagem p2 = {"gabi", 1.71, 23, GUERREIRO, {45, 32}};
	
	return 0;
	
}