#define _MAIN_C
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

void main(void){
    int **matriz, n;
    int i,j;

    stk *pilha;
    pilha = stkCreate();

    printf("digite o n do tabuleiro");
    scanf("%d", & n);

    matriz = (int**)malloc(n*sizeof(int*));

    //forma a matriz
    for(i = 0; i < n; i++){
        matriz[i] = (int*)malloc(n*sizeof(int));
        for(j = 0; j < n; j++){
            matriz[i][j]=0;
        }
    }

    rainhas(pilha,matriz,n);

    //liberar memoria
    for(i = 0; i < n; i++){
      free(matriz[i]);
    }
    free(matriz);
    //destroi pilha
    stkDestroy(pilha);
}
