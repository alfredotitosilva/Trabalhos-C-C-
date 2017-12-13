#include<iostream>


using namespace std;

int inter(int *vetA,int *vetB,int tamA,int tamB,int vetI[]);


int main(){
 //primeiro declarar variaveis
 int *vetA,*vetB;
 int sel,tamA,tamB;
 int i;
 int *vetU,*vetD;
 int contU,contI,contD;
 //preencher os conjuntos
 cout<<"digite o tamanho do conjunto A"<<"\n";
 cin >> tamA;
 cout<<"digite o tamanho do conjunto B"<<"\n";
 cin >>tamB;

 int vetI[tamA+tamB];

 cout<<"\n";
 //alocando dinamicamente
 vetA=new int[tamA];
 vetB=new int[tamB];


 //preenchendo os vetores
 for(i=0;i<tamA;i++){
    cout<<"digite um valor para o conjunto A"<<"\n";
    cin>>vetA[i];
 }

 cout<<"\n";

 for(i=0;i<tamB;i++){
    cout<<"digite um valor para o conjunto B"<<"\n";
    cin>>vetB[i];
 }
//chamar funções
//interssecção
 contI=inter(vetA,vetB,tamA,tamB,vetI);

for(i=0;i<contI;i++){
        cout << vetI[i]<<" ";

}

cout <<"\n";
//união

    delete[]vetA;
    delete[]vetB;

}

int inter(int *vetA,int *vetB,int tamA,int tamB,int vetI[]){

    int cont=0,i,j;

    for(i=0;i<(tamA+tamB);i++)
        vetI[i]=-1;

    //testando o tamanho do inter
    if(tamA>tamB){
        for(i=0;i<tamA;i++){
            for(j=0;j<tamB;j++){
                if(vetA[i]==vetB[j]){
                    vetI[i]=vetA[i];
                    break;
                }
            }
        }
    }else{
        for(i=0;i<tamB;i++){
            for(j=0;j<tamA;j++){
                if(vetA[i]==vetB[j]){
                    vetI[i]=vetB[i];
                    break;
                }
            }
        }

    }

        return cont;
}

