#ifndef OPTIONS_H

#define OPTIONS_H
typedef struct _contato_{
    char *nome;
    char *email;
}contato;


typedef struct _lista_{
    contato *dado;
    struct _lista_ *prox;
}lista;

contato *preencherContato();
contato *preencherContato2(char nome[],char email[]);

lista  *preencherLista(contato *dado);

void criarContato(lista **agenda, contato *dado);

void imprimirLista(lista *agenda);

void salvarContatos(lista *agenda);

void buscarContato(lista *agenda);

void carregarArquivo(lista **agenda);
#endif
