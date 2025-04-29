#include <stdio.h>
#define ROWS 3
#define COLS 3

void matrix_transpose(int a[][COLS], int b[][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < ROWS; j++){
            b[j][i] = a[i][j];
        }
    }
}

void matrix_print(int a[][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int array1[ROWS][COLS] = {{2, 3, 0}, {8, 9, 1}, {7, 0, 5}};
    int array2[ROWS][COLS]; // transpose
    matrix_print(array1);
    matrix_transpose(array1, array2);
    matrix_print(array2);
    return 0;
}
