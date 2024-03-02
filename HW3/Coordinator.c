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

    
//     pid_t pid1 = fork();
//     pid_t pid2 = fork();
// for (int i = 0; i < 2; i++){
//     if (pid == 0)
//     {
//         int status;
//         wait(&status);
//         printf("finished child value %d\n", i);
//         break;
//     }else if (pid > 0){
//         printf("Created child %d\n", i);
//         if ()
//     }
    
//     }
//     int status;
//     wait(&status);
//     printf("PID = %d\n", pid);


    if (argc != 6){
        printf("incorrect number of args \n %d", argc);
        exit(0);
    }
    
    pid_t pid;
    const char *divisor = argv[1];
    for (int i = 2; i <6 ; i++){
        const char *workingNumber = argv[i];

        //Create pip
        int fd[2];
        pipe(fd);

        int smsID = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

        pid = fork();
        //Failed Process
        if (pid < 0){
            printf("failed to create process in loop %d \n", i);
            exit(0);

        //Child process    
        } else if (pid == 0){
            char buffer[8];
            sprintf(buffer, "%d", fd[0]);
            execlp("checker", divisor, workingNumber, buffer, NULL);
            printf("Failed execlp\n");

        //Parent process
        } else {
            printf("Coordinator: forked process with ID %d.\n", pid);
            //write to pipe
            close(fd[0]);
            write(fd[1],&smsID, sizeof(smsID));
            close(fd[1]);
            printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", smsID, sizeof(smsID));
        }
        printf( "Coordinator: waiting for process[%d].\n", pid);
        int status;
        wait(&status);
        //int result =WEXITSTATUS(status);
        int *sharedMemoryPointer = (int*)shmat(smsID, NULL, 0);
        shmctl(*sharedMemoryPointer, IPC_RMID, NULL);
        
    }
    
    printf( "Coordinator: exiting.\n");
    
}
