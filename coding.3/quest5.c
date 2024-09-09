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
        printf("This should be printed first.\n");
        printf("This should be printed second.\n");
        wait(0);
        printf("This should be printed third.\n");
    } else { // parent
        wait(0);
        printf("This should be printed last.\n");
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 5: I ran this program once with no wait calls. The parent printed first as expected. I then added the wait call on line 20. This made the print statements execute in
   order with all of the print statements in the child block executing before the parent block. I then added the wait call on line 17 expecting the order to be 
   first-second-last-third, but running the code with this extra wait call yeilded the same results as when the first wait was added; the third print statement was ran before the 
   last print statement. This may mean that wait calls in the child block are negated.
*********************************************/