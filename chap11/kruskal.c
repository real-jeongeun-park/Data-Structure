#include <stdlib.h>
#include <stdio.h>
#define MAX 50
#define INF 100000
typedef struct{
    int start, end, weight;
} Edge;

typedef struct{
    int n; // 간선 수
    int nvertex; // 정점 수
    Edge edges[MAX * 2]; // 간선 정보
} GraphType;

int parent[MAX];

void graph_init(GraphType *g){
    g->n = g->nvertex = 0;
    for(int i = 0; i < MAX * 2; i++){
        g->edges[i].start = g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType *g, int u, int v, int w){
    g->edges[g->n].start = u;
    g->edges[g->n].end = v;
    g->edges[g->n].weight = w;
    
    g->n++;
}

void set_init(int n){
    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }
}

int set_find(int u){
    // 루트 노드의 인덱스 반환
    if(parent[u] == -1) return u;
    while(parent[u] != -1) u = parent[u];
    return u;
}

void set_union(int u, int v){
    parent[u] = v;
}

int compare(const void* a, const void* b){
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    return(x->weight - y->weight);
}

void kruskal(GraphType *g){
    int uset, vset, selected = 0;
    int i = 0;
    Edge e;
    
    set_init(g->nvertex);
    qsort(g->edges, g->n, sizeof(Edge), compare);
    
    while(selected < (g->nvertex-1)){
        // 간선 6개만 선택
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        
        if(uset != vset){
            // 서로 다른 집합이면
            printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
            selected++;
            set_union(uset, vset);
        }
        
        i++;
    }a
}

int main(void){
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    
    g->nvertex = 7;
    
    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
[O    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);
    
    printf("크루스칼 최소 신장 트리 알고리즘\n");
    kruskal(g);
    free(g);
    
    return 0;
}
