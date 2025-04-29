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

char eval(char expr[]){
    int op1, op2, value;
    int len = strlen(expr);
    char ch;
    StackType p;
    init_stack(&p);
    
    for(int i = 0; i < len; i++){
        ch = expr[i];
        switch(ch){
            case '/': case '*': case '+': case '-':
                op2 = pop(&p) - '0';
                op1 = pop(&p) - '0';
                if(ch == '/') value = op1/op2;
                else if(ch == '*') value = op1*op2;
                else if(ch == '+') value = op1+op2;
                else if(ch == '-') value = op1-op2;
                push(&p, value + '0');
                break;
                
            default:
                push(&p, ch);
                break;
        }
    }
    
    return (pop(&p) - '0');
}

int main()
{
    // 후위표기식 계산
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;

