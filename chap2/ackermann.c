#include <stdio.h>
int ackermann(int m, int n){
    if(m == 0) return n+1;
    else if(n == 0) return ackermann(m-1, 1);
    else if(n >= 1 && m >= 1) return (ackermann(m-1, ackermann(m, n-1)));
}

int main()
{
    printf("A(2,3) : %d\n", ackermann(2,3));
}
