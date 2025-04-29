#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType *p){
    p->front = p->rear = -1;
}

int is_empty(QueueType *p){
    return (p->rear == p->front);
}

int is_full(QueueType *p){
    return (p->rear == MAX_QUEUE_SIZE - 1);
}

void error(const char * text){
    fprintf(stderr, "%s", text);
}

void enqueue(QueueType *p, element item){
    if(is_full(p)){
        error("큐 포화 상태\n");
        return;
    }
    else p->data[++(p->rear)] = item;
}

element dequeue(QueueType *p){
    if(is_empty(p)){
        error("큐 공백 상태\n");
        exit(1);
    }
    else{
        element tmp;
        tmp = p->data[++(p->front)];
        return tmp;
    }
}

element peek(QueueType *p){
    if(is_full(p)){
        error("큐 포화 상태\n");
        exit(1);
    }
    else{
        element tmp;
        tmp = p->data[p->front];
        return tmp;
    }
}

void queue_print(QueueType *p){
    for(int i = 0; i < MAX_QUEUE_SIZE; i++){
        if(p->front >= i || i > p->rear){
            printf("   | ");
        }
        
        else{
            printf("%d | ", p->data[i]);
        }
    }
    printf("\n");
}

int main()
{
    int item = 0;
    QueueType q;
    init_queue(&q);
    
    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    
    return 0;
}
