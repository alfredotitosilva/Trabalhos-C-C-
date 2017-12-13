/*1) busca somente pela primeira ocorrência e informa onde aconteceu*/
#include<iostream>

using namespace std;

int teste(int *vet,int n,int num);

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

    res= teste(vet,n,num);

    if(res==-99){
        cout<<"nao faz parte do vetor";
    }else{
        cout<<"na pos: "<<res;
    }

    delete[]vet;
}


int teste(int *vet,int n,int num){
    int i=0;

    while(i<n && vet[i]!=num){
        i++;

    }
    return i;
}
