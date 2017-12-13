/*busca todas as ocorrências,
 sendo que a medida que vai encontrando uma ocorrência,
  continua buscando no restante do vetor por algo a mais.*/
#include<iostream>

using namespace std;

int teste(int *vet,int n,int num,int i);

int main(){
    int num,*vet,n,i,res;

    //alocando
    cout <<"digite o tamanho do vetor"<<"\n";
    cin>> n;

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

    i=0;
    while(i<n){
        i= teste(vet,n,num,i);
        if(i<n){
            cout << i <<" ";
            i++;
        }

    }

    delete[]vet;
}


int teste(int *vet,int n,int num,int i){

    int pos;

    while(i<n && vet[i]!=num){
        i++;

    }
        return i;
}

