#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("%s", argv[1]);
    for(int i = 2; i < argc; i++)
        printf(" %s", argv[i]);
    printf("\n");
    return 0;
}