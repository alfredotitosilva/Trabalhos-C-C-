#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include"options.h"
using namespace std;

int main(){
    lista *agenda=NULL;//isso aqui é a lista
    contato *dado;
    int op;

    ifstream entrada;
    char buffer[1000],nome[1000], email[1000];
    entrada.open("contatos.txt");

    do{
        system("cls");
        cout<<"1-Cadastrar novos contatos numa lista"<<endl;
        cout<<"2-imprimir contatos"<<endl;
        cout<<"3-salvar contatos"<<endl;
        cout<<"4-carregar contatos"<<endl;
        cout<<"5-Buscar contato"<<endl;
        cout<<"0-sair"<<endl;
        cin>>op;
        switch(op){
        case 1:
            system("cls");
            dado=preencherContato();
            criarContato(&agenda,dado);
            break;
        case 2:
            system("cls");
            imprimirLista(agenda);
            system("pause");
            break;
        case 3:
            salvarContatos(agenda);
            system("pause");
            break;
        case 4:
            while(!entrada.eof()){
               entrada.getline(nome,1000);

               entrada.getline(email,1000);

               dado=preencherContato2(nome,email);
               criarContato(&agenda,dado);
            }
            cout<<"agenda carregada."<<endl;

            entrada.close();
            system("pause");
            break;
        case 5:
            system("cls");
            buscarContato(agenda);
            system("pause");
            break;
        }

    }while(op!=0);

}
