#include <stdio.h>
int binomial(int n, int k){
    if(k == 0 || k == 0) return 1;
    else if(0 < k && k < n){
        return (binomial(n-1, k-1) + binomial(n-1, k));
    }
}

int main()
{
    printf("C(3,4) = %d\n", binomial(4,3));
    return 0;
}
