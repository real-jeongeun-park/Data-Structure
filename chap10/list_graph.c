#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType{
    int n; // 노드의 개수
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

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
    if(v >= (g->n) || u >= (g->n)){
        fprintf(stderr, "그래프: 정점의 개수 초과");
    }
    
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType *g){
    GraphNode* p;
    
    for(int i = 0; i < g->n; i++){
        printf("정점 %d의 인접 리스트", i);
        for(p = g->adj_list[i]; p; p = p->link){
            printf(" -> %d", p->vertex);
        }
        printf("\n");
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
    
    print_adj_list(g);
    free(g);
    return 0;
}
