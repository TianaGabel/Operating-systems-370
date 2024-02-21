#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>


int main(int argc, const char *argv[]) 
{
    if (argc != 6){
        printf("incorrect number of args \n %d", argc);
        exit(0);
    }
    
    pid_t pid;
    const char *divisor = argv[0];
    //for (int i = 1; i <5 ; i++){
        int i = 1;
        const char *workingNumber = argv[i];
        pid = fork();
        if (pid < 0){
            printf("failed to create process in loop %d \n", i);
            //TODO log errors??? process failed to be created
            exit(0);
        } else if (pid == 0){
        printf("[%d] child process\n", i);
        execlp("checker","Checker", divisor, workingNumber, NULL);
        printf("Failed execlp\n");
        } else {
            //wait();
            printf( "parent [%d]\n", i);
        }
        //fork() return the value of the fork and print the PID
        //Run execlp() to load the checker code to newly created process
        //wait() until execuation of checker completes

    //}
//print PID
//Print result
//return success or error

//print exit code

}
