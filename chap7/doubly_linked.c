#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int element;
typedef struct DListNode{
    struct DListNode *rlink, *llink;
    element data;
} DListNode;

void init(DListNode *head){
    head->rlink = head;
    head->llink = head;
}

// head의 오른쪽에 삽입
void dinsert(DListNode *head, element item){
    DListNode *tmp = (DListNode*)malloc(sizeof(DListNode));
    if(!tmp) return;
    tmp->data = item;
    
    tmp->rlink = head->rlink;
    tmp->llink = head;
    head->rlink->llink = tmp;
    head->rlink = tmp;
}

// head의 오른쪽부터 삭제
element ddelete(DListNode *head, DListNode *removed){
    element data;
    if(head == removed) return 0;
    
    data = removed->data;
    removed->rlink->llink = removed->llink;
    head->rlink = removed->rlink; // 순서 바뀌어도 ok

    free(removed);
    return data;
}

void print_dlist(DListNode *head){
    DListNode *p = head->rlink;
    do{
        printf("<-| |%d| |-> ", p->data);
        p = p->rlink;
    } while(p != head);
    printf("\n");
}


int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for(int i = 0; i < 5; i++){
        dinsert(head, i);
        print_dlist(head);
    }
    printf("\n삭제 단계\n");
    for(int i = 0; i < 5; i++){
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    
    free(head);
    return 0;
}
