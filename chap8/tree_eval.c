#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//    n1
//   /  \
// n2    n3

// 단말 노드 개수
int terminal(TreeNode *t){
    int right, left, count;

    if(!t) return 0;
    if(!t->right && !t->left) return 1;
    
    right = terminal(t->right);
    left = terminal(t->left);
    
    return right + left;
}

// 노드 개수
int get_node_count(TreeNode *t){
    int count = 0;
    int left, right;
    if(!t) return 0;
    
    left = get_node_count(t->left);
    right = get_node_count(t->right);
    count = count + 1 + left + right;
    
    return count;
}

int get_height(TreeNode *t){
    int right, left;
    if(!t) return 0;
    
    left = get_height(t->left);
    right = get_height(t->right);
    
    if(left > right) return left + 1;
    else return right + 1;
}

int main(void){
    TreeNode *arr[7];
    element data[7] = {22, 65, 35, 95, 15, 93, 17};
    
    for(int i = 0; i < 7; i++){
        arr[i] = (TreeNode*)malloc(sizeof(TreeNode));
        arr[i]->data = data[i];
    }
    
    arr[0]->left = arr[0]->right = NULL;
    arr[1]->left = arr[1]->right = NULL;
    arr[2]->left = arr[0]; arr[2]->right = NULL;
    arr[3]->left = arr[3]->right = NULL;
    arr[4]->left = arr[1]; arr[4]->right = NULL;
    arr[5]->left = arr[2]; arr[5]->right = arr[3];
    arr[6]->left = arr[4]; arr[6]->right = arr[5];
    
    TreeNode *root = arr[6];
    
    printf("노드의 개수 : %d\n", get_node_count(root));
    printf("단말 노드의 개수 : %d\n", terminal(root));
    printf("트리의 높이 : %d\n", get_height(root));
    
    for(int i = 0; i < 7; i++){
        free(arr[i]);
    }
    
    return 0;
}
