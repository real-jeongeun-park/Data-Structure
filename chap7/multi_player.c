#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode{
    struct ListNode *link;
    char data[10];
} ListNode;

ListNode* insert_last(ListNode *head, char name[]){
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    if(!tmp) exit(1);
    tmp->link = NULL;
    strcpy(tmp->data, name);
    
    if(head == NULL){
        head = tmp;
        tmp->link = head;
    }
    
    else{
        tmp->link = head->link;
        head->link = tmp;
        head = tmp;
    }
    
    return head;
}

int main(void)
{
    ListNode *head = NULL;
    head = insert_last(head, "KIM");
    head = insert_last(head, "PARK");
    head = insert_last(head, "CHOI");
    
    ListNode *p = head->link;
    for(int i = 0; i < 10; i++){
        printf("현재 차례: %s\n", p->data);
        p = p->link;
    }
    return 0;
}
