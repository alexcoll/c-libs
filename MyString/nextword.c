#include "nextword.h"

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

// It returns the next word from fd.
// If there are no more more words it returns NULL.
char * nextword(FILE * fd) {
  	int c;
    if (!feof(fd)) {
        memset(word, 0, sizeof(word));
        wordLength = 0;
        while (1) {
            c = (char) fgetc(fd);
            if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
                if (wordLength > 0) {
                    return word;
                } else {
                    continue;
                }
            } else if (c >= 33) {
                word[wordLength] = c;
                wordLength++;
            } else if (feof(fd)) {
                if (wordLength > 0) {
                    return word;
                } else {
                    return NULL;
                }
            }
        }
    }
	return NULL;
}

int num_words(FILE * fd) {
    char * w;
    int wordCount = 0;
    while ( (w = nextword(fd)) != NULL) {
        wordCount++;
    }
    free(w);
    return wordCount;
}

