#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode* element;

typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

void init_queue(QueueType *p){
[O    p->front = p->rear = 0;
}

int is_empty(QueueType *p){
    return (p->rear == p->front);
}

int is_full(QueueType *p){
    return ((p->rear+1) % MAX_QUEUE_SIZE == p->front);
}

void enqueue(QueueType *q, element p){
    if(is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = p;
}

element dequeue(QueueType *q){
    if(is_empty(q)) exit(1);
    
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
    
}

void level_order(TreeNode *root){
    QueueType queue;
    init_queue(&queue);
    
    enqueue(&queue, root);
    
    while(!is_empty(&queue)){
        TreeNode* p = dequeue(&queue);
        printf("[%d]", p->data);
        
        if(p->left){
            enqueue(&queue, p->left);
        }
        
        if(p->right){
            enqueue(&queue, p->right);
        }
    }
    
}

//      15
//   4      20
// 1      16  25
// 레벨 순회 프로그램. 큐 사용

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {16, NULL, NULL};
TreeNode n3 = {25, NULL, NULL};
TreeNode n4 = {4, &n1, NULL};
TreeNode n5 = {20, &n2, &n3};
TreeNode n6 = {15, &n4, &n5};
TreeNode *root = &n6;

int main()
{
    printf("레벨 순회=");
    level_order(root);
    printf("\n");
    return 0;
}
