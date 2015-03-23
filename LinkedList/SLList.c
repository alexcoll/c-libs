#include "SLList.h"


//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
    list->head = NULL;
}


//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
    ListNode * e;

    if (list->head == NULL) {
        printf("{EMPTY}\n");
        return;
    }

    printf("{");

    e = list->head;
    while (e != NULL) {
        if (e->value.i != 0) {
            printf("%d", e->value.i);
        } else if (e->value.f != 0) {
            printf("%f", e->value.f);
        } else if (e->value.s != NULL) {
            printf("%s", e->value.s);
        }
        e = e->next;
        if (e!=NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}


//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, Value value) {
    // Create new node
    ListNode * n = (ListNode *) malloc(sizeof(ListNode));
    n->value = value;

    // Add at the beginning of the list
    n->next = list->head;
    list->head = n;
}


//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, Value value) {
    ListNode * e;

    if (list->head == NULL) {
        // list is empty
        return 0;
    }

    e = list->head;
    while (e != NULL) {
        if ((value.i != 0) && (e->value.i == value.i)) {
            return 1;
        } else if ((value.f != 0) && (e->value.f == value.f)) {
            return 1;
        } else if ((value.s != NULL) && (strcmp(e->value.s, value.s) > 0)) {
            return 1;
        }
        e = e->next;
    }
    return 0;
}


//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, Value value) {
    ListNode * e;
    ListNode * previous;

    if (list->head == NULL) {
        return 0;
    }

    e = list->head;
    previous = list->head;
    // Check first value
    if ((value.i != 0) && (e->value.i == value.i)) {
        list->head = e->next;
        return 1;
    } else if ((value.f != 0) && (e->value.f == value.f)) {
        list->head = e->next;
        return 1;
    } else if ((value.s != NULL) && (strcmp(e->value.s, value.s) > 0)) {
        list->head = e->next;
        return 1;
    }

    // Check all other values
    while (e->next != NULL) {
        e = e->next;
        if ((value.i != 0) && (e->value.i == value.i)) {
            previous->next = e->next;
            return 1;
        } else if ((value.f != 0) && (e->value.f == value.f)) {
            previous->next = e->next;
            return 1;
        } else if ((value.s != NULL) && (strcmp(e->value.s, value.s) > 0)) {
            previous->next = e->next;
            return 1;
        }
        previous = e;
    }
    return 0;
}


//
// It stores in *value the value that correspond to the ith
// entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, Value *value) {
    ListNode * e;

    if (list->head == NULL) {
        return 0;
    }

    int n = 0;
    e = list->head;
    while (e != NULL) {

        if (n == ith) {
            *value = e->value;
            return 1;
        }
        e = e->next;
        n++;
    }
    return 0;
}


//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
    ListNode * e;

    if (list->head == NULL) {
        return 0;
    }

    int n = 0;
    e = list->head;
    while (e != NULL) {
        if (n == ith) {
            return llist_remove(list, e->value);
        }
        e = e->next;
        n++;
    }
    return 0;
}


//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
    ListNode * e;

    if (list->head == NULL) {
        return 0;
    }

    int n = 0;
    e = list->head;
    while (e != NULL) {
        e = e->next;
        n++;
    }
    return n;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
    // FIXME
    ListNode * e = list->head;
    FILE * fp;
    fp = fopen(file_name, "w+");
    if (fp == NULL) {
        return 0;
    }

    while (e != NULL) {
        if (e->value.i != 0) {
            fprintf(fp, "%d\n", e->value.i);
        } else if (e->value.f != 0) {
            fprintf(fp, "%f\n", e->value.f);
        } else if (e->value.s != NULL) {
            fprintf(fp, "%s\n", e->value.s);
        }
        e = e->next;
    }
    fclose(fp);
    return 0;
}


//
// It reads the list from the file_name indicated. If the list
// already has entries, it will clear the entries.
//
/*int llist_read(LinkedList * list, char * file_name) {
    // FIXME
    FILE * fp = fopen(file_name, "r");
    if (fp == NULL) {
        return 0;
    }
    llist_clear(list);
    char * buffer = (char*) malloc(8 * sizeof(char));
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        llist_add(list, atoi(buffer));
    }
    fclose(fp);
    return 1;
}*/


//
// It sorts the list. The parameter ascending determines if
// the order is ascending (1) or descending(0).
//
/*void llist_sort(LinkedList * list, int ascending) {
    // FIXME
    ListNode * e;
    int done = 0;
    if (list->head == NULL) {
        return;
    }

    while (!done) {
        done = 1;
        e = list->head;
        while (e->next != NULL) {
            if (ascending == 1) {
                if (e->value > e->next->value) {
                    done = 0;
                    int temp = e->value;
                    e->value = e->next->value;
                    e->next->value = temp;
                }
            } else {
                if (e->value < e->next->value) {
                    done = 0;
                    int temp = e->value;
                    e->value = e->next->value;
                    e->next->value = temp;
                }
            }
            e = e->next;
        }
    }
}*/


//
// It removes the first entry in the list and puts value in
// *value. It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, Value *value) {
    if (list->head == NULL) {
        return 0;
    }

    ListNode * e;
    e = list->head;
    *value = e->value;
    list->head = e->next;
    e = NULL;
    return 1;
}


//
// It removes the last entry in the list and puts value in
// *value. It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, Value *value) {
    ListNode * e;

    if (list->head == NULL) {
        return 0;
    }

    e = list->head;
    while (1) {
        if (e->next == NULL) {
            break;
        }
        e = e->next;
    }
    *value = e->value;
    free(e);
    e = NULL;
    return 1;
}


//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, Value value) {
    ListNode * n = (ListNode *) malloc(sizeof(ListNode));
    n->value = value;
    n->next = list->head;
    list->head = n;
}


//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is
// added at the end of the list.
//
void llist_insert_last(LinkedList * list, Value value) {
    ListNode * e;

    if (list->head == NULL) {
        llist_add(list, value);
        return;
    }

    e = list->head;
    while (1) {
        if (e->next == NULL) {
            ListNode * new = (ListNode *) malloc(sizeof(ListNode));
            e->next = new;
            new->value = value;
            new->next = NULL;
            break;
        } else {
            e = e->next;
        }
    }

    return;
}


//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list) {
    ListNode * e;

    if (list->head == NULL) {
        return;
    }
}
