#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;


void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}


int isEmpty(Queue *queue) {
    return queue->front == -1;
}


int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear + 1 == queue->front);
}


void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->rear == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX_SIZE - 1) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
}


int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == MAX_SIZE - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }
    return value;
}


int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", peek(&queue));

    return 0;
}
