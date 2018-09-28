#include <stdio.h>

void passagemPorCopia(int i){
    printf("\n --dentro da function--\n");
    printf("valor antes de ser alterado: %d \n", i);

    i = i -2;

    printf("valor depois de ser alterado: %d \n", i);
}

void passagemPorReferencia(int* ptr){
    printf("\n --dentro da function--\n");
    printf("valor antes de ser alterado: %d \n", *ptr);

    *ptr = *ptr -2;

    printf("valor depois de ser alterado: %d \n", *ptr);
}

int main(){

    int i = 22;
    //Existem dois métodos de passagem de parâmetros para funções:
    //Passagem por valor – permite usar dentro de uma função uma cópia do valor de uma variável, 
    //porém não permite alterar o valor da variável original (somente a cópia pode ser alterada).
    printf("\n ----passando por copia---- \n");
    passagemPorCopia(i);

    printf("valor de ptr na main: %d \n", i);
    //Passagem por referência – É passada para a função uma referência da variável,
    //sendo possível alterar o conteúdo da variável original usando-se esta referência.
    printf("\n ----passando por referencia---- \n");
    passagemPorReferencia(&i);
    printf("valor de ptr na main: %d \n", i);

    return 0;
}