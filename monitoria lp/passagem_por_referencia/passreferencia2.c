#include <stdio.h>

void dobra(int *num)
{
    (*num) = (*num)*2;
}

int main()
{
    int num;

    printf("Insira um numero: ");
    scanf("%d", &num);

    dobra(&num);
    printf("O dobro dele eh: %d\n", num);

    return 0;
}