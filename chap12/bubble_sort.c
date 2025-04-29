#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];

void bubble_sort(int list[], int n){
    int i, j, tmp;
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(list[j] > list[j+1]){
                SWAP(list[j], list[j+1], tmp);
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    }
    
    bubble_sort(list, MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
