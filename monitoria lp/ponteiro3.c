#include <stdio.h>

int main()
{

    int pa[10], razao;
    int *ptr;

    printf("Insira o termo inicial da PA: ");
    scanf("%d", &pa[0]);
    ptr = pa;

    printf("Insira razao da PA:");
    scanf("%d", &razao);

    while( ptr != &pa[9])
    {
        *(ptr+1) = *ptr + razao;
        ptr++;
    }

    for(ptr = pa; ptr <= &pa[9]; ptr++)
        printf("-> %d", *ptr);

    return 0;
}