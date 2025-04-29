#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct{
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2){
    return strcmp(e1.word, e2.word);
    
    // e1 < e2 이면 -1
    // e1 > e2 이면 1
    // e1 == e2 이면 0
}

void display(TreeNode *p){
    if(p == NULL) return;
    printf("(");
    display(p->left);
    printf("%s, %s ", p->key.word, p->key.meaning);
    display(p->right);
    printf(")");
}

// ?????? 예제랑 조금 다름

TreeNode* search(TreeNode *root, element key){
[O    if(root == NULL) return NULL;
    
    if(compare(key, root->key) > 0){
        // 더 크다
        return search(root->right, key);
    }
    
    else if(compare(key, root->key) < 0){
        // 더 작다
        return search(root->left, key);
    }
    
    else{
        // 같다
        return root;
    }
}

TreeNode* new_node(element item){
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->key = item;
    tmp->left = tmp->right = NULL;
    return tmp;
}

TreeNode *insert_node(TreeNode *node, element key){
    if(node == NULL){
        return new_node(key);
    }
    
    if((compare(key, node->key)) > 0){
        //더 크다
        node->right = insert_node(node->right, key);
    }
    
    else if((compare(key, node->key)) < 0){
        // 더 작다
        node->left = insert_node(node->left, key);
    }
    
    else if((compare(key, node->key)) == 0){
        // 같다
        printf("이미 있는 노드는 삽입할 수 없음.\n");
    }
    
    return node;
}

TreeNode* min_value_node(TreeNode *node){
    for(; node->left; node=node->left){}
    return node;
}

TreeNode *delete_node(TreeNode *root, element key){
    if(root == NULL) return root;
    
    if(compare(key, root->key) == 1){
        // 더 크다
        root->right = delete_node(root->right, key);
        return root;
    }
    
    else if(compare(key, root->key) == -1){
        root->left = delete_node(root->left, key);
        return root;
    }
    
    else{
        // 같다
        
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
        
        // 둘다 있다
        TreeNode *tmp = min_value_node(root->right);
        root->key = tmp->key;
        root->right = delete_node(root->right, tmp->key);
        return root;
    }
}



int main(void){
    char command;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;
    
    do{
        printf("*** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
        command = getchar();
        getchar();
        
        switch(command){
            case 'i':
                printf("단어:");
                gets(e.word);
                printf("의미:");
                gets(e.meaning);
                root = insert_node(root, e);
                break;
                
            case 'd':
                printf("단어:");
                gets(e.word);
                root = delete_node(root, e);
                break;
                
            case 's':
                printf("단어:");
                gets(e.word);
                tmp = search(root, e);
                if(tmp != NULL){
                    printf("의미:%s\n", tmp->key.meaning);
                }
                break;
                
            case 'p':
               display(root);
               printf("\n");
               break;
        }
    } while(command != 'q');
    
    return 0;
}
