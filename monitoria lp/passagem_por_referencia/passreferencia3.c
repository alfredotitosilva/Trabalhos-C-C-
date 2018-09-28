#include<stdio.h>

void troca(int *x, int *y){
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int x, y;

    printf("Insira o numero x: ");
    scanf("%d", &x);

    printf("Insira o numero y: ");
    scanf("%d", &y);

    troca(&x, &y);

    printf("Agora x=%d e y=%d \n", x, y);

    return 0;
}