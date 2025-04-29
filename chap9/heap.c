#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENT 100
typedef struct{
    int key; // 식별
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size; // 인덱스 역할. 히프는 1부터 인덱스로 다룸 
} HeapType;

HeapType* create(){
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    if(!tmp) exit(1);
    else return tmp;
}

void init(HeapType *h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element target){
    int child, parent;
    if((h->heap_size) == (MAX_ELEMENT - 1)) return;
    
    child = ++(h->heap_size);
    h->heap[child] = target;
    parent = child / 2;
    
    while(child != 1){
        if(h->heap[parent].key < target.key){
            h->heap[child] = h->heap[parent];
            child = parent;
            parent = parent / 2;
        }
        
        else break;
    }
    
    h->heap[child] = target;
}

element delete_max_heap(HeapType *h){
    if(h->heap_size == 0) exit(1);
    if(h->heap_size == 1) return h->heap[(h->heap_size)--];
    
    element item = h->heap[1];
    element last = h->heap[(h->heap_size)--];
    h->heap[1] = last;
    
    int child, parent;
    parent = 1;
    child = parent * 2;
    
    while(child <= h->heap_size){
        if(h->heap[child].key < h->heap[child+1].key){
            child++;
        }
        
        if((child <= h->heap_size) && (h->heap[child].key > last.key)){
            h->heap[parent] = h->heap[child];
            parent = child;
            child = child * 2;
        }
        
        else break;
    }
    
    h->heap[parent] = last;
    return item;
}


int main(void){
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType *heap;
    
    heap = create(); // 동적으로 생성
    init(heap);
    
    insert_max_heap(heap, e1); // 최대 우선순위 히프
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    
    e4 = delete_max_heap(heap);
    printf("< %d >" , e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d >", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d >\n", e6.key);
    
    free(heap);
    return 0;
}
