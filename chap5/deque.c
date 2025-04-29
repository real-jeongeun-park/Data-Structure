#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct{
    int rear, front;
    element data[MAX_DEQUE_SIZE];
} DequeType;

void init_deque(DequeType *p){
    p->rear = p->front = 0;
}

void error(const char *s){
    fprintf(stderr, "%s", s);
    exit(1);
}

int is_full(DequeType *p){
    return (((p->rear + 1) % MAX_DEQUE_SIZE) == p->front);
}

int is_empty(DequeType *p){
    return (p->rear == p->front);
}

void print_deque(DequeType *p){
    printf("DEQUE(front=%d rear=%d) = ", p->front, p->rear);
    if(!is_empty(p)){
        int i = p->front;
        while(1){
            i = (i + 1) % MAX_DEQUE_SIZE;
            printf("%d | ", p->data[i]);
            if(i == p->rear) break;
        }
    }
    printf("\n");
}

// queue의 enqueue
void add_rear(DequeType *p, element item){
    if(is_full(p)){
        error("덱 포화 상태\n");
    }
    
    else{
        p->rear = (p->rear + 1) % MAX_DEQUE_SIZE;
        p->data[p->rear] = item;
    }
}

// queue의 dequeue, stack의 pop
element delete_front(DequeType *p){
    if(is_empty(p)){
        error("덱 공백 상태\n");
    }
    
    else{
        element tmp;
        p->front = (p->front + 1) % MAX_DEQUE_SIZE;
        tmp = p->data[p->front];
        return tmp;
    }
}

// queue의 peek
element get_front(DequeType *p){
    if(is_empty(p)){
        error("덱 공백 상태\n");
    }
    
    else{
        element tmp;
        tmp = p->data[((p->front) + 1) % MAX_DEQUE_SIZE];
        return tmp;
    }
}

// stack의 push
void add_front(DequeType *p, element item){
    if(is_full(p)){
        error("덱 포화 상태\n");
    }
    
    else{
        p->data[p->front] = item;
        p->front = ((p->front - 1) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    }
}

// 새로운 연산
element delete_rear(DequeType *p){
    if(is_empty(p)){
        error("덱 공백 상태\n");
    }
    
    else{
        element tmp;
        tmp = p->data[p->rear];
        p->rear = ((p->rear - 1) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
        return tmp;
    }
}

// 새로운 연산
element get_rear(DequeType *p){
    if(is_empty(p)){
        error("덱 공백 상태\n");
    }
    
    else{
        element tmp;
        tmp = p->data[p->rear];
        return tmp;
    }
}


int main(void){
    DequeType d;
    init_deque(&d);
    
    for(int i = 0; i < 3; i++){
        add_front(&d, i);
        print_deque(&d);
    }
    
    for(int i = 0; i < 3; i++){
        delete_rear(&d);
        print_deque(&d);
    }
    
    return 0;
}
