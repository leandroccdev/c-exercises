// Exercise:
// Create a function to calculate the length of an integer.
// This solution implements the iterative method of division by 10.

// How to compile this exercise?
// gcc -g 001.c -o 001
// -g: adds debug information for gdb debugger.
// How to execute the binary file?
// Sets the file as executable: chmod +x 001
// Runs the file: ./001

#include <stdlib.h>
#include <stdio.h>

/**
 * @fn int ilen(int n)
 * @brief Return the length of an integer n.
 * @param[in] n The integer whose length to calculate.
 * @return The length of n.
 * @retval A positive integer.
 */
int ilen(int n);

int main() {
    // The integer whose length is calculated
    int n = -82873;

    printf("The length of '%d' is: %d\n", n, ilen(n));

    return EXIT_SUCCESS;
}

int ilen(int n) {
    int nlen = 1;
    while (n /= 10) nlen++;
    return nlen;
}