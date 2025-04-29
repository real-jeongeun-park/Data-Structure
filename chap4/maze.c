#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct{
    short r;
    short c;
} element;

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};

typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *p){
    p->top = -1; // 초기화
}

int is_empty(StackType *p){
    return (p->top == -1);
}

int is_full(StackType *p){
    return (p->top == (MAX_STACK_SIZE -1));
}

void push(StackType *p, element item){
    if(is_full(p)){
        fprintf(stderr, "스택 포화 상태\n");
        return;
    }
    
    else{
        p->stack[++(p->top)] = item;
    }
}

element pop(StackType *p){
    if(is_empty(p)){
        fprintf(stderr, "스택 공백 상태\n");
        exit(1);
    }
    
    else{
        return p->stack[(p->top)--];
    }
}

element peek(StackType *p){
    if(is_empty(p)){
        fprintf(stderr, "스택 공백 상태\n");
        exit(1);
    }
    
    else{
        return p->stack[p->top];
    }
}


void push_loc(StackType *p, int r, int c){
    if(r < 0 || c < 0) return;
    
    element tmp;
    tmp.r = r;
    tmp.c = c;
    
    if(maze[tmp.r][tmp.c] != '1' && maze[tmp.r][tmp.c] != '.'){
        push(p, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    for(int i = 0; i < MAZE_SIZE; i++){
        for(int j = 0; j < MAZE_SIZE; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int r, c;
    StackType s;
    
    init_stack(&s);
    here = entry;
    while(maze[here.r][here.c] != 'x'){
        // 출구 아님
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        // 다녀감 표시
        maze_print(maze);
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c-1);
        push_loc(&s, r, c+1);
        
        if(is_empty(&s)){
            printf("실패\n");
            return 0;
        }
        else{
            here = pop(&s);
        }
    }
    
    printf("성공\n");
    return 0;
}
