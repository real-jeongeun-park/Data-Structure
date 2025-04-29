#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void error(const char *s){
    printf("%s\n", s);
    exit(1);
}

ListNode * insert_first(ListNode *head, element item){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if(p == NULL){
        error("메모리 할당 실패");
    }
    
    p->data = item;
    p->link = head;
    head = p;
    
    return head;
}

ListNode * insert(ListNode *head, ListNode *pre, element item){
    // 선행 노드가 pre
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if(p == NULL){
        error("메모리 할당 실패");
    }
    
    p->data = item;
    p->link = pre->link;
    pre->link = p;
    
    return head;
}

ListNode * delete_first(ListNode *head){
    ListNode *removed;
    removed = head;
    head = head->link;
    
    free(removed);
    return head;
}

ListNode * delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre->link;
    pre = removed->link;
    
    free(removed);
    return head;
}

void print_list(ListNode *p){
    for(; p != NULL; p = p->link){
        printf("%d->", p->data);
    }
    
    printf("NULL\n");
}

ListNode* concat_list(ListNode *head1, ListNode *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    ListNode *p = head1;
    while(p->link != NULL){
        p = p->link;
    }
    
    p->link = head2;
    return head1;
}

int main()
{
    ListNode *head1 = NULL; // 연결 리스트 생성
    ListNode *head2 = NULL;
    
    for(int i = 1; i < 4; i++){
        head1 = insert_first(head1, i*10);
    }
    print_list(head1);
    
    for(int i = 4; i < 6; i++){
        head2 = insert_first(head2, i*10);
    }
    print_list(head2);
    
    head1 = concat_list(head1, head2);
    print_list(head1);
    
    return 0;
}

