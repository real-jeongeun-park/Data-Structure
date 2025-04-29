#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element[100];
typedef struct DListNode{
    struct DListNode *rlink, *llink;
    element data;
} DListNode;

void init(DListNode *head){
    head->rlink = head->llink = head;
}

DListNode *current = NULL;

void dinsert(DListNode *head, element item){
    // 스택 구조로 쌓음
    DListNode *tmp = (DListNode*)malloc(sizeof(DListNode));
    if(!tmp) return;
    strcpy(tmp->data, item);
    
    tmp->rlink = head->rlink;
    tmp->llink = head;
    head->rlink->llink = tmp;
    head->rlink = tmp;
}

void print_dlist(DListNode *head){
    DListNode *p = head->rlink;
    do{
        if(p == current) printf("<-| #%s# |-> ", p->data);
        else printf("<-| %s |-> ", p->data);
        p = p->rlink;
    } while(p != head);
}


int main(void)
{
    char ch;
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    
    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "fernando");
    
    current = head->rlink;
    print_dlist(head);
    
    do{
        printf("\n명령어를 입력하시오(<, >, q): ");
        ch = getchar();
        if(ch == '<'){
            current = current->llink;
            if(current == head){
                current = current->llink;
            }
        }
        
        else if(ch == '>'){
            current = current->rlink;
            if(current == head){
                current = current->rlink;
            }
        }
        print_dlist(head);
        getchar();
    } while(ch != 'q');
}
