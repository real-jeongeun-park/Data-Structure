#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct QueueNode{
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *rear;
    QueueNode *front;
} LinkedQueueType;

void init(LinkedQueueType *p){
    p->rear = p->front = NULL;
}

int is_empty(LinkedQueueType *p){
    if(p->front == NULL && p->rear == NULL) return 1;
    else return 0;
}

void enqueue(LinkedQueueType *p, element item){
    QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
    if(!tmp) return;
    tmp->data = item;
    tmp->link = NULL;
    
    if(is_empty(p)){
        p->rear = p->front = tmp;
    }
    else{
        p->rear->link = tmp;
        p->rear = tmp;
    }
}

element dequeue(LinkedQueueType *p){
    if(is_empty(p)){
        printf("오류\n");
        exit(1);
    }
    
    QueueNode *target = p->front;
    element data = target->data;
    p->front = target->link;
    
    if(p->front == NULL){
        p->rear = NULL; // 둘다 NULL 처리 필요
    }
    
    free(target);
    return data;
}

void print_queue(LinkedQueueType *queue){
    QueueNode* p = queue->front;
    for(; p; p = p->link){
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main()
{
    LinkedQueueType queue;
    init(&queue);
    
    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    return 0;
}
