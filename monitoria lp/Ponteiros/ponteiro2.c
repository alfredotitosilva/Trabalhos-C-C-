#include <stdio.h>

int main(){

    int a[5] = {11,22,33,44,55};
    int* ptr = a;
    
    for(int i = 0; i < 5; i++)
    {
        printf("antes de operar os ponteiro: %i \n", *ptr);
        ptr++;
    }
    
}