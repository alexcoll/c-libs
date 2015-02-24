#include "countlines.h"

int count_lines(char * fileName) {

    FILE * fd = fopen(fileName, "r");
    if (fd == NULL) {
        return -1;
    }

    int lines = 0;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fd)) != -1) {
        lines++;
    }

    fclose(fd);
    if (line) {
        free(line);
    }

    return lines;
}
