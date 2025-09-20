#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) ;
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, int value) ;
int dequeue(Queue *q);
int main(){




    return 0;
}

void init(Queue *q) {
    q->front = 1;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue *q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue *q, int value) {
    if(isFull(q)) {
        printf("Full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Empty!\n");
        return -1;
    }
    int val = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return val;
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

   for (int i = q->front; ; i = (i + 1) % MAX) {
    printf("%d ", q->items[i]);
    if (i == q->rear) break;
    }
}

