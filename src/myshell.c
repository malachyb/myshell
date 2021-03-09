#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "path.h"

#define MAX_COMM_SIZE 256
#define BOLD "\033[1m"
#define PATH_COLOUR "\033[34m"
#define CLEAR_FORMAT "\033[0m"


int test_comm(char* comm) {
    struct dirent *curr_dir;
    DIR *directory = opendir(PATH);
    if(directory) {
        while((curr_dir = readdir(directory)) != NULL)
            if (strcmp(comm, curr_dir->d_name) == 0)
                return 1;
    }
    return 0;
}

int handle_command(char* command_line, char* dir) {
    char* command = (char*)calloc(30, sizeof(char));
    int command_end;
    for(command_end = 0; command_line[command_end] && command_line[command_end] != ' ' && command_line[command_end] != '\n'; command_end++){}
    strncat(command, command_line, command_end);
    if(strcmp(command, "quit") == 0) {
        free(command);
        return -1;
    }
    if(test_comm(command)) {
        char* curr_comm = (char*)calloc(MAX_COMM_SIZE, sizeof(char));
        strcat(curr_comm, PATH);
        strcat(curr_comm, "/");
        strcat(curr_comm, command_line);
        system(curr_comm);
        free(curr_comm);
        free(command);
        return 0;
    }
    printf("Command not found, try something else\n");
    free(command);
    return 0;
}

int main(int argc, char* argv[]) {
    char directory[PATH_MAX];
    getcwd(directory, sizeof(directory));
    if (argc == 1) {
        char* command_line = malloc(MAX_COMM_SIZE * sizeof(char));
        int comm_res = 0;
        while (comm_res != -1) {
            printf("%s%s%s%s$ ", BOLD, PATH_COLOUR, PATH, CLEAR_FORMAT);
            fgets(command_line, MAX_COMM_SIZE, stdin);
            comm_res = handle_command(command_line, directory);
        }
        free(command_line);

    }
    return 0;
}