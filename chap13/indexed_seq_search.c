// 인덱스 테이블을 사용하여 탐색의 효율을 높이는 방법. index[i] <= key < index[i+1]
// 을 만족하는 항목을 찾는다. 그리고 그 조건을 만족하는 항목으로부터 주자료 리스트에서
// 순차 탐색을 수행한다.

// 효율성을 위해서 재귀 호출보다는 반복문을 사용하는 것이 좋다.
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

void init_index_table(int list[], int n){
    // n 은 리스트 사이즈. n / m 이 간격이다.
    int gap = n / INDEX_SIZE; // 3의 간격
    for(int i = 0; i < INDEX_SIZE; i++){
        index_table[i].index = gap*i;
        index_table[i].key = list[gap*i];
    }
}

int search_index(int key, int n){
    // indexed sequential search
    int i;
    int target_index = -1;
    if(key > list[n-1] || key < list[0]) return -1;

    for(i = 0; i < INDEX_SIZE-1; i++){
        if(index_table[i].key <= key && key < index_table[i+1].key){
            target_index = i;
            break;
        }
    }
    
    if(i == INDEX_SIZE-1){
        for(int j = index_table[i].index; j <= n-1; j++){
            if(list[j] == key){
                target_index = j;
                break;
            }
        }
    }
    
    if(target_index != -1){
        for(int j = index_table[target_index].index; j < index_table[target_index+1].index; j++){
            if(list[j] == key){
                return j;
            }
        }
    }
    
    return -1;
}

int compare(const void* a, const void* b){
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a == *(int*)b) return 0;
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
    
    init_index_table(list, SIZE);
    int res = search_index(13, SIZE);
    
    if(res != -1) printf("찾았음.\n");
    else printf("찾지 못함.\n");
}
