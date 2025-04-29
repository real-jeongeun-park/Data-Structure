#include <stdio.h>

void hanoi_tower(char from, char tmp, char to, int n){
    if(n == 1){
        printf("%d번째 원판을 %c에서 %c로 옮깁니다.\n", n, from, to);
    }
    
    else{
        hanoi_tower(from, to, tmp, n-1);
        printf("%d번째 원판을 %c에서 %c로 옮깁니다.\n", n, from, to);
        hanoi_tower(tmp, from, to, n-1);
    }
}

int main()
{
    hanoi_tower('A', 'B', 'C', 3);
    return 0;
}