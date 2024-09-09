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
        execl("/bin/ls", "ls", "-l", NULL);
    } else { // parent
        char *args[] = {"ls", NULL};
        execv("/bin/ls", args);
    }
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 4: exec("/bin/ls") would not work. execv() and execvp() with the args set to ls and NULL yeilded the exact same results. execl seems to have listed much more information
   including file permissions, the date the files in the directory were created. I would imagine the other variationss of exec() allow for more customization of how the process is 
   executed. 
*********************************************/