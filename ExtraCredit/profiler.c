#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //TODO: fix this
    //char pid[argc] = argv[1];
    //TODO: we want to read a specific process from args
    FILE *file = fopen("/proc/" + pid + "/stat", "r");

    if (file == NULL){
        //TODO: Gracefully give a message that the process was not found
        return EXIT_FAILURE;
    }

    char line[256];

    //This gets a line of size line
    if(fgets(line,sizeof(line),file) == NULL){
        //This means that the file failed to read anything
        fclose(file);
        return EXIT_FAILURE;
    }

    //stat file
    char *token[] = strtok(line, " ");

    for(int i = 1; i < 12; ++i){
        token[i] = strtok(NULL, " ")
    }

    printf("checking pid %s\n",pid);
    printf("%-25s", "Executable:");
    printf("%s\n",token[1]);
    printf("%-25s", "ppid:");
    printf("%s\n",token[1]);
    printf("%-25s", "pgrp:");
    printf("%s\n",token[1]);
    printf("%-25s", "State:");
    printf("%s\n",token[1]);
    printf("%-25s", "User mode:");
    printf("%s\n",token[1]);
    printf("%-25s", "Kernel mode:");
    printf("%s\n",token[1]);
    printf("%-25s", "Virtual memory:");
    printf("%s\n",token[1]);
    printf("%-25s", "Resident pages:");
    printf("%s\n",token[1]);
    printf("%-25s", "Shared pages:");
    printf("%s\n",token[1]);
    printf("%-25s", "Page faults:");
    printf("%s\n",token[1]);


    return EXIT_SUCCESS;
}