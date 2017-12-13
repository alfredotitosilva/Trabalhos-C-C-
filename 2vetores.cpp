/*ELE VAI INTERAR SOBRE O VETOR 1 COMPARANDO SE EXISTE O NUMERO NO VETOR 3
E DEPOIS INTERAR SOBRE O VETOR 2 COMPARANDO SE EXISTE O VALOR NO VETOR 3,
É NECESSARIO UM CONTADOR PARA DETERMINAR O NUMEROS DE POSIÇÕES NO VETOR 3
ELE INICIA COM ZERO E SEU VALOR FINAL DETERMINARA O NUMERO DE CASAS DO VETOR 3,ENTAO
ELE DE CONTAR TANTO NA INTERAÇÃO DO VETOR 1 QUANTO NA DO VETOR2*/

#include<iostream>

using namespace std;

int main (){

    int vet1[10]={1,0,1,4,5,6,7,8,1,9};
    int vet2[10]={10,11,2,4,15,16,17,18,19,20};
    int vet3[20];
    int i=0,j=0,k,cont2=0;

    for(i=0;i<10;i++){
        for(k=0;k<cont2;k++){
            //Testa para ver se no vetor 3 ja tem um valor do vetor 1
            if(vet3[k]==vet1[i])
                break;
        }
        //se nao tiver nenhum igual,ele coloca aquele valor do vetor 1 no 3.
        if(k==cont2){
            vet3[k]=vet1[i];
            cont2++;
        }
    }

    for(i=0;i<10;i++){
        for(k=0;k<cont2;k++){
            if(vet3[k]==vet2[i])
                break;
        }
        if(k==cont2){
            vet3[cont2]=vet2[i];
            cont2++;
        }
    }

    for(k=0;k<cont2;k++){
        cout << vet3[k] << " ";
    }
}
