#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];

void insertion_sort(int list[], int first, int last, int gap){
    // gap은 부분 리스트의 개수
    int i, j, key;
    for(i = first+gap; i <= last; i += gap){
        key = list[i];
        
        for(j = i-gap; j >= 0 && key < list[j]; j -= gap){
            list[j+gap] = list[j];
        }
        
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n){
    for(int gap = n / 2; gap > 0; gap /= 2){
        if(gap % 2 == 0) gap++;
        for(int i = 0; i < gap; i++){
            // gap 개수만큼의 부분 리스트 생성
            insertion_sort(list, i, n-1, gap);
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    }
    
    shell_sort(list, MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
