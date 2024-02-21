#include <stdlib.h>
#include <stdio.h>
#include "Checker.h"
#include <sys/resource.h>


int main(int argc, const char *argv[]) 
{
    if (argc != ){
        printf("incorrect number of args \n %d", argc);
        exit(0);
    }
    
    const char *divisor = argv[0];
    for (int i = 1; i <5 ; i++){
        const char *workingNumber = argv[i];
        if (fork() < 0){
            printf("failed to create process in loop %d \n", i);
            //TODO log errors??? process failed to be created
            exit(0);
        }
        printf("actually made it here");
        execlp("Checker.c", divisor, workingNumber, NULL);
        //fork() return the value of the fork and print the PID
        //Run execlp() to load the checker code to newly created process
        //wait() until execuation of checker completes

    }
//print PID
//Print result
//return success or error

//print exit code

}
