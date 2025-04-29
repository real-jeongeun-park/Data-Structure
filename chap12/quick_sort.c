#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];

int partition(int list[], int left, int right){
    int low, high, tmp;
    int pivot = left;
    low = left;
    high = right+1;
    
    do{
        do{
            low++;
        } while(list[pivot] > list[low] && low <= right);
        do{
            high--;
        } while(list[pivot] < list[high]);
        
        if(low < high) SWAP(list[low], list[high], tmp);
    } while(low < high);
    
    SWAP(list[pivot], list[high], tmp);
    return high;
}

void quick_sort(int list[], int left, int right){
    if(left < right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    } 
    
    quick_sort(list, 0, MAX_SIZE-1);
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
