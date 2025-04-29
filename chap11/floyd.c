#include <stdlib.h>
#include <stdio.h>
#define MAX 50
#define INF 100000
typedef struct{
    int n; // vertex 개수
    int weight[MAX][MAX]; // 가중치 인접 행렬
} GraphType;

int A[MAX][MAX]; // 각 단계에서의 최단 경로.

void print_A(GraphType *g){
    printf("==========================\n");
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            if(A[i][j] == INF) printf(" *  ");
            else printf("%2d  ", A[i][j]);
        }
        printf("\n");
    }
    printf("==========================\n\n\n");
}

void floyd(GraphType *g){
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            A[i][j] = g->weight[i][j];
        }
    }
    print_A(g);

    for(int k = 0; k < g->n; k++){
        for(int i = 0; i < g->n; i++){
            for(int j = 0; j < g->n; j++){
                if(A[i][j] > A[i][k]+g->weight[k][j]){
                    A[i][j] = A[i][k]+g->weight[k][j];
                }
            }
        }
        print_A(g);
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
    
    floyd(&g);
    return 0;
}
