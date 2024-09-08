#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int adgc, char *argv[]) {
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Child process value: %d\n", x);
    } else {
        printf("Parent process value: %d\n", x);
    }
    return 0;
}