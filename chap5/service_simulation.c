#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 60

typedef struct{
    int id;
    int arrival_time;
    int service_time; // 용무 시간
} element;

typedef struct{
    int rear, front;
    element data[MAX_QUEUE_SIZE];
} QueueType;
[O
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
    }
    
    else{
        p->front = (p->front + 1) % MAX_QUEUE_SIZE;
        return p->data[p->front];
    }
}

int main()
{
    int minutes = 60;
    int total_wait = 0;
    int total_customer = 0;
    int service_time = 0;
    int service_customer;
    
    QueueType q;
    init_queue(&q);
    
    srand(time(NULL));
    
    for(int clock_ = 0; clock_ < minutes; clock_++){
        printf("현재시각 = %d분\n", clock_);
        
        if((rand() % 10) < 3){
            // 30퍼센트의 확률로 고객 들어옴 
            element new;
            new.id = total_customer++;
            new.arrival_time = clock_;
            new.service_time = (rand() % 3 + 1);
            enqueue(&q, new);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", new.id, clock_, new.service_time);
        }
        
        if(service_time > 0){
            // 고객이 용무 보는 중
            printf("고객 %d 업무 처리 중입니다.\n", service_customer);
            service_time--;
        }
        
        else if(!(is_empty(&q))){
            // 고객 용무 아무도 안 보는 중
            element customer_now = dequeue(&q);
            service_time = customer_now.service_time;
            service_customer = customer_now.id;
            printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
                service_customer, clock_, (clock_ - customer_now.arrival_time));
                
            total_wait += (clock_ - customer_now.arrival_time);
        }
    }
    
    printf("전체 대기 시간 = %d분\n", total_wait);
    return 0;
}

