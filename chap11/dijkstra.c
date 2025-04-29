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

int found[MAX]; // start 정점으로부터 인덱스 정점으로까지의 최단 거리 찾았는지 여부
int distance[MAX]; // start 정점으로부터 인덱스 정점으로까지의 최단 거리

void print_status(GraphType *g, int step){
    printf("STEP %d)\n", step);
    
    printf("distance: ");
    for(int i = 0; i < g->n; i++){
        if(distance[i] == INF) printf("* ");
        else printf("%d ", distance[i]);
    }
    printf("\n");
    
    printf("found: ");
    for(int i = 0; i < g->n; i++){
        printf("%d ", found[i]);
    }
    printf("\n\n");
}

int choose(int n){
    int min = INF;
    int minpos = -1;
    
    for(int i = 0; i < n; i++){
        // vertex 개수만큼 돌림
        if(!found[i] && (min > distance[i])){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortest_path(GraphType *g, int start){
    int u;
    int i = 1;
    
    for(int i = 0; i < g->n; i++){
        distance[i] = g->weight[start][i];
        found[start] = FALSE;
        // 초기화
    }
    found[start] = TRUE;
    distance[start] = 0;

    for(int j = 0; j < (g->n); j++){
        // vertex 개수만큼 반복. start 정점에서 각 정점까지의 최단 경로 찾는 것이니 당연.
        print_status(g, i++);
        u = choose(g->n);
        found[u] = TRUE;
        
        for(int k = 0; k < (g->n); k++){
            if(!found[k] && (distance[k] > distance[u] + g->weight[u][k])){
                distance[k] = distance[u] + g->weight[u][k];
            }
        }
    }
}

int main(void){
    GraphType g = {7,
        {{0, 7, INF, INF, 3, 10, INF},
        {7, 0, 4, 10, 2, 6, INF},
        {INF, 4, 0, 2, INF, INF, INF},
        {INF, 10, 2, 0, 11, 9, 4},
        {3, 2, INF, 11, 0, INF, 5},
        {10, 6, INF, 9, INF, 0, INF},
        {INF, INF, INF, 4, 5, INF, 0}}
    };
    // 가중치 인접 행렬
    
    shortest_path(&g, 0);
    
    return 0;
}
