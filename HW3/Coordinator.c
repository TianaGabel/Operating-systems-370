#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, const char *argv[]) 
{

    if (argc != 6){
        printf("incorrect number of args \n %d", argc);
        exit(0);
    }
    
    pid_t pid[5];
    int smsID[5];
    const char *divisor = argv[1];
    for (int i = 0; i <4 ; i++){
        const char *workingNumber = argv[i+2];

        //Create pipe
        int fd[2];
        pipe(fd);

        smsID[i] = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

        pid[i] = fork();
        //Failed Process
        if (pid[i] < 0){
            printf("failed to create process in loop %d \n", i);
            exit(0);
        //Child process    
        } else if (pid[i] == 0){
            char buffer[8];
            sprintf(buffer, "%d", fd[0]);
            execlp("checker", divisor, workingNumber, buffer, NULL);
            printf("Failed execlp\n");

        //Parent process
        } else {
            printf("Coordinator: forked process with ID %d.\n", pid[i]);
            //write to pipe
            close(fd[0]);
            write(fd[1],&smsID[i], sizeof(smsID[i]));
            close(fd[1]);
            printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", smsID[i], sizeof(smsID[i]));
        }

    }
    for (int i = 0; i <4 ; i++){
        printf( "Coordinator: waiting on child process ID %d...\n", pid[i]);
        int *sharedMemoryPointer = (int*)shmat(smsID[i], NULL, 0);
        int status;
        waitpid(pid[i], &status, WEXITSTATUS(status));

        int divisor = atoi(argv[1]);

        int dividend = atoi(argv[i+2]);
        
        if (sharedMemoryPointer == 0){
            printf("Coordinator: result 0 read from shared memory: %d is divisible by %d.\n",dividend,divisor);
        } else {
            printf("Coordinator: result 1 read from shared memory: %d is divisible by %d.\n",dividend,divisor);
        }
        

        shmctl(*sharedMemoryPointer, IPC_RMID, NULL);
        
    }
    
    printf( "Coordinator: exiting.\n");
    
}
