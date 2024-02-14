#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "findfilepath.h"
int main() {
    if (chdir("/") != 0) {
        perror("chdir");
        return 1; // Return error code
    }

    printf("Changed directory to root.\n");

    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    if (!find_file_recursive(".", filename)) {
        printf("File not found.\n");
    }

    return 0;
}
