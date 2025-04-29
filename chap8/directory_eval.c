#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode{
    element size;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {200, NULL, NULL};
TreeNode n2 = {500, NULL, NULL};
TreeNode n3 = {50, NULL, NULL};
TreeNode n4 = {100, &n1, &n2};
TreeNode n5 = {0, &n3, &n4};
TreeNode *root = &n5;

//     ?
// 50     100
//      200 500

element eval(TreeNode *root){
    int x, y, result;
    
    if(!(root->left) && !(root->right)){
        return root->size;
    }
    
    x = eval(root->left);
    y = eval(root->right);
    result = x + y + root->size;
    
    return result;
}

int main(void)
{
    printf("디렉터리 크기 = %d", eval(root));
}
