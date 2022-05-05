#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define reza True;

enum MEMBRO {MAGO, GUERREIRO, SACERDOTE};

struct Personagem {
	char nome[33]; //nome do personagem
	float altura; //altura do personagem
	int idade; //idade do personagem
	enum MEMBRO sub;
	union{
			struct {int magia; }; //magia do Mago
			struct {short int ataque; short int defesa; }; //ataque e defesa do Guerreiro
			struct {bool reza; }; //reza do Sacerdote
	};
};

int main (void){
	
	struct Personagem p1 = {"joao", 1.45, 12, MAGO, {68}};
	struct Personagem p2 = {"gabi", 1.71, 23, GUERREIRO, {45, 32}};
	
	return 0;
	
}
