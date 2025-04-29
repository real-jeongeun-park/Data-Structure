#include <stdio.h>
#define MAX_NUM 100

typedef struct{
    int row;
    int col;
    int value;
} element;

typedef struct{
    element data[MAX_NUM];
    int rows; // 행 수
    int cols; // 열 수
    int terms; // 항 수
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a){
    SparseMatrix b;
    b.terms = a.terms;
    b.rows = a.cols;
    b.cols = a.rows;
    int bindex = 0;
    
    for(int i = 0; i < a.cols; i++){
        for(int j = 0; j < a.terms; j++){
            if(a.data[j].col == i){
                b.data[bindex].value = a.data[j].value;
                b.data[bindex].col = a.data[j].row;
                b.data[bindex++].row = a.data[j].col;
                if(bindex >= a.terms) break;
            }
        }
    }
    
    return b;
}

void matrix_print(SparseMatrix mat){
    for(int i = 0; i < mat.terms; i++){
        printf("(%d, %d, %d)\n", mat.data[i].row, mat.data[i].col, mat.data[i].value);
    }
}

int main()
{
    SparseMatrix m = {{{0, 0, 2}, {0, 1, 3}, {1, 0, 8}, {1, 1, 9}, {1, 2, 1},
        {2, 0, 7}, {2, 2, 5}}, 3, 3, 7};
    SparseMatrix result;
    
    result = matrix_transpose2(m);
    matrix_print(result);
    return 0;
}

