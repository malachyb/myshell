#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) {
    for (char** env_var = envp; *env_var != 0; env_var++) {
        printf("%s\n", *env_var);
    }
}
