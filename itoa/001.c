// Create a function to convert an integer to string.
// This solution implements pointers

#include <stdlib.h>
#include <stdio.h>

/**
 * @fn int itoa(int n, char**s)
 * @brief Converts an integer into a string.
 * @param[in]  n The integer value to convert.
 * @param[out] s The string storing the converted integer as double pointer. Must be free manually.
 * @return A status code indicating the execution result.
 * @retval 0 The conversion was successful.
 * @retval 1 Indicates a memory assignation error.
 */
int itoa(int n, char **s);

int main() {
    int n = 0;
    char *ns;

    if ( itoa(n, &ns) == -1 ) {
        printf("Memory assignation error!\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", ns);
    free(ns);

    return EXIT_SUCCESS;
}

int itoa(int n, char **s) {
    int nlen = 0, n2 = n;

    // Finds the length of n
    while (n2 /= 10) nlen++;
    // Adds one more position for negative sign
    if (n < 0) nlen++;

    // Assigns the memory for *s and initialize it with zeros
    *s = (char*) calloc(nlen, sizeof(char));
    if (s == NULL) return 1;

    // Handles negative integer
    if (n < 0) {
        n = -n; // n is positive integer now
        **s = '-';
    }

    // Converts n to string
    do *(*s + nlen--) = n % 10 + '0'; while (n /= 10);
    // This write ascii chars from the right to the left

   return 0;
}