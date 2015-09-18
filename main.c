#include <stdio.h>
#include <stdlib.h>
void printResult(unsigned long result){
    int k, c;
    for(c = 7; c >= 0; c--) {
        k = result >> c;

        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
int main( int argc, char *argv[] ) {
    if ( argc < 3) {
        fprintf (stderr, "error: insufficient input. usage: %s b1 b1\n", argv[0]);
        return 1;
    }
    /* input conversion and bitwise operation */
    unsigned long b1 = strtoul (argv[1], NULL, 2);
    unsigned long b2 = strtoul (argv[2], NULL, 2);
    unsigned long result = b1 & b2;
    printResult(result);

	return 0;
}
