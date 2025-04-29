// 탐색키가 존재하는 위치를 예측하여 탐색하는 방법
// 이진 탐색과 유사하나 불균등 분할하여 탐색.
// 항상 정렬돼 있어야 함.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 9
#define INDEX_SIZE 3
int list[SIZE];
typedef struct{
    int key;
    int index;
} itable;
itable index_table[INDEX_SIZE];
// 인덱스 테이블

int compare(const void* a, const void* b){
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a == *(int*)b) return 0;
    else return -1;
}

int interpol_search(int key, int n){
    int low, high, j;
    low = 0;
    high = n-1;
    
    while(list[high] >= key && list[low] < key){
        j = ((float)(key-list[low]) / (list[high]-list[low]) * (high-low)) + low;
        
        if(key > list[j]) low = j+1;
        else if(key < list[j]) high = j-1;
        else low = j;
    }
    
    if(list[low] == key) return low;
    else return -1;
}

int main(void){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        list[i] = rand() % 20;
    }
    
    qsort(list, SIZE, sizeof(int), compare);
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    
    int res = interpol_search(10, SIZE);
    
    if(res != -1) printf("찾았음.\n");
    else printf("찾지 못함.\n");
}
