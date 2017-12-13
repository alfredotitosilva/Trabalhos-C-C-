#include<iostream>
#include<stdlib.h>
using namespace std;

void aposta(int **vet,int n){
    int i;

    for(i=0;i<n;i++){
        (*vet)[i]=1+rand()%60;
    }

}


int main(){

int *vet,n,i;

n=5+rand()%20;

vet=new int[n];

aposta(&vet,n);


for(i=0;i<n;i++){
    cout << vet[i] <<" ";
}

delete[]vet;
}
