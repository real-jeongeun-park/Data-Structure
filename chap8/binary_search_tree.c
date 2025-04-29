#include <stdlib.h>
#include <stdio.h>
typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
} TreeNode;

// 서치
TreeNode *search(TreeNode *node, int key){
    if(node == NULL) return NULL;
    
    if(node->key > key){
        return search(node->left, key);
    }
    
    else if(node->key < key){
        return search(node->right, key);
    }
    
    else{
        return node;
    }
}

TreeNode* new_node(element item){
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->key = item;
    tmp->left = tmp->right = NULL;
    return tmp;
}

TreeNode* insert_node(TreeNode *node, int key){
    if(node == NULL){
        return new_node(key);
    }
    
    if(node->key == key){
        printf("이미 삽입된 값임.\n");
        return node;
    }
    
    if(node->key > key){
        node->left = insert_node(node->left, key);
    }
    
    else if(node->key < key){
        node->right = insert_node(node->right, key);
    }
    
    return node;
}

TreeNode* min_value_node(TreeNode *node){
    for(; node->left; node = node->left){}
    return node;
}

//    10
//  4    14
// 1 6  13 18

TreeNode *delete_node(TreeNode *root, int key){
    // 단말 노드인 경우, 자식 1개 있는 노드인 경우, 2개 있는 노드인 경우
    if(root == NULL){
        printf("삭제할 노드 없음.\n");
        return root;
    }
    
    if(root->key > key){
        root->left = delete_node(root->left, key);
        return root;
    }
    
    else if(root->key < key){
        root->right = delete_node(root->right, key);
        return root;
    }
    
    else{
        // 3가지 케이스 가능
        if(root->right == NULL){
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        }
        
        else if(root->left == NULL){
            TreeNode *tmp = root->right;
            free(root);
            return tmp;
        }
        
        
        TreeNode *tmp = min_value_node(root->right);
        root->key = tmp->key;
        root->right = delete_node(root->right, tmp->key);
        return root;
    }
}

void inorder(TreeNode *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("[%d]", root->key);
    inorder(root->right);
}

int main(void){
    TreeNode *root = NULL;
    TreeNode *tmp = NULL;
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
    
    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");
    
    root = delete_node(root,30);
    inorder(root);
    printf("\n");
    
    if(search(root, 30) != NULL) printf("이진 탐색 트리에서 30을 발견함.\n");
    
    else printf("이진 탐색 트리에서 30을 발견하지 못함.\n");
    
    return 0;
}
