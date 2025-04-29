#include <stdio.h>
#include <stdlib.h>

int compare(const void* arg1, const void* arg2){
    if(*(double*)arg1 > *(double*)arg2) return 1;
    else if(*(double*)arg1 == *(double*)arg2) return 0;
    else return -1;
}

int main(void){
    int i;
    double list[5] = {2.1, 0.9, 1.6, 3.8, 1.2};
    qsort((void*)list, (size_t)5, sizeof(double), compare);
    // C언어에서 제공하는 퀵 정렬 함수
    // 차례대로 배열의 시작 주소값, 배열 사이즈, 배열 내 요소들의 크기, compare 함수
    
    for(i = 0; i < 5; i++){
        printf("%.1f ", list[i]);
    }
    printf("\n");
}
