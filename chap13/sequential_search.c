// 정렬되지 않은 배열의 항목을 처음부터 마지막까지 하나씩 검사해 원하는 항목을 찾는
// 탐색 방법이다. 찾지 못할 경우 -1 반환.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 10 
int list[SIZE];

int seq_search(int key, int low, int high){
    for(int i = low; i <= high; i++){
        if(list[i] == key) return i;
    }
    
    return -1;
}

int main(void){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        list[i] = rand() % 100;
    }
    
    int res = seq_search(35, 0, SIZE-1);
    
    if(res != -1) printf("찾았음.\n");
    else printf("찾지 못함.\n");
}
