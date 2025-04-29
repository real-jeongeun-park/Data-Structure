#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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

int priority(char ch1){
    switch(ch1){
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
}

void infix_to_postfix(char expr[]){
    StackType p;
    char ch, top_op;
    int len = strlen(expr);
    init_stack(&p);
    
    for(int i = 0; i < len; i++){
        ch = expr[i];
        switch(ch){
            case ')':
                while((top_op = pop(&p)) != '('){
                    printf("%c", top_op);
                }
                break;
            
            case '(':
				         push(&p, ch); break;
				                        
            case '+': case '-': case '*': case '/':
                while(!is_empty(&p) && priority(ch) <= priority(peek(&p))){
                    printf("%c", pop(&p));
                }
                push(&p, ch); break;
                
            default:
                printf("%c", ch);
                break;
        }
    }
    
    while(!is_empty(&p)){
        printf("%c", pop(&p));
    }
}


int main()
{
    char *s = "(2+3)*4+9";
    printf("중위표시수식 : %s\n", s);
    printf("후위표시수식 : ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}
