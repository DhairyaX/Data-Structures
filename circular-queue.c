#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;


void initialize(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}


int isEmpty(CircularQueue *queue) {
    return queue->size == 0;
}


int isFull(CircularQueue *queue) {
    return queue->size == MAX_SIZE;
}



void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    queue->size++;
}


int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return value;
}


int peek(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);
    enqueue(&queue, 70);

    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", peek(&queue));

    return 0;
}
