#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TWO_NODE 2
#define THREE_NODE 3
#define NO_DATA -1000000

typedef struct Tree23Node{
    int data1, data2;
    struct Tree23Node* left;
    struct Tree23Node* mid;
    struct Tree23Node* right;
    int type;
} Tree23Node;

Tree23Node* create(int data1, int data2, int type){
    Tree23Node* tmp = (Tree23Node*)malloc(sizeof(Tree23Node));
    if(!tmp) exit(1);
    tmp->data1 = data1;
    tmp->data2 = data2;
    tmp->type = type;
    tmp->left = tmp->mid = tmp->right = NULL;
    return tmp;
}

Tree23Node* insert_23node(Tree23Node* root, int data1, int data2, int type){
    if(root == NULL){
        return create(data1, data2, type);
    }
    
    if(root->type == TWO_NODE){
        if(type == TWO_NODE){
            if(root->data1 < data1){
                root->right = insert_23node(root->right, data1, data2, type);
            }
            
            else if(root->data1 > data1){
                root->left = insert_23node(root->left, data1, data2, type);
            }
            
            else{
                // 키 값 같으면 안됨
                printf("중복 키 오류\n");
                return root;
            }
        }
        
        else if(type == THREE_NODE){
            if(root->data1 > data2){
                root->left = insert_23node(root->left, data1, data2, type);
            }
            
            else if(root->data1 < data1){
                root->right = insert_23node(root->right, data1, data2, type);
            }
            
            else return root;
        }
    }
    
    else if(root->type == THREE_NODE){
        if(type == TWO_NODE){
            if(data1 < root->data1){
                root->left = insert_23node(root->left, data1, data2, type);
            }
            
            else if(data1 > root->data1 && data1 < root->data2){
                root->mid = insert_23node(root->left, data1, data2, type);
            }
            
            else if(data1 > root->data2){
                root->right = insert_23node(root->right, data1, data2, type);
            }
            
            else return root;
        }
        
        else if(type == THREE_NODE){
            if(data2 < root->data1){
                root->left = insert_23node(root->left, data1, data2, type);
            }
            
            else if(data1 > root->data1 && data2 < root->data2){
                root->mid = insert_23node(root->mid, data1, data2, type);
            }
            
            else if(data1 > root->data2){
                root->right = insert_23node(root->right, data1, data2, type);
            }
            else return root;
        }
    }
    
    return root;
}

void print_tree(Tree23Node *root){
    // 루트(root), 좌, 중(middle), 우 순서 출력
    if(root == NULL) return;
    
    if(root->type == TWO_NODE){
        printf("[%d] ", root->data1);
        print_tree(root->left);
        print_tree(root->right);
    }
    
    else if(root->type == THREE_NODE){
        printf("[%d] [%d] ", root->data1, root->data2);
        print_tree(root->left);
[O        print_tree(root->mid);
        print_tree(root->right);
    }
}

Tree23Node* tree23_search(Tree23Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    
    else if(key == root->data1 || key == root->data2){
        return root;
    }
    
    else if(root->type = TWO_NODE){
        if(root->data1 > key){
            return tree23_search(root->left, key);
        }
        
        else{
            return tree23_search(root->right, key);
        }
    }
    
    else{
        // THREE NODE일 경우,
        if(root->data1 > key){
            return tree23_search(root->left, key);
        }
        
        else if(root->data1 < key && root->data2 > key){
            return tree23_search(root->mid, key);
        }
        
        else return tree23_search(root->right, key);
    }
}

int main(void){
    Tree23Node *root = NULL;
    root = insert_23node(root, 50, NO_DATA, TWO_NODE);
    root = insert_23node(root, 10, 35, THREE_NODE);
    root = insert_23node(root, 70, NO_DATA, TWO_NODE);
    root = insert_23node(root, 5, NO_DATA, TWO_NODE);
    root = insert_23node(root, 20, 30, THREE_NODE);
    root = insert_23node(root, 40, NO_DATA, TWO_NODE);
    root = insert_23node(root, 60, NO_DATA, TWO_NODE);
    root = insert_23node(root, 90, NO_DATA, TWO_NODE);
    
    print_tree(root);TW
    printf("\n");
    
    Tree23Node *res = tree23_search(root, 40);
    if(!res) printf("없는 노드\n");
    else printf("탐색한 노드\n");
}
