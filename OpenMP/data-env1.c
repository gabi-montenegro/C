#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


int main() {
	
	int x = 100;

    #pragma omp parallel first private (x)
    { 
        printf("valor de x: %d", x);
        //se declarar aa variavel x dentro do bloco, cada thread vai ter sua versão da variável ou inserir a diretiva acima que copia o valor inicial
        x = omp_get_thread_num();
        if (x != omp_get_thread_num()){ 
            printf("Sou a thread %d, meu valor de x é %d\n", omp_get_thread_num(), x);	
        }
        }
	return 0;
}