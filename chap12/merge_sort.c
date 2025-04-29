#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 8 
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[SIZE];

void sorting_check(int list[], int n){
    printf("\n");
    int max = list[0];
    for(int i = 1; i < n; i++){
        if(max > list[i]){
            printf("제대로 정렬되지 않음.\n");
            return;
        }
        max = list[i];
    }
    
    printf("제대로 정렬됨.\n");
}

void merge(int list[], int left, int middle, int right){
    int sorted[SIZE];
    
    int i = left;
    int j = middle+1;
    int k = left;
    
    while(i <= middle && j <= right){
        if(list[i] < list[j]){
            sorted[k++] = list[i++];
        }
        else sorted[k++] = list[j++];
    }
    
    for(; i <= middle; i++){
        sorted[k++] = list[i];
    }
    
    for(; j <= right; j++){
        sorted[k++] = list[j];
    }
    
    for(int l = left; l <= right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        merge_sort(list, left, middle);
        merge_sort(list, middle+1, right);
        merge(list, left, middle, right);
    }
}


int main(void){
    // merge sort? 잘개 쪼개서 더이상 쪼갤 수 없을 때까지 쪼개고,
    // 그후 합병을 반복.

    srand(time(NULL));

    for(int i = 0; i < SIZE; i++){
        list[i] = rand() % 100;
    }
    
    merge_sort(list, 0, SIZE-1);
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", list[i]);
    }
    
    sorting_check(list, SIZE);
    
    printf("\n");
    return 0;
}
