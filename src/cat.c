#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Error: no file provided\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    char* line = (char*) calloc(256, sizeof(char));
    while (fgets(line, 256, file)) {
        printf("%s", line);
    }
    printf("\n");
    return 0;
}