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
    int returnCode;

    printf("Checker process [%d]: Starting.\n", pid);
    //Put the calculations here
    if ((dividend % divisor) == 0){
        //Case is divisible
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid,dividend, divisor);
        returnCode = 1;
    } else {
        //Case is not divisible
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid,dividend, divisor);
        returnCode = 0;
    }
    printf("Checker process [%d]: Returning %d.\n", pid, returnCode);
    return returnCode;
}


int is_divisable(int * a, int * b)
{
   return (-1);
}