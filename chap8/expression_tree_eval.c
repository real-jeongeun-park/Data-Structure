#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, NULL, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {'*', &n1, &n2};
TreeNode n6 = {'+', &n3, &n4};
TreeNode n7 = {'+', &n5, &n6};
TreeNode* expr = &n7;

//     +
//  *     +
// 1 4  16 25

int evaluate(TreeNode *expr){
    int x, y, op;
    
    if(expr->left == NULL && expr->right == NULL){
        return expr->data;
    }
    
    x = evaluate(expr->left);
    y = evaluate(expr->right);
    op = expr->data;
    
    printf("%d %c %d를 계산합니다.\n", x, op, y);
    switch(op){
        case '+':
            return x + y;
        
        case '-':
            return x - y;
        
        case '*':
            return x * y;
            
        case '/':
            return x / y;
    }
}

int main()
{
    printf("\n수식의 값은 %d입니다. \n", evaluate(expr));
    return 0;
}
