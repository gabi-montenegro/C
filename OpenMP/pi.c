#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, i;
    double mypi, pi, h, sum, x, a;
    n = 20;
    h = 1.0 / (double) n;
    sum = 0.0;

    #pragma omp parallel for shared(n,h) private(i,x) reduction(+:sum)
    for (i = 1; i <= n; i ++) {
        x = h * ((double) i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }

    mypi = h * sum;


    printf("pi is approximately %.16f\n", mypi);
    return 0;
}