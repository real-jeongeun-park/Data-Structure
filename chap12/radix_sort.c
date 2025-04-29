#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100
#define MAX_SIZE 10
#define DIGITS 2
#define BUCKETS 10

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int rear;
    int front;
} QueueType;

void queue_init(QueueType *q){
    q->rear = q->front = 0;
}

int is_full(QueueType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)) exit(1);
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void radix_sort(int list[], int n){
    int radix_num;
    int expon = 1;
    
    QueueType queue[BUCKETS];
    for(int i = 0; i < BUCKETS; i++){
        queue_init(&queue[i]);
    }
    
    for(int i = 0; i < DIGITS; i++){
        int index = 0;
        // 자리수만큼 반복
        for(int j = 0; j < n; j++){
            radix_num = (list[j] / expon % 10);
            enqueue(&queue[radix_num], list[j]);
        }
        
        for(int j = 0; j < BUCKETS; j++){
            while(!is_empty(&queue[j])){
                list[index++] = dequeue(&queue[j]);
            }
        }
        expon *= 10;
    }
}

int list[MAX_SIZE];

[Oint main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    } 
    
    radix_sort(list, MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
