#include <stdio.h>
//na função fat, como a variável n é inteiro (um inteiro ocupa 4 bytes de memória) e temos n (??) chamadas recusivas
double fat (int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fat(n-1);
    }
}

double vec[100]; //800 bytes de memória

void main (void) {
    //para cada laço, usa-se 4 bytes de memória
    for (int i=0; i<100; i++) {
        vec[i] = fat(i);
    }

    //printf("\n%li\n", sizeof(vec));
    
    
}
