#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
//      15
//   4      20
// 1      16  25
// 스택 이용해서 구현. 반복으로 중위 순회.
typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int top = -1;
TreeNode* stack[MAX_STACK_SIZE];
 
void push(TreeNode *p){
    if((MAX_STACK_SIZE-1) <= top){
        return;
    }
    
    stack[++top] = p;
}

TreeNode* pop(){
    if(top == -1) exit(1);
    
    return stack[top--];
}

void inorder_iter(TreeNode *root){
    while(1){
        for(; root; root = root->left){
            push(root);
        }
        
        root = pop();
        if(root == NULL) break;
        printf("[%d]", root->data); // 방문
        root = root->right;
    }
    
}
 
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {16, NULL, NULL};
TreeNode n3 = {25, NULL, NULL};
TreeNode n4 = {4, &n1, NULL};
TreeNode n5 = {20, &n2, &n3};
TreeNode n6 = {15, &n4, &n5};
TreeNode *root = &n6;

int main()
{
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");
}
