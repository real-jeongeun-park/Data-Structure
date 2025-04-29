#include <stdio.h>
#define MAX_NUM 101

typedef struct {
    int degree;
    float coef[MAX_NUM];
} polynomial;

polynomial poly_add1(polynomial a, polynomial b){
    polynomial c;
    int a_pos, b_pos, c_pos;
    int a_deg = a.degree;
    int b_deg = b.degree;
    c.degree = (a_deg > b_deg ? a_deg : b_deg);
    a_pos = b_pos = c_pos = 0;
    
    while(c.degree >= c_pos){
        
        if(a_deg > b_deg){
            c.coef[c_pos++] = a.coef[a_pos++];
            a_deg--;ㅁ
        }
        
        else if(a_deg == b_deg){
            c.coef[c_pos++] = (a.coef[a_pos++] + b.coef[b_pos++]);
            a_deg--; b_deg--;
        }
        
        else{
            c.coef[c_pos++] = b.coef[b_pos++];
            b_deg--;
        }
    }
    
    return c;
}

void print_poly(polynomial poly){
    int cnt = 0;
    while(poly.coef[cnt] == 0){
        poly.degree--;
        cnt++;
    }
    for(int i = poly.degree; i > 0; i--){
        printf("%.1fx^%d + ", poly.coef[poly.degree - i + cnt], i);
    }
    printf("%.1f \n", poly.coef[poly.degree + cnt]);
    
    
}

int main()
{
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {5, {-3, 7, 0, 5, 0, 1}};
    polynomial c;
    
    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("-----------------------------------------------\n");
    print_poly(c);
    return 0;
}
