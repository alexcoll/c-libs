#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// It returns the next word from stdin.
// If there are no more more words it returns NULL.
extern char * nextword(FILE * fd);
extern int num_words(FILE * fd);
