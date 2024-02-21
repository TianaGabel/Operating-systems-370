#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    //will get 1 and A
    pid_t pid = getpid();

    int divisor = atoi(argv[1]);

    int dividend = atoi(argv[2]);

    printf("Checker process [%d]: Starting.\n", pid);
    //Put the calculations here
    //This will need a bit more in the string formatting, and possible concatenating strings
    printf("Checker process [%d]: %d *IS* divisible by %d\n", pid,dividend, divisor);

    printf("Checker process [%d]: Returning 1.\n", pid);
    return 0;
}


int is_divisable(int * a, int * b)
{
   return (-1);
}