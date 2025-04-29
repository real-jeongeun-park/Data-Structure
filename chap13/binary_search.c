// 범위 low~high까지 하고, 정렬된 배열에서 중앙 값을 조사하여 찾고자 하는 항목이
// 왼쪽에 있는지 오른쪽에 있는지 조사하여 조사 범위를 반씩 줄여 나가는 것.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 20
int list[SIZE];

int binary_search(int key, int low, int high){
    if(low <= high){
        int middle = (low+high) / 2;
        if(list[middle] == key) return middle;
        else if(list[middle] > key) return binary_search(key, low, middle-1);
        else return binary_search(key, middle+1, high);
    }
    
    return -1;
}

int compare(const void *a, const void *b){
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a == *(int*)b) return 0;
    else return -1;
}

int main(void){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        list[i] = rand() % 100;
    }
    
    qsort((void*)list, SIZE, sizeof(int), compare);
    
    int res = binary_search(35, 0, SIZE-1);
    
    if(res != -1) printf("찾았음.\n");
    else printf("찾지 못함.\n");
}
