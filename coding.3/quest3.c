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
        printf("Hello!\n");
    } else { // parent
        sleep(1);
        printf("Goodbye!\n");
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 3: Using wait() of course made these processes finish correctly. I utilized the sleep function to accomplish the same results without wait(). I noticed that using
   sleep(0.5) would make the order random, but using sleep(1) consistently makes the parent finish last.
*********************************************/