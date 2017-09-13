#ifndef STACK_C_
#define STACK_C_

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

//FUNÇOES DE PILHA
stk *stkCreate(){
    stk *S;
    S = (stk*)malloc(sizeof(stk));
    if(S != NULL) {
        S->top = NULL;
        return S;
    }

    return NULL;
}

int stkPush(stk *S,void *data) {
    sllnode *newnode;
    if(S != NULL) {
        newnode = (sllnode*)malloc(sizeof(sllnode));
        if(newnode != NULL) {
            newnode->next = S->top;
            newnode->data = data;
            S->top = newnode;
            return true;
        }
    }
    return false;
}

void *stkPop(stk *S) {
    void *data; sllnode *aux;
    if(S != NULL){
        if(S->top != NULL) {
            aux = S->top;
            S->top = aux->next;
            data = aux->data;
            free(aux);
            return data;
        }
    }
    return NULL;
}

void *stkTop(stk* S){
    if(S != NULL) {
        if(S->top != NULL){
            return S->top->data;
        }
    }
    return NULL;
}

int stkDestroy(stk *S){
    if(S != NULL) {
        if(S->top != NULL) {
            free(S);
            return true;
        }
    }
    return false;
}

//FUNÇÕES DA RAINHA
void rainhas(stk *S, int **matriz, int n)// a pilha, a matriz, a dimensão, a coluna
{
int lin = 0, col = 0;
int preenchidas = 0;
int conf = 0;
int resultado = 0;
int i,k;
int backflag = 0;
    for(i=0;i<n;i++){
        preenchidas = stkTotal(S);
        for(k=0;k<n;k++){
            //se é valido
            if(teste(matriz,n,k,i)){
                matriz[k][i] = 1;//insere um numero na matriz
                stkPush(S,(void*)k);//coloca na pilha
                break;//vai para proxima coluna
            }else if(!(teste(matriz,n,k,i))){
                //se a pilha for igual a zero, sai do laço
                if(stkTotal(S) == 0){
                    break;
                    printf("fim");
                }
                if(k+1 == n)//se andou tudo e nao preencheu faz back
                {
                    //backtracking
                    k = stkPop(S);
                    i--;
                    matriz[k][i] = 0;
                    if(k+1==n){
                        //faz backtraking e move a rainha anterior a partir da sua posição anterior
                        k = stkPop(S);
                        i--;
                        matriz[k][i] = 0;
                    }
                }
            }
        }
    }
    imprimeMatriz(matriz,n);
}


int stkTotal(stk* S)
{
    if(S !=NULL){
        if(S->top!=NULL){
            int i = 1;
            sllnode *aux;
            aux = S->top->next;
            while(aux != NULL){
                aux = aux->next;
                i++;
            }

            return i;
        }
    }
    return 0;
}

int teste(int **matriz, int n, int lin, int col)
{
    int i, j;

    //testa a linha
    for(i = 0 ;i < n ; i++){
        if(matriz[lin][i] == 1)
            return false;
    }

    //teste a coluna
    for(i = 0 ;i < n ; i++){
        if(matriz[i][col] == 1)
            return false;
    }

    //testa a diagonal principal atras
    //acima
    for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(matriz[i][j] == 1)
            return false;
    }
    //abaixo
    for(i = lin, j = col; i < n && j < n; i++, j++)
    {
        if(matriz[i][j] == 1)
            return false;
    }

    //teste a diagona secundaria
    //acima
    for(i = lin, j = col; (i >= 0)  && (j < n); i--, j++)
    {
        if(matriz[i][j] == 1)
            return false;
    }
    //abaixo
    for(i = lin, j = col; (j >= 0)  && (i < n); i++, j--)
    {
        if(matriz[i][j] == 1)
            return false;
    }

    return true;
}

void imprimeMatriz(int **matriz,int n)
{
    int i,j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(matriz[i][j] == 1){
                printf("1  ");
            }
            if(matriz[i][j] == 0){
                printf("0  ");
            }
        }
        printf("\n");
    }
}
#endif // STACK_C_

