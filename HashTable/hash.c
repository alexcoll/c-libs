#include "hash.h"

typedef union key {
    int i;
    double f;
    char s[STR_LENGTH];
} Key;

int hash (Key key, int n) {
    if (key.i != 0) {
        // Key is integePr
        return key.i % n;
    } else if (key.f != 0) {
        // Key is a double
        return n;
    } else if (key.s != NULL) {
        // Key is a string
        char * p = key.s;
        int sum = 0;
        int pos = 1;
        while (*p) {
            sum += *p * pos;
            pos++;
            p++;
        }
        return sum % n;
    }
    return 0;
}

int main () {
    return 0;
}
