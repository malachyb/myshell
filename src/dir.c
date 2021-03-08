#include <stdio.h>
#include <dirent.h>

char* file_code(int code) {
    char* dir_code = "\033[32m";
    char* file_code = "\033[37m";
    if (code == 4)
        return dir_code;
    return file_code;
}

int main(int argc, char* argv[]) {
    char* dir_loc = ".";
    struct dirent *curr_dir;
    if (argc > 1)
        dir_loc = argv[1];
    DIR *directory = opendir(dir_loc);
    if(directory) {
        while((curr_dir = readdir(directory)) != NULL)
            printf("%s%s\n", file_code(curr_dir->d_type), curr_dir->d_name);
    }
    return 0;
}
