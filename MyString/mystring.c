#include "mystring.h"

int mystrlen(char * s) {
	char * p = s;
    int i = 0;
    while (*p != '\0') {
        i++;
        p++;
    }
    return i;
}

char * mystrcpy(char * dest, char * src) {
    char * p = src;
    char * q = dest;
    while (*p != '\0') {
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';
    return dest;
}

char * mystrcat(char * dest, char * src) {
    char * p = dest;
    char * q = src;

    // Go to end of p
    while (*p != '\0') {
        p++;
    }

    // Copy the characters from q to p
    while (*q != '\0') {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return dest;

}

int mystrcmp(char * s1, char * s2) {
	int returnValue = 0;
    while (!(returnValue = *(char*) s1 - *(char*) s2) && *s2) {
        ++s1, ++s2;
    }
    if (returnValue < 0) {
        returnValue = -1;
    } else if (returnValue > 0) {
        returnValue = 1 ;
    }
    return returnValue;

}

char * mystrstr(char * hay, char * needle) {
	char * p = hay;
    while (*p) {
        char * pBegin = p;
        char * q = needle;
        while (*p && *q && *p == *q) {
            p++;
            q++;
        }
        if (! *q)
            return pBegin;
        p = pBegin + 1;
    }
    return NULL;
}

char * mystrdup(char * s) {
	char * d = (char *) malloc((mystrlen(s) / sizeof(char)) + sizeof(char));
    if (d == NULL) {
        return NULL;
    }
    mystrcpy(d, s);
    return d;
}

char * mymemcpy(char * dest, char * src, int n) {
	char * dest_temp = (char*) dest;
    char * src_temp = (char*) src;
    while (n--) {
        *dest_temp++ = *src_temp++;
    }
    return dest;
}

