#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define TRUE 1 
#define FALSE 0 

typedef struct{
    int n; // 간선의 수
    int adj_mat[MAX][MAX]; // 인접행렬
} GraphType;

int visited[MAX];

void init(GraphType *g){
    g->n = 0;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            g->adj_mat[i][j] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    if(g->n >= MAX){
        return;
    }
    
    g->n++;
}

void insert_edge(GraphType *g, int u, int v){
    if(u >= g->n || v >= g->n){
        return;
    }
    
    g->adj_mat[u][v] = 1;
    g->adj_mat[v][u] = 1;
}

void dfs_mat(GraphType *g, int v){
    if(v >= g->n) return;
    visited[v] = TRUE;
    
    for(int i = 0; i < g->n; i++){
        if(!visited[i] && g->adj_mat[v][i]){
            printf("(%d, %d), ", v, i);
            dfs_mat(g, i);
        }
    }
}

int main()
{
    GraphType *g;
    g = malloc(sizeof(GraphType));
    init(g);
    
    for(int i = 0; i < 4; i++){
        insert_vertex(g, i);
    }
    
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    
    printf("신장 트리 E(G)\n");
    dfs_mat(g, 0);
    free(g);
}
