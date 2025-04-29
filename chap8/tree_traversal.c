#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
} TreeNode;

// 밑에서부터 위로 올라가는 구조
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {16, NULL, NULL};
TreeNode n3 = {25, NULL, NULL};
TreeNode n4 = {4, &n1, NULL};
TreeNode n5 = {20, &n2, &n3};
TreeNode n6 = {15, &n4, &n5};
TreeNode *root = &n6;

//      15
//   4      20
// 1      16  25

TreeNode* inorder(TreeNode *root){
    // LVR
    if(root == NULL) return NULL;
    inorder(root->left);
    printf("[%d] ", root->data);
    inorder(root->right);
}

TreeNode* preorder(TreeNode *root){
    if(root == NULL) return NULL;
    printf("[%d] ", root->data);
    preorder(root->left);
    preorder(root->right);
}

TreeNode* postorder(TreeNode *root){
    if(root == NULL) return NULL;
    postorder(root->left);
    postorder(root->right);
    printf("[%d] ", root->data);
    
}

int main(void){
    printf("중위 순회=");
    inorder(root);
    printf("\n");
    
    printf("전위 순회=");
    preorder(root);
    printf("\n");
    
    printf("후위 순회=");
    postorder(root);
    printf("\n");
    
    return 0;
}
