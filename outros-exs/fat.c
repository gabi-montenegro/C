#include <stdio.h>
//na função fat, como a variável n é inteiro (um inteiro ocupa 4 bytes de memória) e temos n chamadas recusivas, logo teremos 4n bytes de memória.
double fat (int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fat(n-1);
    }
}

double vec[100]; //800 bytes de memória para vec[100], pois um double ocupa 8 bytes de memória, logo 8 * 100 = 800 bytes.

void main (void) {
    //para cada laço, usa-se 4 bytes de memória para a variável i, pois um int equivale a 4 bytes de memória.
    for (int i=0; i<100; i++) {
        vec[i] = fat(i);
    }

    //printf("\n%li\n", sizeof(vec));
    
    
}
