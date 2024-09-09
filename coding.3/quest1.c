#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int adgc, char *argv[]) {
    int x = 100;
    int rc = fork();
    if (rc < 0) { // error
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child
        x += 200;
        printf("Child process value: %d\n", x);
    } else { // parent
        printf("Parent process value: %d\n", x);
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 1: Because x is initialized to 100 before the fork is created, both the parent and child processes start with x = 100. I added x += 200
   on line 13 to verify that changing x in the child process would not change x in the parent process. Any changes in the else if and else selections
   will only affect the variable in the child or parent processes respectively.
*********************************************/