// 똑같이 깊이 우선 탐색으로 정점 0 -> 정점 1 -> 정점 2 -> 정점 3 -> 결과 내야 함.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 50
#define TRUE 1
#define FALSE 0

typedef struct StackNode{
    int stack[MAX_STACK_SIZE];
    int top;
} StackNode;

int visited[MAX_VERTICES];

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType{
    int n; // 노드의 개수
    GraphNode *adj_list[MAX_VERTICES]; // 각 연결 리스트의 헤드
} GraphType;

void init_stack(StackNode *p){
    p->top = -1;
}

int is_empty(StackNode *p){
    return (p->top == -1);
}

void push(StackNode *p, int item){
    if(p->top == (MAX_STACK_SIZE - 1)) return;
    p->stack[++(p->top)] = item;
}

int pop(StackNode *p){
    if(p->top == -1) exit(1);
    return p->stack[(p->top)--];
}

void init(GraphType* g){
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        g->adj_list[i] = NULL;
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
    // INSERT_FIRST
    if(v >= (g->n) || u >= (g->n)){
        fprintf(stderr, "그래프: 정점의 개수 초과");
    }
    
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void dfs_iter(GraphType *g, int v){
    int w;
    StackNode s1;
    init_stack(&s1);
    push(&s1, v);
    visited[v] = TRUE;
    
    while(!is_empty(&s1)){
        w = pop(&s1);
        printf("정점 %d -> ", w);
        
        for(GraphNode *p = g->adj_list[w]; p; p=p->link){
            if(!visited[p->vertex]){
                visited[p->vertex] = TRUE;
                push(&s1, p->vertex);
            }
        }
    }
}

int main()
{
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    
    for(int i = 0; i < 4; i++){
        insert_vertex(g, i);
    }
    
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    
    printf("깊이 우선 탐색\n");
    dfs_iter(g, 0);
    printf("\n");
    
    free(g);
    return 0;
}
