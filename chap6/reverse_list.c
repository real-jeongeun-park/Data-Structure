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

ListNode* reverse(ListNode *head1){
    ListNode * p;
    ListNode * q;
[O    ListNode * r;
    // p는 역순으로 만들 리스트 q는 현재 역순으로 만들 노드
    // r은 이미 역순으로 만든 노드를 가리킨다.
    // 역순 바꾸기 전에 먼저 뒤의 노드 알아둬야 한다
    
    r = head1;
    q = r->link;
    p = q->link;
    r->link = NULL;
    q->link = r;

    while(1){
        // printf("%d %d %d\n", r->data, q->data, p->data);
        r = q;
        q = p;
        
        if(p->link == NULL){
            q->link = r;
            break;
        }
        
        p = p->link;
        q->link = r;
        // printf("%d %d %d\n", r->data, q->data, p->data);
    }
    
    head1 = q;
    
    return head1;
}

int main(){
    ListNode *head1 = NULL; // 연결 리스트 생성
    ListNode *head2 = NULL;
    
    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    head1 = insert_first(head1, 40);
    head1 = insert_first(head1, 50);
    head1 = insert_first(head1, 60);

    print_list(head1);
    
     head2 = reverse(head1);
    print_list(head2);
    
    return 0;
}
