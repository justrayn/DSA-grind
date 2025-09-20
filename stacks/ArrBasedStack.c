#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

typedef int Data;
typedef struct{
    Data Elem[MAX];
    int top;
}Stack;

void initStack(Stack *);
bool isEmpty(Stack);
bool isFull(Stack);
Data peek(Stack);
void push(Stack *, Data);
void pop(Stack *);
void visualize(Stack);
void removeNeg(Stack*, Stack*);
void sortStack(Stack *);


int main(){
    Stack s, r;
    initStack(&r);
    initStack(&s);
    push(&s, 6);
    push(&s, 4);
    push(&s, 9);
    push(&s, 5);
    visualize(s);
    sortStack(&s);
    visualize(s);



    return 0;
}

void initStack(Stack *s){
    s->top = -1;
}

bool isEmpty(Stack s){
    return s.top == -1;
}

bool isFull(Stack s){
    return s.top == MAX -1;
}

Data peek(Stack s){
    if(isEmpty(s)){
        return 0;
    }
    return s.Elem[s.top];
}

void push(Stack *s, Data elem){
    if(isFull(*s)){
        printf("Full!\n");
        return;
    }

    s->Elem[++s->top] = elem;
}

void pop(Stack *s){
    if(isEmpty(*s)){
        return;
    }
    s->top--;
}

void visualize(Stack s){
    for(int i = MAX -1; i >= 0; i--){
        if(i > s.top){
            printf("???\n");
        }

        if(i <= s.top){
            printf("%d\n",s.Elem[i]);
        }

        // if(i < s.top){
        //     printf("x\n");
        // }
    }
}

void removeNeg(Stack*s, Stack*r){
    Stack temp;
    initStack(&temp);

    while(!isEmpty(*s)){
        Data top = peek(*s);
        pop(s);
        if(top >= 0){
            push(&temp, top);
        } else {
            push(r, top);
        }
    }

     while(!isEmpty(temp)){
        Data top = peek(temp);
        pop(&temp);
        push(s, top);
     }
}


void sortStack(Stack *s){
    Stack temp;
    initStack(&temp);

    while(!isEmpty(*s)){
        Data curr = peek(*s);
        pop(s);
        while(!isEmpty(temp) && peek(temp) < curr){
            push(s, peek(temp));
            pop(&temp);
        }
        push(&temp, curr);
    }

    while(!isEmpty(temp)){
        push(s, peek(temp));
        pop(&temp);
    }
}
