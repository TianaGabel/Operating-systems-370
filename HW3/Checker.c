#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    //will get 1 and A
    pid_t pid = getpid();

    printf("Checker process [%d]: Starting.\n", pid);

    int divisor = atoi(argv[0]);

    int dividend = atoi(argv[1]);
    int returnCode;

    int fd = atoi(argv[2]);
    int smsID;

    read(fd, &smsID, sizeof(smsID));
    printf("Checker process [%d]: read %d bytes containing shm ID %d \n",pid,sizeof(smsID), smsID);
    //location of the sms
    int *sharedMemoryPointer = (int*)shmat(smsID, NULL, 0);

    //TODO: read 4 bytes containing shm ID
    //Put the calculations here
    if ((dividend % divisor) == 0){
        //Case is divisible
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid,dividend, divisor);
        sharedMemoryPointer = 1;
         printf("Checker process [%d]: wrote result (%d) to shared memory.\n", pid, 1);
    } else {
        //Case is not divisible
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid,dividend, divisor);
        sharedMemoryPointer = 0;
         printf("Checker process [%d]: wrote result (%d) to shared memory.\n", pid, 0);
    }
   

    //detach from sms
    shmdt(sharedMemoryPointer);

}