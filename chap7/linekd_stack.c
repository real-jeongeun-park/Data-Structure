#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int element;
typedef struct StackNode{
    struct StackNode *link;
    element data;
} StackNode;

typedef struct LinkedStackType {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s){
    s->top = NULL;
}

int is_empty(LinkedStackType *s){
    if(s->top == NULL) return 1;
    else return 0;
}

void push(LinkedStackType *s, element item){
    StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
    if(!tmp) return;
    tmp->data = item;
    tmp->link = s->top;
    s->top = tmp;
}

element pop(LinkedStackType *s){
    if(is_empty(s)){
        printf("비어 있음\n");
        exit(1);
    }
    StackNode *target = s->top;
    element data = target->data;
    s->top = s->top->link;
    free(target);
    return data;
}

element peek(LinkedStackType *s){
    if(is_empty(s)){
        printf("비어 있음\n");
        exit(1);
    }
    return s->top->data;
}

void print_stack(LinkedStackType *s){
    StackNode* p = s->top;
    for(; p; p = p->link){
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(void)
{
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    
    return 0;
}
