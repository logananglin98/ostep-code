#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{   
    int rc = fork();
    int parentPID = getpid();
    int status;

    if (rc < 0) { // error
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) { // child
        printf("This should be printed first.\n");
        printf("This should be printed second.\n");
        waitpid(parentPID, &status, 0);
        printf("This should be printed third.\n");
        printf("Child PID %d\n", getpid());
    } else { // parent
        waitpid(parentPID + 1, &status, 0);
        printf("This should be printed last.\n");
        printf("Parent PID %d\n", getpid());
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 6: waitpid() would be useful if the program creates multiple children. I noticed that the waitpid() in line 19 didn't work. I presume this is because child processes 
   can't be made to wait for parent processes. 
*********************************************/