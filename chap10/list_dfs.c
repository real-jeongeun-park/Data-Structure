#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];
typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
    GraphNode* adj_list[MAX_VERTICES];
    int n; // 노드 개수
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


void init(GraphType *g){
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType *g, int v){
    if(g->n == MAX_VERTICES) return;
    g->n++;
}

void insert_edge(GraphType* g, int u, int v){
    if(v >= (g->n) || u >= (g->n)){
        fprintf(stderr, "그래프: 정점의 개수 초과");
    }
    
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = NULL;
    
    if(!(g->adj_list[u])){
        g->adj_list[u] = node;
    }
    else{
        GraphNode *p = g->adj_list[u];
        for(; p->link; p = p->link){}
        p->link = node;
    }
}
void bfs_list(GraphType *g, int v){
    int w;
    QueueType *q = (QueueType*)malloc(sizeof(QueueType));
    q_init(q);
    
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(q, v);
    
    while(!is_empty(q)){
        w = dequeue(q);
            for(GraphNode* p = g->adj_list[w]; p; p = p->link){
                if(!visited[p->vertex]){
                    visited[p->vertex] = TRUE;
                    printf("%d 방문 -> ", p->vertex);
                    enqueue(q, p->vertex);
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
    insert_edge(g, 2, 0);
    insert_edge(g, 2, 1);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 0);
    insert_edge(g, 4, 5);
    insert_edge(g, 5, 4);
    insert_edge(g, 1, 5);
    insert_edge(g, 5, 1);
    
    printf("너비 우선 탐색\n");
    bfs_list(g, 0);
    printf("\n");
    
    free(g);
    return 0;
}
