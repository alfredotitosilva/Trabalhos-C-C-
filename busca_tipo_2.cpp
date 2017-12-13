/*2) busca todas as ocorrências e grava num vetor máscara a localização de todas essas ocorrências*/
#include<iostream>

using namespace std;

int* teste(int *vet,int n,int num);

int main(){
    int num,*vet,n,i;

    //alocando
    cout <<"digite o tamanho do vetor"<<"\n";
    cin>> n;

    int *res;

    vet= new int[n];

    if(vet==NULL){
        return 0;
    }

    cout<<"\n";

    for(i=0;i<n;i++){
        cout << "digite um valor"<<"\n";
        cin >> vet[i];
    }

    cout <<"\n"<<"digite um numero"<<"\n";
    cin>> num;

    res=teste(vet,n,num);
    for(i=0;i<n;i++){
        if(res[i]!=0){
            cout << i << " ";
        }
    }

    delete[]vet;
    delete[]res;
}


int* teste(int *vet,int n,int num){
    int i=0;
    int *aux;

    //vetor mascara
    aux=new int[n];
    //0 para falso, 1 para verdadeiro
    for(i=0;i<n;i++){
        aux[i]=0;
    }

    for(i=0;i<n;i++){
        if(vet[i]==num){
            aux[i]=1;
        }
    }

    return aux;

}

