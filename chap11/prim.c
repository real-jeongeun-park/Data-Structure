#include <stdlib.h>
#include <stdio.h>
#define MAX 50
#define INF 100000
#define TRUE 1 
#define FALSE 0
typedef struct{
    int n; // vertex 개수
    int weight[MAX][MAX]; // 가중치 인접 행렬
} GraphType;

int selected[MAX]; // vertex 선택 여부
int distance[MAX]; // 신장 트리로부터 인접한 정점까지의 최단 거리

int find_min_vertex(GraphType* g, int v){
    int min = INF;
    int minpos = -1;
    
    for(int i = 0; i < g->n; i++){
        // vertex의 개수만큼 돌림
        if(!selected[i] && distance[i] < min){
            min = distance[i];
            minpos = i;
        }
    }
    
    return minpos;
}

void prim(GraphType *g, int start){
    int u;
    selected[start] = TRUE;
    printf("정점 %d 선택\n", start);
    
    for(int i = 0; i < g->n; i++){
        distance[i] = g->weight[start][i];
    }
    
    for(int i = 0; i < (g->n-1); i++){
        // 모든 정점 포함. 7번 돌림
        u = find_min_vertex(g, start);
        selected[u] = TRUE;
        if(distance[u] == INF) return;
        printf("정점 %d 선택\n", u);
        
        for(int j = 0; j < g->n; j++){
            if(!selected[j] && (distance[j] > g->weight[u][j])){
                distance[j] = g->weight[u][j];
            }
        }
    }
}

int main(void){
    GraphType g = {7,
        {{0, 29, INF, INF, INF, 10, INF},
        {29, 0, 16, INF, INF, INF, 15},
        {INF, 16, 0, 12, INF, INF, INF},
        {INF, INF, 12, 0, 22, INF, 18},
        {INF, INF, INF, 22, 0, 27, 25},
        {10, INF, INF, INF, 27, 0, INF},
        {INF, 15, INF, 18, 25, INF, 0}}
    };
    // 가중치 인접 행렬
    
    printf("프림 최소 비용 신장 트리\n");
    prim(&g, 0);
    
    return 0;
}
