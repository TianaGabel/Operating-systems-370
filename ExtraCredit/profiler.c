#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char createArrayOfStrings() {
    
}

int main(int argc, char *argv[]) {

    //Argc is num of args, argv is an array of 'strings'
    char *pid = argv[1];
    printf("checking pid %s\n",pid);

    char path[] = "/proc/";
    char fname[] = "/stat";
    strcat(path,pid);
    strcat(path,fname);
    printf("checking path name %s\n",path);
    FILE *file = fopen(path, "r");

    if (file == NULL){
        //TODO: Gracefully give a message that the process was not found
        printf("Pid %s was not found\n",pid);
        return EXIT_FAILURE;
    }

    char line[256];
    //This gets a line of size line
    if(fgets(line,sizeof(line),file) == NULL){
        //This means that the file failed to read anything
        fclose(file);
        printf("File did not contain information\n",pid);
        return EXIT_FAILURE;
    }
    //stat file
    char *token = strtok(line, " ");
    char *tokens[15];

    for(int i = 1; i < 15; ++i){
        tokens[i] = token;
        token = strtok(NULL, " ");
    }
    
    printf("checking pid %s\n",tokens[1]); // col 1
    printf("%-25s", "Executable:");
    printf("%s\n",tokens[2]); // col 2
    printf("%-25s", "ppid:");
    printf("%s\n",tokens[4]); // col 4
    printf("%-25s", "pgrp:");
    printf("%s\n",tokens[5]); // col 5
    printf("%-25s", "State:");
    printf("%s\n",tokens[3]); // col 3
    
    float userMode = atoi(tokens[14]) * 1.0 / sysconf(_SC_CLK_TCK);
    float kernelMode = atoi(tokens[15]) * 1.0 / sysconf(_SC_CLK_TCK);
    printf("%-25s", "User mode:");
    printf("%.4f sec\n",userMode); // utime col 14
    printf("%-25s", "Kernel mode:");
    printf("%.4f sec\n",kernelMode); //stime col 15

    
    // printf("%-25s", "Virtual memory:");
    // printf("%s\n",token[1]); //size col 1
    // printf("%-25s", "Resident pages:");
    // printf("%s\n",token[1]); //col 2
    // printf("%-25s", "Shared pages:");
    // printf("%s\n",token[1]); // col 3
    // printf("%-25s", "Page faults:");
    // printf("%s\n",token[1]); //majflt col 12

    fclose(file);

    return EXIT_SUCCESS;
}