#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct TreeNode{
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct{
    TreeNode *ptree;
    char ch;
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int size;
} HeapType;

HeapType* create(){
    HeapType *tmp = (HeapType*)malloc(sizeof(HeapType));
    if(!tmp) exit(1);
    else return tmp;
}

void init(HeapType *h){
    h->size = 0;
}

void insert_min_heap(HeapType *h, element target){
    if(h->size == (MAX_ELEMENT - 1)) return;
    int index = ++(h->size);
    h->heap[index] = target;
    
    while(index != 1){
        if(h->heap[index / 2].key > target.key){
            h->heap[index] = h->heap[index / 2];
            index = index / 2;
        }
        else break;
    }
    
    h->heap[index] = target;
}

element delete_min_heap(HeapType *h){
    if(h->size == 0) exit(1);
    element tmp, item;
    int parent = 1, child = 2;
    item = h->heap[1];
    tmp = h->heap[(h->size)--];
    
    while(child <= h->size){
        if((child < h->size) && (h->heap[child].key > h->heap[child+1].key)){
            child++;
        }
        
        if(tmp.key <= h->heap[child].key){
            break;
        }
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    
    h->heap[parent] = tmp;
    return item;
}


TreeNode* make_tree(TreeNode* left, TreeNode* right){
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
    if(!tmp) exit(1);
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

void destroy_tree(TreeNode *root){
    if(!root) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int is_leaf(TreeNode *root){
    return (root->left == NULL && root->right == NULL);
}

void print_codes(TreeNode *root, int codes[], int top){
    
    if(root->left != NULL){
        codes[top] = 1;
        print_codes(root->left, codes, top+1);
    }
    
    if(root->right != NULL){
        codes[top] = 0;
        print_codes(root->right, codes, top+1);
    }
    
    if(is_leaf(root)){
        printf("%c: ", root->ch);
        for(int i = 0; i < top; i++){
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}


void huffman_tree(int freq[], char ch_list[], int n){
    int i;
    TreeNode *node, *x;
    HeapType *heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;
    
    heap = create();
    init(heap);
    
    for(i = 0; i < n; i++){
        node = make_tree(NULL, NULL);
        e.key = node->weight = freq[i];
        e.ch = node->ch = ch_list[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }
    
    for(i = 0; i < n-1; i++){
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d\n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }
    
    e = delete_min_heap(heap);
    
    print_codes(e.ptree, codes, top);
    destroy_tree(e.ptree);
    free(heap);
}

int main()
{
    char ch_list[] = {'s', 'i', 'n', 't', 'e'};
    int freq[] = {4, 6, 8, 12, 15};
    huffman_tree(freq, ch_list, 5);
    return 0;
}

