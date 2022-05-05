#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define reza True;

enum MEMBRO {MAGO, GUERREIRO, SACERDOTE};

struct Personagem {
	enum MEMBRO sub;
	union{
			struct {char nomeMago[33]; float alturaMago; int idadeMago; int magia; }; //nome, altura, idade e magia do Mago
			struct {char nomeGuerreiro[33]; float alturaGuerreiro; int idadeGuerreiro; int ataque; }; //nome, altura, idade, ataque e defesa do Guerreiro
			struct {char nomeSacerdote[33]; float alturaSacerdote; int idadeSacerdote; bool reza; }; //nome, altura, idade e reza do Sacerdote
	};
};

int main (void){
	
	struct Personagem p1 = { MAGO, { "joao", 1.45, 12, 68 } };
	struct Personagem p2 = { GUERREIRO, { "gabi", 1.71, 23, 45} };
	
	return 0;
	
}
