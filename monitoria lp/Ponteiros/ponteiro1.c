#include <stdio.h>

int main(){

    int a = 22;
    int* ptr = &a;
    printf("\n Usando ponteiros \n");
    printf("valor de a: %d \n", a);
    printf("valor do endereço de a: %x \n", &a);
    printf("valor do ponteiro ptr: %x \n", ptr);
    printf("valor que ptr aponta: %d \n", *ptr);

    int** ptrptr = &ptr;
    printf("endereço do ponteiro ptr: %x \n", &ptr);
    printf("valor de um ponteiro que aponta pra ponteiro: %x \n", ptrptr);

    return 0;
}