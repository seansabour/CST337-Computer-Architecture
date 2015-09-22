#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints Result in binary
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
        fprintf (stderr, "error: insufficient input. usage: %s b1 b2\n", argv[0]);
        return 1;
    }
    /* input conversion and bitwise operation */
    unsigned long b1 = strtoul (argv[1], NULL, 2);
    unsigned long b2 = strtoul (argv[2], NULL, 2);
    char logicGate[5];
    unsigned long result;

    /* Get input from user of which logical gate behavior to use */
    printf("What logical gate behavior would you like to simulate? (AND, OR, XOR, NAND)\n");
    scanf("%4s", &logicGate);

    /* String comparison to match user inputted behavior, perform behavior and print results */
    if(strcmp(logicGate, "AND") == 0){
        result = b1 & b2;
        printResult(result);
    } else if(strcmp(logicGate, "OR") == 0){
        result = b1 | b2;
        printResult(result);
    } else if(strcmp(logicGate, "XOR") == 0){
        result = b1 ^ b2;
        printResult(result);
    } else if(strcmp(logicGate, "NAND") == 0){
        result = ~(b1 & b2);
        printResult(result);
    } else {
        printf("Sorry you did not enter a valid logic gate behavior\n");
    }

	return 0;
}

