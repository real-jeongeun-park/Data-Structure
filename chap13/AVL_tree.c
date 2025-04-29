// AVL 트리는 이진 균형 탐색 트리다. 그러니, 구조체 구현은 이진 탐색
// 트리 형태로 하자.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define max(x, y) ((x > y) ? (x) : (y)) 

typedef struct AVLNode{
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

AVLNode *create_node(int key){
    AVLNode* tmp = (AVLNode*)malloc(sizeof(AVLNode));
    if(!tmp) exit(1);
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

int get_height(AVLNode *node){
    int left, right;
    if(node == NULL) return 1;
    left = get_height(node->right);
    right = get_height(node->left);
    return 1 + max(right, left);
}

int get_balance(AVLNode* node){
    return (get_height(node->left) - get_height(node->right));
}

AVLNode* rotate_right(AVLNode *parent){
    AVLNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

AVLNode* rotate_left(AVLNode *parent){
    AVLNode* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

AVLNode* insert(AVLNode* node, int key){
    if(node == NULL){
        return (create_node(key));
    }
    
    if(node->key > key){
        node->left = insert(node->left, key);
    }
    
    else if(node->key < key){
        node->right = insert(node->right, key);
    }
    
    else{
        printf("같은 키를 가지는 노드를 추가할 수 없음.\n");
        return node;
    }
    
    // 노드 추가 완료된 상태
    
    int balance = get_balance(node);
    
    // LL 타입 회전
    if(balance > 1 && node->left->key > key){
        return rotate_right(node);
    }
    
    // RR 타입 회전
    if(balance < -1 && node->right->key < key){
        return rotate_left(node);
    }
    
    // RL 타입 회전
    if(balance < -1 && node->right->key > key){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    
    // LR 타입 회전
    if(balance > 1 && node->left->key < key){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    
    
    return node;
}

void preorder(AVLNode *root){
    if(root == NULL) return;
    printf("[%d] ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main(void){
    AVLNode *root = NULL;
    
    for(int i = 1; i < 6; i++){
        root = insert(root, i*10);
    }
    
    root = insert(root, 29);
    
    printf("전위 순회 결과\n");
    preorder(root);
    
    return 0;
}
