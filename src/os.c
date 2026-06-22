#include <io.h>
#include <stdio.h>
#include <direct.h>
#include "../include/os.h"

int writeFile(const char* filename, const char* text) {
     FILE *fp;

    // Open the file in write mode ("w")
    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Failed to open file");
        return 0;
    }
    // Write a string to the file
    fprintf(fp, "%s", text);

    // Close the file
    fclose(fp);

    return 1;
}

int createDirectory(const char* dirname) {
    // if directory exists, return early
    if (_access(dirname, 0) == 0) {
        return 1;
    }

    // otherwise, attempting to make a directory
    if (_mkdir(dirname) != 0) {
        perror("_mkdir failed");
        return 0;
    }

    return 1;
}
