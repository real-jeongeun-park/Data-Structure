#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENT 100
#define JOBS 7
#define MACHINES 3
typedef struct{
    int id;
    int avail;
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

void insert_min_heap(HeapType *h, element target){
    if(h->size == (MAX_ELEMENT - 1)) return;
    int index = ++(h->size);
    h->heap[index] = target;
    
    while((index != 1) && (target.avail < h->heap[index / 2].avail)){
        /// key는 avail
        h->heap[index] = h->heap[index / 2];
        index = index / 2;
    }
    
    h->heap[index] = target;
}

element delete_min_heap(HeapType *h){
    if(h->size == 0) exit(1);
    if(h->size == 1) return h->heap[(h->size)--];
    
    element tmp, item;
    int child, parent;
    
    item = h->heap[1];
    tmp = h->heap[(h->size)--];
    
    parent = 1;
    child = 2;
    
    while(h->size >= child){
        if((h->size > child) && (h->heap[child].avail > h->heap[child+1].avail)){
            child++;
        }
        
        if(tmp.avail < h->heap[child].avail) break;
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    
    h->heap[parent] = tmp;
    return item;
}

int main(void){
    int jobs[JOBS] = {8, 7, 6, 5, 3, 2, 1}; // 작업 시간
    element m = {0, 0}; // 초기화로 기계 번호 0, 작업 종료 시간 0
    
    HeapType *heap;
    heap = create();
    init(heap);
    
    for(int i = 0; i < MACHINES; i++){
        element tmp = {i+1, 0}; // id와 종료 시간 초기화
        insert_min_heap(heap, tmp);
    }
    
    for(int i = 0; i < JOBS; i++){
        m = delete_min_heap(heap);
        printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다.\n",
        i, m.avail, m.avail + jobs[i] - 1, m.id);
        m.avail += jobs[i];
        insert_min_heap(heap, m);
    }
    
    return 0;
}
