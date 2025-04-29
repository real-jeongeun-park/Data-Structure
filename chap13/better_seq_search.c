// 비교 횟수를 줄이는 방법.
// 리스트의 끝에 찾자 하는 키값을 저장하고 반복문의 탈출 조건을 키를 차즐 때까지로 한다.
// 연산의 수를 반으로 줄일 수 있다.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 20
int list[SIZE];

int seq_search(int key, int low, int high){
    int i;
    
    list[high+1] = key;
    for(i = low; list[i] != key; i++);
    
    if(i == high+1) return -1;
    else return i;
}

int main(void){
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        list[i] = rand() % 100;
    }
    
    int res = seq_search(35, 0, 10);
    
    if(res != -1) printf("찾았음.\n");
    else printf("찾지 못함.\n");
}
