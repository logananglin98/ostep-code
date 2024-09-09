#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSZE 32

/* #8 Write a program that creates two children, and connects the standard
output of one to the standard input of the other, using the
pipe() system call */

int
main(int argc, char *argv[])
{
    // Setup our pipe
    char buff[BUFSZE];
    int p[2];

    if (pipe(p) < 0)
      exit(1);

    int rc1 = fork();
    if (rc1 < 0) { // error
        fprintf(stderr, "fork 1 failed\n");
        exit(1);
    } else if (rc1 == 0) { // Child 1
       printf("Child 1\n");
       close(p[0]);
       dup2(p[1], 1);
       printf("This line will be piped to another process.\n");
    } else { // Parent
        int rc2 = fork();
        if (rc2 < 0) { // error
        fprintf(stderr, "fork 2 failed\n");
        exit(1);
        } else if (rc2 == 0) { // child 2
          printf("Child 2\n");
          close(p[1]);
          dup2(p[0], 0);
          char buff[512];
          read(STDIN_FILENO, buff, 512);
          printf("%s", buff);

        } else {
          waitpid(rc2, NULL, 0);
          printf("goodbye");
        }
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 8: Using pipe made the program execute so the print stateent on line 31 was executed during the running of the second child even though it was created in the first 
   child.
*********************************************/