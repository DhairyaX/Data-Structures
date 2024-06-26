#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *stack) {
    stack->top = -1;
}


int isEmpty(Stack *stack) {
    return stack->top == -1;
}


int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}


int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    
    return 0;
}
