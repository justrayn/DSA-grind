#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int items[5];
    int front;
    int rear;
} Queue;

void initQ(Queue *);
bool isEmpty(Queue);
bool isFull(Queue);
void enqueue(Queue*, int);
void dequeue(Queue*);
void display(Queue);


int main(){
    Queue q;
    initQ(&q);
    enqueue(&q, 10);
    enqueue(&q, 1);
    enqueue(&q, 12);
    enqueue(&q, 3);
    enqueue(&q, 29);
    dequeue(&q);
    display(q);




    return 0;
}

void initQ(Queue *q){
    q->front = 0;
    q->rear = -1;
}
bool isEmpty(Queue q){
    return q.front > q.rear;
}
bool isFull(Queue q){
    return q.rear == MAX -1;
}
void enqueue(Queue* q, int val){
    if(isFull(*q)){
        printf("\nfull!\n");
        return;
    }
    q->items[++q->rear] = val;
}
void dequeue(Queue*q){
    if(isEmpty(*q)){
        printf("\nnothing to dequeue!\n");
        return;
    }
    q->front++;
}
void display(Queue q){
    printf("front->[");
    for(int i = q.front; i <= q.rear ;i++ ){
        printf(" %d ", q.items[i]);
    }
    printf("]-> rear");
}
