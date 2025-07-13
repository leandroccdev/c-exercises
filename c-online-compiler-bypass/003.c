// Exercise:
// Creates a bypass for C online compilers when
// system function is blocked.

// How to compile this exercise?
// gcc -g 003.c -o 003
// -g: adds debug information for dgb debugger.
// How to execute the binary file?
// Sets the files as executable: chmod +x 003
// runs the file: ./003

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// Defines a custom macro
// token pasting: p1##p2
// Output: p1p2(x)
#define call(p1, p2, x) p1##p2(x)

int main() {
    char *cmd = "whoami";
    int status = call(sys, tem, cmd);
    printf("Comand: %s\n", cmd);
    printf("Status: %d\n", WEXITSTATUS(status));
    return 0;
}