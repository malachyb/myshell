#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* file = "readme";
    if (argc > 1) {
        file = argv[1];
    }
    char* comm = (char*) calloc(256, sizeof(char));
    strcat(comm, getenv("PATH"));
    strcat(comm, "/cat ");
    strcat(comm, getenv("PATH"));
    strcat(comm, "/../manual/");
    strcat(comm, file);
    system(comm);
    return 0;
}