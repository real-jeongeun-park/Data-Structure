#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
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

int main()
{
    StackType s;
    init_stack(&s);
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}

