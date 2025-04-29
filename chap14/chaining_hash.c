#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
#define TABLE_SIZE 7 // 소수 사용
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    int key;
} element;

typedef struct list{
    element item;
    struct list* link;
} list;

list *hash_table[TABLE_SIZE];

int hash_function(int key){
    // 제산 함수
    int res = key % TABLE_SIZE;
    
    if(res < 0){
        res += TABLE_SIZE;
    }
    
    return res;
}

void hash_chain_add(element e, list *ht[]){
    int hash_index = hash_function(e.key);
    list *before, *p, *new;
    
    before = NULL;
    new = (list*)malloc(sizeof(list));
    new->item = e;
    new->link = NULL;
    
    for(p = ht[hash_index]; p; p = p->link){
        if(p->item.key == e.key){
            fprintf(stderr, "이미 존재하는 항목.\n");
            return;
        }
        
        before = p;
    }
    
    if(before) before->link = new;
    else ht[hash_index] = new;
}

void hash_chain_print(list *ht[]){
    list *p;
    printf("===================\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d] ", i);
        p = ht[i];
        for(; p; p = p->link){
            printf("%d -> ", p->item.key);
        }
        printf("\n");
    }
    printf("===================\n\n");
}

void hash_chain_search(element e, list *ht[]){
    int hash_index = hash_function(e.key);
    list *p = ht[hash_index];
    
    for(; p; p = p->link){
        if(e.key == p->item.key){
            printf("탐색 성공: 키 %d, 해시 테이블 인덱스 %d\n", p->item.key, hash_index);
            return;
        }
    }
    
    printf("탐색 실패\n");
}

int main()
{
    int data[SIZE] = {8, 1, 9, 6, 13};
    element e;
    
    for(int i = 0; i < SIZE; i++){
        e.key = data[i];
        hash_chain_add(e, hash_table);
        hash_chain_print(hash_table);
        // 매번 추가된 결과를 보임
    }
    
    for(int i = 0; i < SIZE; i++){
        e.key = data[i];
        hash_chain_search(e, hash_table);
    }
    
    return 0;
}
