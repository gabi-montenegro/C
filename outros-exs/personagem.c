#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*struct Mago{
	int magia;
};

struct Guerreiro{
	short int ataque;
	short int defesa;
};*/
enum MEMBRO {MAGO, GUERREIRO, SACERDOTE};
struct Personagem {
	char nome[33];
	int altura;
	int idade;
	enum MEMBRO sub;
	union{
			struct {int magia; }; //Mago
			struct {short int ataque; short int defesa; }; //Guerreiro
			struct {bool reza; }; //Sacerdote
	};
};

int main (void){
	
	
	

	return 0;
	
}