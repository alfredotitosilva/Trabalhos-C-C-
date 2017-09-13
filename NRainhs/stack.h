#ifndef STACK_H_
#define STACK_H_

typedef struct _sllnode_ {
    void *data;
    struct _sllnode_ *next;
}sllnode;

typedef struct _stack_ {
    sllnode *top;
}stk;

    #ifdef STACK_C_
        stk *stkCreate();
        int stkPush(stk *S,void *data);
        int stkDestroy(stk *S);
        void *stkTop(stk* S);
        void *stkPop(stk *S);
        int stkPush(stk *S,void *data);
        void rainhas(stk *S, int **matriz, int n);
        int teste(int **matriz, int n, int lin, int col);
        void imprimeMatriz(int **matriz,int n);
        int stkTotal(stk* S);
    #else
        extern stk *stkCreate();
        extern int stkPush(stk *S,void *data);
        extern int stkDestroy(stk *S);
        extern void *stkTop(stk* S);
        extern void *stkPop(stk *S);
        int stkPush(stk *S,void *data);
        extern void rainhas(stk *S, int **matriz, int n);
        extern int teste(int **matriz, int n, int lin, int col);
        extern void imprimeMatriz(int **matriz,int n);
        extern int stkTotal(stk* S);
    #endif
#endif // STACK_H


