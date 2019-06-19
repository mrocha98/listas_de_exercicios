#include <stdio.h>

int main(){
    int *p, x=5;
    p = &x;
    *p *= 2 * *p;
    printf("%d\n", x);
    system("pause");
    return 0;
}