#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct GraphType{
    int n; // 노드의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

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

void dfs_mat(GraphType *g, int v){
    // 시작 정점 v
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    // 항상 visited TRUE 되면 정점 방문 했다고 print 해줘야 함.
    
    for(int i = 0; i < g->n; i++){
        if(g->adj_mat[v][i] && !visited[i]){
            dfs_mat(g, i);
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
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    
    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);
}
