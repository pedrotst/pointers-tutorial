#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void f(int *y) {
  printf("\n=== f was called ===\n");
  printf("y addr: %p\n", &y);
  printf("y points to: %p\n", (void *) y);
  printf("y points to value: %d\n", *y);
  *y = *y+1;
}

int main(){
    int x;
    x = 5;
    printf("x: %d\n", x);
    printf("x addr: %p\n", (void *) &x);
    f(&x);
    printf("x: %d\n", x);
    printf("x addr: %p\n", (void *) &x);

    return 0;
}


