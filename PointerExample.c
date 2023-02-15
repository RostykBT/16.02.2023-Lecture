//Example oƒusing pointers in different functions 
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 5, y = 10;
    printf("x is %d and y is %d before swap function call\n", x, y);
    swap(&x, &y);
    printf("x is %d and y is %d after swap function call\n", x, y);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
