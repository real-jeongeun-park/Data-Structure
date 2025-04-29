#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];

void insertion_sort(int list[], int n){
    int key, j;
    
    for(int i = 1; i < n; i++){
        key = list[i];
        
        for(j = i-1; j >= 0 && list[j] > key; j--){
            list[j+1] = list[j];
        }
        
        list[j+1] = key;
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    }
    
    insertion_sort(list, MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
