#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void init(ArrayListType *p){
    p->size = 0;
}

int is_full(ArrayListType *p){
    return (p->size == MAX_LIST_SIZE);
}

int is_empty(ArrayListType *p){
    return (p->size == 0);
}

int get_length(ArrayListType *p){
    return p->size;
}

element get_entry(ArrayListType *p, int pos){
    if(pos < 0 || pos > (p->size)-1){
        printf("오류\n");
        exit(1);
    }
    
    return p->array[pos];
}

void insert_first(ArrayListType *p, element item){
    if(is_full(p)){
        printf("초과\n");
        return;
    }
    
    for(int i = (p->size)-1; i >= 0; i--){
        p->array[i+1] = p->array[i];
    }
    
    p->array[0] = item;
    (p->size)++;
}

void insert_last(ArrayListType *p, element item){
    if(is_full(p)){
        printf("초과\n");
        return;
    }
    
    p->array[(p->size)++] = item;
}

void insert(ArrayListType *p, int pos, element item){
    if(is_full(p)){
        printf("초과\n");
        return;
    }
    
    if(is_empty(p)){
        p->array[0] = item;
        printf("hello\n");
    }
    
    else{
        for(int i = (p->size)-1; i >= pos; i--){
            p->array[i+1] = p->array[i];
        }
        
        p->array[pos] = item;
    }
    
    (p->size)++;
}

void delete(ArrayListType *p, int pos){
    if(is_empty(p)){
        printf("공백\n");
        return;
    }
    
    // pos+1부터 size-1까지 앞으로 한 칸씩 당기기
    for(int i = pos; i < p->size; i++){
        p->array[i] = p->array[i+1];
    }
    
    (p->size)--;
}

void print_list(ArrayListType *p){
    for(int i = 0; i < p->size; i++){
        printf("%d->", p->array[i]);
    }
    printf("\n");
}

int main()
{
    ArrayListType list;
    init(&list);
    
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete(&list, 0); print_list(&list);
    
    insert_first(&list, 333); print_list(&list);
}

