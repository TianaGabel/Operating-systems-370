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
    const char *divisor = argv[1];
    for (int i = 2; i <6 ; i++){
        const char *workingNumber = argv[i];
        pid = fork();
        //Failed Process
        if (pid < 0){
            printf("failed to create process in loop %d \n", i);
            exit(0);

        //Child process    
        } else if (pid == 0){
        execlp("checker","Checker", divisor, workingNumber, NULL);
        printf("Failed execlp\n");

        //Parent process
        } else {
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf( "Coordinator: waiting for process[%d].\n", pid);
            int status;
            wait(&status);
            int result =WEXITSTATUS(status);
            printf("Coordinator: child process %d returned %d.\n", pid,result);
        }
    }
    printf( "Coordinator: exiting.\n");
}
