#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024

char find_file_recursive(const char *dir_name, const char *file_name) {
    DIR *dir = opendir(dir_name);
    if (!dir) {
        return printf("File not found: \n");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH_LEN];
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            find_file_recursive(path, file_name);
        } else if (strcmp(entry->d_name, file_name) == 0) {
            return printf("File found: %s\n", path);
        }
    }

    closedir(dir);
}

int main() {
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    find_file_recursive(".", filename);

    return 0;
}
