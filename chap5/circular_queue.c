#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

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
        exit(1);
    }
    
    else{
        p->front = (p->front + 1) % MAX_QUEUE_SIZE;
        return p->data[p->front];
    }
}

int main()
{
    QueueType q;
    element n;
    init_queue(&q);
    
    printf("--데이터 추가 단계--\n");
    while(!is_full(&q)){
        printf("정수를 입력하십시오: ");
        scanf("%d", &n);
        enqueue(&q, n);
        print_queue(&q);
    }
    printf("큐는 포화 상태입니다.\n");
    
    printf("--데이터 삭제 단계--\n");
    while(!is_empty(&q)){
        n = dequeue(&q);
        printf("꺼내진 정수 %d \n", n);
        print_queue(&q);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}
