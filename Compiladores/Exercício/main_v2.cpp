#include <iostream>
#include <stdio.h>
#include <string>


//NOME TOKENS
#define IF  256;
#define THEN  257;
#define ELSE  258;
#define RELOP  259;
#define ID  260;
#define NUM  261;


//ATRIBUTOS (associado aos tokens q vao ser gerados. Se for uma palavra reservada, nao tera atributo associado. Se for um id, o atributo associado vai ser um ponteiro para a estrutura de dados que esta armazenando essas informacoes. Se for um número, o valor associado vai ser o proprio numero )
#define LT 262;
#define LE 263;
#define EQ 264;
#define NE 265;
#define GT 266;
#define GE 267;


//estrutura do token q vai ser enviado para o analisador sintatico
typedef struct Token{
 std::string nome_token;
 std::string atributo;
 int linha;
 std::string lexema;
 struct Token *prox;
}Token;

typedef struct ListaDeTokens {
	Token *inicio;
}ListaDeTokens;

ListaDeTokens *L;

int estado = 0; // informa em qual estado o automato está
int partida = 0; //ponto de partida, de qual automato, estou partindo
int cont_sim_lido = 0; // acada simbolo lido, somamos 1. Lendo simbolo a simbolo do codigo-fonte, percorrendo o codigo-fonte(code)
char *code; //codigo-fonte

char *readFile(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	char *code;
	int n = 0;
	int c;

	if(file == NULL) return NULL;

	fseek(file, 0, SEEK_END);
	long f_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	code = new char (f_size);

	while ((c = fgetc(file))!= EOF)
	{
		code[n++] = (char) c;
	}
	code[n] = '\0';
	return code;
}




int falhar() //implementacao de um ponto de partida para outro. Se comecei no 0 e por algum motivo falhou, vou pro 9 e assim vai...
{
	switch(estado)
	{
	case 0: partida = 9; break;

	case 9: partida = 12; break;

	case 12: partida = 20; break;

	case 20: partida = 25; break;

	case 25:
		//retornar msg de erro
		printf("Erro encontrado no código\n");
		cont_sim_lido++;
		break;

	default: printf("Erro do compilador");
	}
	return(partida);
}

//busca pelo lexema na lista
bool buscaLexema(struct ListaDeTokens *L, std::string lexema){

}
//inserir no final da lista
void inserirToken (const std::string nome, const std::string atributo, int linha ,std::string lexema){

}

//exibir token
void exibirToken(struct Token *p) {

}

std::string lexema = "";

struct Token proximo_token() //essa funcao retorna um token que vai ser analisado pelo analisador lexico
{
	Token token;
	char c;
	while(code[cont_sim_lido] != EOF) //assumimos que o codigo-fonte esta carregado na string code.
	{
		switch(estado) //nesse swicth se dá passagem de um estado para outro
		{
			case 0: //cada case (representa um estado) -> em cada estado temos ações desses estados
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if(c == '<') {
					lexema += c;
					estado = 1;
				}
				else if(c == '=') {
					lexema += c;
					estado = 5;
				}
				else if(c == '>'){
					lexema += c;
					estado = 6;
				} 
				else
					{
					 estado = falhar();
					}
				break;

			case 1:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if(c == '='){ 
					lexema += c;
					estado = 2;
				}
				else if(c == '>'){
					lexema += c;
					estado = 3;
				} 
				else{
					lexema += c;
					estado = 4;
				} 
				break;

			case 2:
				cont_sim_lido++;
				printf("<relop, LE>\n");
				if (!buscaLexema(L, lexema)){
					inserirToken("relop", "LE", 256 ,lexema);
				}		
				estado = 0;
				return(token); //retornar o ponteiro que aponta para esse token
				break;
				

			case 3:
				cont_sim_lido++;
				printf("<relop, NE>\n");
				token.nome_token = RELOP;
				token.atributo = NE;
				estado = 0;
				return(token); //retornando o token
				break;

			case 4:
				cont_sim_lido++;
				printf("<relop, LT>\n");
				token.nome_token = RELOP;
				token.atributo = LT;
				estado = 0;
				return(token); //retornando o token
				break;

			case 5:
				cont_sim_lido++;
				printf("<relop, EQ>\n");
				token.nome_token = RELOP;
				token.atributo = EQ;
				estado = 0;
				return(token); //retornando o token
				break;

			case 6:
				cont_sim_lido++;
				c = code[cont_sim_lido];
				if(c == '=') estado = 7;
				else estado = 8;
				break;

			case 7:
				cont_sim_lido++;
				printf("<relop, GE>\n");
				token.nome_token = RELOP;
				token.atributo = GE;
				estado = 0;
				return(token); //retornando o token
				break;

			case 8:
				cont_sim_lido++;
				printf("<relop, GT>\n");
				token.nome_token = RELOP;
				token.atributo = GT;
				//ATENÇÃO - CORREÇÃO: foi acrescentado o comando "estado = 0;"
				estado = 0;
				return(token); //retornando o token
				break;

			case 9:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if (c == 'letra') estado = 10;
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
				}

				break;

			case 10:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if(c == 'letra' || c == 'digito')
				{
					estado = 10;
				}
				else estado = 11;
				break;

			case 11:
				cont_sim_lido++;
				printf("<obter-token()>, instalar-id()");
				//token.nome_token = ?;
				//token.atributo = ?
				return (token); //retornando token
				break;


				/*implementar ações para os estados 10, 11, 12*/

			case 12:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if (c == 'digito') estado = 13;
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
				}
				break;

			case 13:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 13;
				else if (c == 'E') estado = 16;
				else if (c == '.') estado = 14;
				break;


			case 14:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 15;
				break;

			case 15:
				cont_sim_lido;
				c = code[cont_sim_lido];

				if(c == 'digito') estado = 15;
				else if (c == 'E') estado = 16;
				break;

			case 16:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == '+' || c == '-') estado = 17;
				else if (c == 'digito') estado = 18;
				break;

			case 17:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 18;
				break;

			case 18:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 18;
				else if (c == 'outro') estado = 19;
				break;

			case 19:
				cont_sim_lido++;
				printf("<obter-token()>, instalar-id()");
				//token.nome_token = ?;
				//token.atributo = ?
				return (token); //retornando token
				break;


			case 20:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if (c == 'digito') estado = 21;
				else
				{
					/*implementar ações referentes aos estado */
	
					estado = falhar();
				}
				break;

				/*implementar ações para os estados 21-24*/

			case 21:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 21;
				else if (c == '.') estado = 22;
				break;

			case 22:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 23;
				break;

			case 23:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 23;
				else if (c == 'outro') estado = 24;
				break;

			case 24:
				cont_sim_lido++;
				printf("<obter-token()>, instalar-id()");
				//token.nome_token = ?;
				//token.atributo = ?
				return (token); //retornando token
				break;

			case 25:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if (c == 'digito') estado = 26;
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
					token.nome_token = -1;
					token.atributo = -1;
					return(token);
				}
				break;

			case 26:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if (c == 'digito') estado = 26;
				else if (c == 'outro') estado = 27;
				break;

			case 27:
				cont_sim_lido++;
				printf("<obter-token()>, instalar-id()");
				//token.nome_token = ?;
				//token.atributo = ?
				return (token); //retornando token
				break;

				
		}

	}
	token.nome_token = EOF;
	token.atributo = -1;
	return(token);
}

int main(void){
	
}