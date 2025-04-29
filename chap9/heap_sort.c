#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENT 100
#define SIZE 8
typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int size;
} HeapType;

HeapType* create(){
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    if(!tmp) exit(1);
    else tmp;
}

void init(HeapType *h){
    h->size = 0;
}

void insert_max_heap(HeapType *h, element target){
    if(h->size == (MAX_ELEMENT - 1)) return;
    int index = ++h->size;
    h->heap[index] = target;
    
    while((index != 1) && (target.key > h->heap[index / 2].key)){
        h->heap[index] = h->heap[index / 2];
        index = index / 2;
    }
    
    h->heap[index] = target;
}

element delete_max_heap(HeapType *h){
    element tmp, item;
    int child, parent;
    item = h->heap[1];
    tmp = h->heap[(h->size)--];
    
    parent = 1;
    child = 2;
    
    while(child <= h->size){
        if((child < h->size) && (h->heap[child].key < h->heap[child+1].key)){
            child++;
        }
        
        if(tmp.key >= h->heap[child].key) break;
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child = child * 2;
    }
    
    h->heap[parent] = tmp;
    return item;
}

void heap_sort(element a[], int size){
    HeapType *heap = create();

    for(int i = 0; i < size; i++){
        insert_max_heap(heap, a[i]);
    }
    
    for(int i = size - 1; i >= 0; i--){
        a[i] = delete_max_heap(heap);
    }
    
    // 배열은 주소가 복사됨. 따로 리턴 필요 없음.
}

int main(void){
    element list[8] = {{23}, {56}, {11}, {9}, {56}, {99}, {27}, {34}};
    // element list[8] = {23, 56, 11, 9, 56, 99, 27, 34}와 같이 쓰기도 가능.
    heap_sort(list, SIZE);
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", list[i].key);
    }
    
    printf("\n");
    return 0;
}
