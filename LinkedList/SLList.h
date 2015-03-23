#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LENGTH 64

union Value {
    int i;
    float f;
    char s[STR_LENGTH];
};

typedef union Value Value;

struct ListNode {
    Value value;
    struct ListNode * next;
};

typedef struct ListNode ListNode;

struct LinkedList {
    ListNode * head;
};

typedef struct LinkedList LinkedList;

extern void llist_init(LinkedList * list);
extern void llist_print(LinkedList * list);
extern void llist_add(LinkedList * list, Value value);
extern int llist_exists(LinkedList * list, Value value);
extern int llist_remove(LinkedList * list, Value value);
extern int llist_get_ith(LinkedList * list, int ith, Value *value);
extern int llist_remove_ith(LinkedList * list, int ith);
extern int llist_number_elements(LinkedList * list);
extern int llist_save(LinkedList * list, char * file_name);
extern int llist_read(LinkedList * list, char * file_name);
extern void llist_sort(LinkedList * list, int ascending);
extern void llist_clear(LinkedList * list);
extern int llist_remove_first(LinkedList * list, Value *value);
extern int llist_remove_last(LinkedList * list, Value *value);
extern void llist_insert_first(LinkedList * list, Value value);
extern void llist_insert_last(LinkedList * list, Value value);
