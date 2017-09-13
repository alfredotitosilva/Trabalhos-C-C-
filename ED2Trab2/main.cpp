#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"structs.h"
#include"AVL.h"
#include"Hash.h"
#include"RedBlack.h"
using namespace std;

vector<string> vector_of_words(string frase);
void ocurrences(Data* data, vector<string> doc);

int main(){
    AVLnode* AVLroot = NULL;
    Hash* ha = createHash(1427);
    RBnode* RBroot= NULL;

    ifstream entrada;
    entrada.open("maior.txt");
    int i = 0;
    char *teste;
    int line = 1;
    vector<string> documento;//contém todas as linhas
    vector<int> chaves;
    //criar vector com todas as linhas
    while(!entrada.eof()){
        char buffer[1000];
        entrada.getline(buffer,1000);
        string str = buffer;
        documento.push_back(str);
    }
    //começar adicionar elementos
    for(int i = 0; i < documento.size(); i++){
        /*gerar palavras*/
        vector<string> palavras = vector_of_words(documento[i]);
        for(int j = 0; j < palavras.size(); j++){
            //busca se elemento ja existe
            //verifica o tamanho
            if(palavras[j].size() > 2){
                Data* dado = new Data[1];
                if(dado != NULL){
                    dado->key = valorString(palavras[j]);
                    dado->palavra = palavras[j];
                    ocurrences(dado, documento);
                    /*Inserções*/
                    /*Hash*/
                    insereHash_EnderAberto(ha,dado);
                    /*AVL*/
                    AVLroot = insert_AVLnode(AVLroot, dado);
                    /*Red and Black*/
                    RB_Insert(&RBroot, dado);
                }
            }
        }
    }
    entrada.close();
    /*Buscas nas estruturas*/
    //Váriaveis
    Data *dado = NULL;
    int passos = 0;
    char buffer[1000];
    string busca;
    //BUSCA NA AVL
    cout << "digite a palavra que quer buscar" << endl;
    cin.getline(buffer,1000);
    busca = buffer;
    //Busca elemento na AVL
    Query(AVLroot, &dado, busca, &passos);
    cout<<"tempo gasto na busca AVL: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl;
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl;
    }
    /*BUSCA NO HASH*/
    dado = NULL;
    passos = 0;
    cout << "digite a palavra que quer buscar" << endl;
    cin.getline(buffer,1000);
    busca = buffer;
    buscaHash_EnderAberto(ha, valorString(busca), &dado, &passos);
    cout<<"tempo gasto na busca Hash: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl;
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl;
    }else{
        cout<<"voltei null"<<endl;
    }
    dado = NULL;
    passos = 0;
    /*Busca na RB*/
    cout << "digite a palavra que quer buscar" << endl;
    cin.getline(buffer,1000);
    busca = buffer;
    RBQuery(RBroot, &dado, busca, &passos);
    cout<<"tempo gasto na busca REDBLACK: "<<passos<<" passos"<<endl;
    if(dado != NULL){
        cout << "palavra: "<<dado->palavra << endl;
        for(int j = 0; j < dado->linhas.size(); j++)
            cout << "linha " << dado->ocorrencias[j] << ": " << dado->linhas[j] << endl;
    }else{
        cout<<"não foi encontrado";
    }

    freeHash(ha);
    Destroy(AVLroot);
    //RBDestroy(RBroot);
    return 0;
}

//Pega palavras da frase
vector<string> vector_of_words(string frase){
    vector<string> vet;
    string del = " ";//delimitador
    size_t pos = 0;
    string word;
    while((pos = frase.find(del)) != string::npos){
        word = frase.substr(0, pos);
        vet.push_back(word);
        frase.erase(0, pos + del.length());
    }
    //Para pegar a última palavra da frase
    word = frase.substr(0, pos);
    vet.push_back(word);

    return vet;
}

/*Função que verifica as ocorrências no texto
  e preencher o struct data*/
void ocurrences(Data* data, vector<string> doc){
    //ver onde ocorre a palavra
    int line = 1;
    for(int i = 0; i < doc.size(); i++){
        if(doc[i].find(data->palavra) != string::npos){
            data->linhas.push_back(doc[i]);
            data->ocorrencias.push_back(line);
        }
        line++;
    }
}
