#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
    int is_thread;
} TreeNode;

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'D', NULL, NULL, 1};
TreeNode n4 = {'E', NULL, NULL, 0};
TreeNode n5 = {'C', &n1, &n2, 0};
TreeNode n6 = {'F', &n3, &n4, 0};
TreeNode n7 = {'G', &n5, &n6, 0};
TreeNode *root = &n7;

TreeNode* find_successor(TreeNode *root){
    TreeNode *p = root;
    p = root->right;
    if(!p || root->is_thread == 1){
        return p;
    }
    
    for(; p->left; p = p->left){}
    return p;
}

// 순환 없이 순회하는 스레드 이진 트리
//      G 
//   C    F
//  A B  D E

void thread_inorder(TreeNode *root){
    // 중위 순회, 순환 함수 x 
    for(; root->left; root = root->left){}
    while(root != NULL){
        printf("%c->", root->data);
        root = find_successor(root);
    }
}

int main(void){
    n1.right = &n5;
    n2.right = &n7; // 다음 방문할 노드 선택
    n3.right = &n6;

    thread_inorder(root);
}
