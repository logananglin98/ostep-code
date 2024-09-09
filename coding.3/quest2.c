#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    struct stat sb;
    int my_file = open("quest2.txt", O_CREAT | O_RDWR, S_IRWXU);
    
    int rc = fork();

    if (rc < 0) { // error
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) { // child
        const char *child = "Written to by Child\n";
        write(my_file, child , strlen(child));
    } else { // parent
        const char *parent = "Written to by Parent\n";
        write(my_file, parent, strlen(parent));
        exit(0);
    }
    fstat(my_file, &sb);
    lseek(my_file, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(my_file, buffer, sb.st_size);

    printf("Content of file: \n%s", buffer);
    close(my_file);
    return 0;
}

/*********************************************
   Your name: Logan Anglin (anglinl)
   Question 2: It took some time and effort to get the code working, but with the implementation above, both the child and parent processes can write to the file without issue. 
   Using the exit() system call on line 23 seemed to allow both processes to write. The fstat() and lseek() functions helped as well.
*********************************************/