#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

typedef int element;
typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void q_init(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)) exit(1);
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}


void init(GraphType* g){
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        for(int j = 0; j < MAX_VERTICES; j++){
            g->adj_mat[i][j] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v){
    if((g->n) == MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    
    (g->n)++;
}

void insert_edge(GraphType* g, int u, int v){
    if(v >= (g->n) || u >= (g->n)){
        fprintf(stderr, "그래프: 정점의 개수 초과");
    }

    g->adj_mat[u][v] = 1;
    g->adj_mat[v][u] = 1;
}

void print_adj_mat(GraphType *g){
    for(int i = 0; i < g->n; i ++){
        for(int j = 0; j < g->n; j++){
            printf("%d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void bfs_mat(GraphType *g, int v){
    int w;
    QueueType *q = (QueueType*)malloc(sizeof(QueueType));
    q_init(q);
    
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(q, v);
    
    while(!is_empty(q)){
        w = dequeue(q);
        
        for(int i = 0; i < g->n; i++){
            if(!visited[i] && g->adj_mat[w][i]){
                visited[i] = TRUE;
                printf("%d 방문 -> ", i);
                enqueue(q, i);
                // enqueue 하기 전에 반드시 방문 처리
            }
        }
    
    }
}

int main()
{
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    
    for(int i = 0; i < 6; i++){
        insert_vertex(g, i);
    }
    
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);
    
    printf("너비 우선 탐색\n");
    bfs_mat(g, 0);
    printf("\n");
    
    free(g);
    return 0;
    
    free(g);
}
