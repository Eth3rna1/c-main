/*
* A pipeline to make initialization of projects automated.
*
*
* Pipeline
* --------
*   * /src
*   * /include
*   * /tests directory
*   * src/main.c file with a hello world program
*   * build.py file
*   * .gitignore
*/
#include <stdio.h>
#include "../include/process.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide a project name\n");
        return 1;
    }
    char* PROJECT_NAME = argv[1];
    printf("%s\n", PROJECT_NAME);
    int _ = createDirectories(PROJECT_NAME);
    _ = createFiles(PROJECT_NAME);
    return 0;
}

/*int main() {*/
/*    char path[256];*/
/*    char* base = ".";*/
/*    char* leaf = "direc";*/
/*    concatPath(path, base, leaf);*/
/*    concatPath(path, path, "text.h");*/
/*    printf("Result: %s\n", path);*/
/*    return 0;*/
/*}*/
