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

ListNode* search_list(ListNode *head, element item){
    ListNode *p = head;
    for(; p != NULL; p = p->link){
        if(p->data == item) return p;
    }
    
    return NULL;
}

int main()
{
    ListNode *head = NULL; // 연결 리스트 생성
    
    for(int i = 1; i <= 3; i++){
        head = insert_first(head, i*10);
        print_list(head);
    }
    
    if(search_list(head, 30)){
        // NULL이 아님
        printf("리스트에서 30을 찾았습니다.\n");
    }
    else printf("리스트에서 30을 찾지 못했습니다.\n");
    return 0;
    
}

