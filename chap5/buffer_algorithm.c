#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5

// 큐를 버퍼처럼 사용하기. 20% 비율로 난수 생성하여 큐에 집어넣고,
// 10% 비율로 큐에서 정수 꺼낸다. 생산자 속도가 소비자 속도보다 빠르니 큐가 포화 상태 될
// 가능성이 높음.

typedef int element;
typedef struct{
    int rear, front;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(const char *s){
    fprintf(stderr, "%s", s);
}

void init_queue(QueueType *p){
    p->rear = p->front = 0;
}

int is_empty(QueueType *p){
    return (p->rear == p->front);
}

int is_full(QueueType *p){
    return (((p->rear + 1) % MAX_QUEUE_SIZE) == p->front);
}

void print_queue(QueueType *p){
    printf("QUEUE(front=%d rear=%d) = ", p->front, p->rear);
    if(!is_empty(p)){
        int i = p->front;
        while(1){
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%d | ", p->data[i]);
            
            if(i == p->rear) break;
        }
    }
    printf("\n");
}

void enqueue(QueueType *p, element item){
    if(is_full(p)){
        error("큐 포화 상태\n");
        return;
    }
    else{
        p->rear = (p->rear + 1) % MAX_QUEUE_SIZE;
        // 0 1 2 3 4 0
        p->data[p->rear] = item;
    }
}

element dequeue(QueueType *p){
    if(is_empty(p)){
        error("큐 공백 상태\n");
    }
    
    else{
        p->front = (p->front + 1) % MAX_QUEUE_SIZE;
        return p->data[p->front];
    }
}


// 큐를 버퍼처럼 사용하기. 20% 비율로 난수 생성하여 큐에 집어넣고,
// 10% 비율로 큐에서 정수 꺼낸다. 생산자 속도가 소비자 속도보다 빠르니 큐가 포화 상태 될
// 가능성이 높음.

int main()
{
    QueueType p;
    init_queue(&p);
    srand(time(NULL));
    
    for(int i = 0; i < 100; i++){
        if(rand() % 5){
            enqueue(&p, rand() % 100);
        }
        
        print_queue(&p);
        
        if(rand() % 10){
            dequeue(&p);
        }
        
        print_queue(&p);
    }

    return 0;
}
