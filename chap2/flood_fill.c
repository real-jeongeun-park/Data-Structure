#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 0, 0, 0, 0, 2, 2, 2}, {2, 2, 2, 2, 0, 0, 0, 2, 2, 2}, {2, 2, 2, 2, 0, 0, 0, 2, 2, 2}, 
    {2, 2, 2, 2, 0, 0, 0, 0, 2, 2}, {2, 2, 2, 2, 0, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 0, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};

int read_pixel(int x, int y){
    return screen[x][y];
}

void write_pixel(int x, int y, int color){
    screen[x][y] = color;
}

void flood_fill(int x, int y, int color){
    if(read_pixel(x, y) == WHITE){
        write_pixel(x, y, color);
        flood_fill(x-1, y, BLACK);
        flood_fill(x+1, y, BLACK);
        flood_fill(x, y-1, BLACK);
        flood_fill(x, y+1, BLACK);
    }
}

int main()
{
    printf("실행 전\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", read_pixel(i,j));
        }
        printf("\n");
    }
    
    flood_fill(5,4,BLACK);
    printf("\n실행 후\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", read_pixel(i,j));
        }
        printf("\n");
    }
}
