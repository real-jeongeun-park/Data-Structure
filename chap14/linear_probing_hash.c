#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 // (탐색)키 최대 길이
#define TABLE_SIZE 13 // 소수 사용 항상
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    char key[KEY_SIZE]; // 최대 10글자의 문자열
} element;

element hash_table[TABLE_SIZE];
// 해시 테이블에 각 항목 들어감.

void init_table(element e[]){
    for(int i = 0; i < TABLE_SIZE; i++){
        e[i].key[0] = '\0'; // \0을 줘서 버킷이 비어 있음.
    }
}

int transform(char *key){
    // 문자를 숫자 키로 변경한다. 그 후 제산 함수 사용.
    // 호너의 방법
    int number = 0;
    while(*key){
        number = 31 * number + *key++;
    }
    return number;
}

int hash_function(char *key){
    // 제산 함수
    int hash_index = transform(key) % TABLE_SIZE;
    if(hash_index < 0){
        hash_index += TABLE_SIZE;
    }
    return hash_index;
}

void hash_lp_add(element item, element ht[]){
    // linear probing으로 선형 조사법을 이용해 추가하는 방식.
    int i, hash_value;
    i = hash_value = hash_function(item.key);
    
    while(!empty(ht[i])){
        // empty가 아닌 동안 수행
        // 즉, 이미 버킷이 채워짐
        if(equal(ht[i], item)){
            fprintf(stderr, "이미 존재하는 항목임.\n");
            return;
        }
        
        i = (i + 1) % TABLE_SIZE;
        
        if(i == hash_value){
            fprintf(stderr, "저장할 공간 부족.\n");
            return;
        }
    }
    
    ht[i] = item;
}

void hash_lp_search(element item, element ht[]){
    int i, hash_value;
    i = hash_value = hash_function(item.key);
    
    while(!empty(ht[i])){
        if(equal(ht[i], item)){
            printf("탐색 성공: 키 %s, 위치 %d\n", ht[i].key, i);
            return;
        }
        
        i = (i+1) % TABLE_SIZE;
        if(i == hash_value){
            fprintf(stderr, "찾는 항목 없음.\n");
            return;
        }
    }
    
    fprintf(stderr, "찾는 항목 없음.\n");
}

void hash_lp_print(element ht[]){
    printf("===========================\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d] ", i);
        if(ht[i].key != NULL){
            printf("%s ", ht[i].key);
        }
        printf("\n");
    }
    printf("===========================\n\n");
}

int main()
{
		init_table(hash_table);
    char *s[7] = {"do", "for", "if", "case", "else", "return", "function"};
    element e;
    
    for(int i = 0; i < 7; i++){
        strcpy(e.key, s[i]);
        hash_lp_add(e, hash_table);
        hash_lp_print(hash_table);
    }
    
    for(int i = 0; i < 7; i++){
        strcpy(e.key, s[i]);
        hash_lp_search(e, hash_table);
    }
    
    return 0;
}
