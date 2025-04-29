#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
typedef struct{
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} Dictionary;

Dictionary list[SIZE];

void insertion_sort(Dictionary list[], int n){
    int i, j, least, tmp;
    char key_word[MAX_WORD_SIZE];
    char key_meaning[MAX_MEANING_SIZE];
    for(i = 1; i < n; i++){
        strcpy(key_word, list[i].word);
        strcpy(key_meaning, list[i].meaning);
        for(j = i-1; j >= 0 && (strcmp(list[j].word, key_word) > 0); j--){
            list[j+1] = list[j];
        }
        strcpy(list[j+1].word, key_word);
        strcpy(list[j+1].meaning, key_meaning);
    }
}

int main(void)
{
    printf("5개의 단어와 의미를 입력하시오.\n");
    for(int i = 0; i < SIZE; i++){
        scanf("%s[^\n]", list[i].word);
        scanf("%s[^\n]", list[i].meaning);
    }
    printf("\n");
    
    insertion_sort(list, SIZE);
    
    printf("정렬 후 사전의 내용: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%s: %s\n", list[i].word, list[i].meaning);
    }
    printf("\n");
    return 0;
}

