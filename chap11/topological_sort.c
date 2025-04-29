// 출력
// 그래프 위상 정렬 알고리즘
// 1 제거 -> 0 제거 -> 4 제거 -> 2 제거 -> 3 제거 -> 5 제거 ->

#include <stdlib.h>
#include <stdio.h>
#define MAX 50
#define MAX_STACK_SIZE 10
#define INF 100000
#define TRUE 1 
#define FALSE 0 

typedef int element;
typedef struct{
    int top;
    element stack[MAX_STACK_SIZE];
} StackType;

void stack_init(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item){
    if(is_full(s)) return;
    s->stack[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)) exit(1);
    return s->stack[(s->top)--];
}

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct{
    int n; // vertex 개수
    GraphNode* adj_list[MAX]; // head 주소값
} GraphType;

int in_degree[MAX]; // 각 정점의 진입 차수 기록
int deleted[MAX];

void graph_init(GraphType *g){
    g->n = 0;
    for(int i = 0; i < MAX; i++){
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType *g, int v){
    if(g->n >= MAX){
        return;
    }
    
    g->n++;
}

void insert_edge(GraphType *g, int u, int v){
    if(g->n <= u || v >= g->n){
        return;
    }
    
    GraphNode *tmp = (GraphNode*)malloc(sizeof(GraphNode));
    tmp->vertex = v;
    tmp->link = NULL;
    
    if(!g->adj_list[u]){
        g->adj_list[u] = tmp;
    }
    
    else{
        GraphNode *p;
        for(p = g->adj_list[u]; p->link; p=p->link){}
        p->link = tmp;
    }
}

void in_degree_print(){
    for(int i = 0; i < 6; i++){
        printf("%d ",in_degree[i]);
    }
    printf("\n\n");
}

int topo_sort(GraphType *g){
    int w;
    StackType s;
    stack_init(&s);
    
    for(int i = 0; i < g->n; i++){
        for(GraphNode *p = g->adj_list[i]; p; p = p->link){
            in_degree[p->vertex]++;
        }
        deleted[i] = FALSE;
    }
        
    for(int i = 0; i < g->n; i++){
        // n개 전부 정렬해야 한다.
        for(int j = 0; j < g->n; j++){
            if(!deleted[j] && in_degree[j] == 0){
                // 0이다
                push(&s, j);
            }
        }
        
        while(!is_empty(&s)){
            w = pop(&s);
            printf("%d 제거 -> ", w);
            deleted[w] = TRUE;
            
            for(GraphNode* p = g->adj_list[w]; p; p = p->link){
                in_degree[p->vertex]--;
            }
        }
    }
    
    for(int i = 0; i < g->n; i++){
        if(!deleted[i]) return 0;
    }
    
    return 1;
}

int main(void){
    GraphType g;
    graph_init(&g);
    
    for(int i = 0; i < 6; i++){
        insert_vertex(&g, i);
    }
    
    //정점 0
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    
    //정점1
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    
    //정점2
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);
    
    //정점3
    insert_edge(&g, 3, 5);
    
    //정점4
    insert_edge(&g, 4, 5);
    
    printf("그래프 위상 정렬 알고리즘\n");
    topo_sort(&g);
    printf("\n");
    return 0;
}
