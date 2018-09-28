#include <stdio.h>

/*
Escreva uma função mm que receba um vetor inteiro v[5] e os
endereçosde duas variáveis inteiras, digamos min e max, e deposite nessas
variáveis ovalor de um elemento mínimo e o valor de um elemento máximo do
vetor.Escreva também uma função main que use a função mm.
*/

void minmax(int vet[], int* min, int* max){

  for(int i = 0; i < 5; i++){
    if(vet[i] < *min)
      *min = vet[i];
    if(vet[i] > *max)
      *max = vet[i];
  }
} 

int main() {
  
  int vet[5] = {2,3,10,2,1};
  int menor = vet[0];
  int maior = vet[0];

  minmax(vet, &menor, &maior);

  printf("o valor minimo: %d \n", menor);
  printf("o valor maior: %d", maior);

  return 0;
}