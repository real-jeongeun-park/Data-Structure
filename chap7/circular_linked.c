#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
    struct ListNode *link;
    element data;
} ListNode;

ListNode* insert_last(ListNode *head, element item){
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    if(!tmp) exit(1);
    tmp->data = item;
    tmp->link = NULL;
    
    if(head == NULL){
        head = tmp;
        tmp->link = head;
    }
    
    else{
        // head는 가장 마지막 node 가리킴
        tmp->link = head->link;
        head->link = tmp;
        head = tmp;
    }
    
    return head;
}

ListNode* insert_first(ListNode *head, element item){
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    if(!tmp) exit(1);
    tmp->data = item;
    
    if(head == NULL){
        head = tmp;
        tmp->link = head;
    }
    
    else{
        tmp->link = head->link;
        head->link = tmp;
    }
    
    return head;
}

void print_list(ListNode *head){
    ListNode *p = head->link;
    do{
        
        printf("%d->", p->data);
        p = p->link;
        
    } while(head->link != p);
}

int main(void)
{
    ListNode *head = NULL;
    
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    
    return 0;
}
