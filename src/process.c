#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/os.h"
#include "../include/constants.h"

#define MAX_PATH_LEN 256

void concatPath(char* buffer, const char* base, const char* leaf) {
    snprintf(buffer, MAX_PATH_LEN, "%s/%s", base, leaf);
}

int createDirectories(const char* base) {
    if (strcmp(base, ".") == 0) {
        int res_a = createDirectory(SRC_DIR);
        int res_b = createDirectory(INCLUDE_DIR);
        // cleverly, returning success or fail
        // by checking if both return values are
        // equal to each other. With a caveat of
        // comparing b to 0, implying that a
        // must also be 0 (success), to return a final
        // success value
        return res_a == res_b && res_b == 1;
    } else {
        // creates the folder in which the project will live in
        createDirectory(base);
    }

    char srcDirBuf[MAX_PATH_LEN];
    concatPath(srcDirBuf, base, SRC_DIR);
    int res_a = createDirectory(srcDirBuf);
    printf("%s\n", srcDirBuf);

    char includeDirBuf[MAX_PATH_LEN];
    concatPath(includeDirBuf, base, INCLUDE_DIR);
    int res_b = createDirectory(includeDirBuf);
    printf("%s\n", includeDirBuf);

    char testsDirBuf[MAX_PATH_LEN];
    concatPath(testsDirBuf, base, TESTS_DIR);
    int res_c = createDirectory(testsDirBuf);
    printf("%s\n", testsDirBuf);

    int are_equal = (res_a == res_b) && (res_b == res_c);
    int are_success = res_b == 1;

    return are_equal && are_success;
}

int createFiles(const char* base) {
    char main_C_LocBuf[MAX_PATH_LEN];
    concatPath(main_C_LocBuf, base, MAIN_C_LOC);
    int res_a = writeFile(main_C_LocBuf, MAIN_C_CONTENT);
    printf("%s\n", main_C_LocBuf);

    char buildPyLocBuf[MAX_PATH_LEN]; 
    concatPath(buildPyLocBuf, base, BUILD_PY_LOC);
    int res_b = writeFile(buildPyLocBuf, BUILD_PY_CONTENT);
    printf("%s\n", buildPyLocBuf);

    char gitignoreLocBuf[MAX_PATH_LEN];
    concatPath(gitignoreLocBuf, base, GITIGNORE_LOC);
    int res_c = writeFile(gitignoreLocBuf, GITIGNORE_CONTENT);
    printf("%s\n", gitignoreLocBuf);

    int a = res_a == res_b && res_b == 0;
    int b = res_b == res_c && res_b == 0;

    return a == b && b == 1;
}


// Given a working directory (wd), changes
// directory into it and initializes a git
// repository
int createLocalRepo(const char* wd) {
    if (system(NULL) == 0) {
        // means that there is no
        // command processor
        return 0;
    }

    if (chdir(wd) != 0) {
        // not a successful change of
        // working directories
        return 0;
    }

    int status_code = system("git init -q");

    if (status_code != 0) {
        printf("Could not initialize git repo. Please make sure you got git installed");
    } else {
        char gitLocBuf[MAX_PATH_LEN];
        concatPath(gitLocBuf, wd, ".git");
        printf("%s\n", gitLocBuf);
    }

    return status_code == 0;
}
