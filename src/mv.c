#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Error: needs two files as arguments");
        return 1;
    }
    if (rename(argv[1], argv[2]) != 0)
        printf("Error: cannot move file to that location");
    return 0;
}