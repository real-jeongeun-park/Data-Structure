#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct{
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *p){
    p->top = -1;
    p->capacity = 1;
    p->data = (element *)malloc(sizeof(element) * (p->capacity));
}

int is_empty(StackType *p){
    return (p->top == -1);
}

int is_full(StackType *p){
    return (p->top == (s->capacity - 1));
}

void push(StackType *p, element item){
    if(is_full(p)){
        p->capacity *= 2;
        p->data = (element *)realloc(p->data, sizeof(element) * (p->capacity));
    }
    
    p->data[++(p->top)] = item;
}

element pop(StackType *p){
    if(is_empty(p)){
        fprintf(stderr, "스택 공백 상태\n");
        exit(1);
    }
    
    else{
        return p->data[(p->top)--];
    }
}

element peek(StackType *p){
    if(is_empty(p)){
        fprintf(stderr, "스택 공백 상태\n");
        exit(1);
    }
    
    else{
        return p->data[(p->top)];
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
    
    free(s.data);
}
