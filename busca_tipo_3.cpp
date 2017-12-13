/*3) busca todas as ocorrências e gera um vetor
dinâmicamente alocado com os valores das localizações de onde foi encontrado o valor*/
#include<iostream>

using namespace std;


int* teste(int *vet,int n,int num);

int cont=0;

int main(){
    int num,*vet,*vet2,n,i,res;

    //alocando
    cout <<"digite o tamanho do vetor"<<"\n";
    cin>> n;
    cout <<"\n";
    vet= new int[n];

    if(vet==NULL){
        return 0;
    }

    for(i=0;i<n;i++){
        cout << "digite um valor"<<"\n";
        cin >> vet[i];
    }

    cout <<"\n"<<"digite um numero"<<"\n";
    cin>> num;

    vet2= teste(vet,n,num);

    for(i=0;i<cont;i++){
        cout << vet2[i] << " ";
    }

    delete[]vet;
  }


int* teste(int *vet,int n,int num){
    int i,k=0;
    int *aux;

    for(i=0;i<n;i++){
        if(vet[i]==num)
            cont++;
    }

    aux=new int[cont];

    for(i=0;i<n;i++){
        if(vet[i]==num){
            aux[k]=i;
            k++;
        }
    }

    return aux;
    delete[]aux;
}
