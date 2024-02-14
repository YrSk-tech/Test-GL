#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "findfilepath.h"

#define MAX_PATH_LEN 1024
char find_file_recursive(const char *dir_name, const char *file_name) {
    DIR *dir = opendir(dir_name);
    if (!dir) {
        return 0; // Directory not found
    }

    struct dirent *entry;
    char found = 0; // Flag to indicate whether the file is found
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
            found |= find_file_recursive(path, file_name); // Update found flag recursively
        } else if (strcmp(entry->d_name, file_name) == 0) {
            printf("File found: %s\n", path);
            found = 1; // Set flag if the file is found in the current directory
        }
    }

    closedir(dir);
    return found; // Return flag indicating whether the file is found
}
