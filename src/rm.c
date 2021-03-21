#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Error: file must be provided\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if(remove(argv[i]) != 0)
            printf("Error removing %s\n", argv[i]);
    }
    return 0;
}