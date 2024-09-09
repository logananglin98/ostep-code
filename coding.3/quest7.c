#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{   
    int rc = fork();

    if (rc < 0) { // error
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) { // child
        close(STDOUT_FILENO);
        printf("Wil this make it to the terminal?\n");
    } else { // parent
        wait();
        printf("Parent process complete!\n");
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 7: As expected, using the close(STDOUT_FILENO) call prevented the print statement on the next line in the child block from running. What surprized me was that adding 
   the wait call on line 18 so the close(STDOUT_FILENO) runs before the print statement in parent block didn't prevent that print statement from executing.
*********************************************/