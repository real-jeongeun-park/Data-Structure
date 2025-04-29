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

int checking(const char *in){
    StackType p;
    init_stack(&p);
    
    int n = strlen(in);
    char ch, open_ch;
    
    for(int i = 0; i < n; i++){
        // 각각 하나씩 문자 검사
        switch(ch){
            case '[': case '{': case '(':
                push(&p, ch);
                break;
                
            case ')': case ']': case '}':
                if(is_empty(&p)) return 0;
                else{
                    open_ch = pop(&p);
                    if(open_ch == '(' && ch != ')' ||
                        open_ch == '[' && ch != ']' ||
                        open_ch == '{' && ch != '}'
                    ) return 0;
                }
                break;
        }
    }
    
    if(!is_empty(&p)) return 0;
    return 1;
}

int main()
{
    char *p = "{ A[(i+1)]=0 }";
    if(checking(p) == 1) printf("%s 괄호검사성공\n", p);
    else printf("%s 괄호검사실패\n", p);
    return 0;
}
