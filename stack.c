#include "stack.h"

int top = 0;
double stack[MAXSTACK];

void stack_clear() {
    top = 0;
}

double stack_pop() {
    top--;
    return stack[top];
}

void stack_push(double val) {
    stack[top++] = val;
}

void stack_print() {
    printf("Stack:\n");
    if (stack_is_empty()) {
        printf("Stack is empty");
    } else {
        for (int i = 0; i < stack_top(); i++) {
            printf("%d: %6f\n", i, stack[i]);
        }
    }
}

int stack_top() {
    return top;
}

int stack_max() {
    return MAXSTACK;
}

int stack_is_empty() {
    return top == 0;
}


