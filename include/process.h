#pragma once

char* concatPath(char* buffer, const char* base, const char* leaf);

int createDirectories(const char* base);

int createFiles(const char* base);

int createLocalRepo(const char* wd);
