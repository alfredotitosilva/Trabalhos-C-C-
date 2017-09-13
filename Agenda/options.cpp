#include"options.h"
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

contato *preencherContato(){
    contato *novoContato;

    novoContato=new contato[1];
    char buffer[1000];

    cout<<"digite o nome do contato"<<endl;
    cin.ignore(1);
    cin.getline(buffer,1000);
    novoContato->nome=new char[strlen(buffer)];
    strcpy(novoContato->nome,buffer);

    cout<<"digite o email do contato"<<endl;

    cin.getline(buffer,1000);
    novoContato->email=new char[strlen(buffer)];
    strcpy(novoContato->email,buffer);

    return novoContato;
}

contato *preencherContato2(char nome[],char email[]){
    contato *novoContato;
    novoContato=new contato[1];
    novoContato->nome=new char[strlen(nome)];
    strcpy(novoContato->nome,nome);

    novoContato->email=new char[strlen(email)];
    strcpy(novoContato->email,email);

    return novoContato;
}

lista  *preencherLista(contato *dado){
    lista *novo;

    novo=new lista[1];

    novo->dado=dado;
    novo->prox=NULL;

    return novo;

}

void criarContato(lista **agenda, contato *dado){

    lista *novo = preencherLista(dado);
    lista *tmp = *agenda;

    //existe cabeça?
    if(*agenda==NULL){
        *agenda=novo;
    }else{

        while(tmp->prox!=NULL){
            tmp = tmp->prox;
        }

        tmp->prox=novo;
    }

}


void imprimirLista(lista *agenda){
    lista *tmp=agenda;


    while(tmp!=NULL){
        cout<<"nome: "<<tmp->dado->nome<<endl;
        cout<<"email:"<<tmp->dado->email<<endl;
        tmp=tmp->prox;
    }

}


void salvarContatos(lista *agenda){
    lista *tmp=agenda;
    char buffer[1000];

    ofstream saida;
    saida.open("contatos.txt");

    if(!saida.is_open())
        cout<<"arquivo nao aberto";

    while(tmp!=NULL){
        strcpy(buffer,tmp->dado->nome);
        saida<<buffer<<"\n";
        strcpy(buffer,tmp->dado->email);
        saida<<buffer<<"\n";

        tmp=tmp->prox;
    }

    cout<<"contatos foram salvos em um arquivo"<<endl;
    saida.close();
}



void buscarContato(lista *agenda){
    char tipobusca[100];
    char buffer[1000];

    lista *tmp=agenda;

    cout<<"deseja busca por nome ou email"<<endl;
    cin.ignore(1);
    cin.getline(tipobusca,100);

    cout<<"digite o nome do contato que busca"<<endl;
    cin.getline(buffer,1000);

    if(strcmp(tipobusca,"nome")==0){
        while(tmp!=NULL){
        if(strstr(agenda->dado->nome,buffer)){
            cout<<"nome: "<<agenda->dado->nome<<endl;
            cout<<"email: "<<agenda->dado->email<<endl;
        }
            tmp=tmp->prox;
        }
    }else{
        while(tmp!=NULL){
            if(strstr(agenda->dado->email,buffer)){
                cout<<"nome: "<<agenda->dado->nome<<endl;
                cout<<"email: "<<agenda->dado->email<<endl;
            }
                tmp=tmp->prox;
        }

    }

}
