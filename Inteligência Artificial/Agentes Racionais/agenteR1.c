/******************************************************************************

O objetivo do agente A é capturar todos os * da tela no menor tempo possivel.
1 - Escreva a função do agente seguindo o modelo reativo simples.
2 - Escreva a função do agente seguindo o modelo reativo baseado em objetivos.
3 - Escreva a função do agente seguindo o modelo reativo baseado em utilidade.

Depois compare o tempo que cada abordagem demorou para atingir o objetivo.

O agente capta com seus sensores o conteudo das 4 casas ao seu redor (esquerda, direita, cima, baixo)
O agente tem como acoes movimentar-se para esquerda (0), direita (1), cima (2), baixo (3)

Obs.: A função de agente implementada como exemplo representa um agente aleatório, 
qualquer abordagem que você desenvolver, deve ser no mínimo melhor que o aleatório.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 52

int posAgenteX = 1;
int posAgenteY = 1;

int ambiente[SIZE][SIZE];

void delay(int tempo){
	for(int i=0; i<tempo; i++);
}

void construirAmbiente(){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
			if(i == 0 || i == SIZE-1){
				if(j == 0 || j == SIZE-1) ambiente[i][j] = 2;
				else ambiente[i][j] = 3;
			}
			else if(j == 0 || j == SIZE-1) ambiente[i][j] = 4;
			else ambiente[i][j] = rand()%2;
		}
	}
}

void atualizarAmbiente(int acao){
    ambiente[posAgenteX][posAgenteY] = 0;
    if (acao == 0 && ambiente[posAgenteX][posAgenteY-1] < 2) posAgenteY -= 1;
    else if (acao == 1 && ambiente[posAgenteX][posAgenteY+1] < 2) posAgenteY += 1;
    else if (acao == 2 && ambiente[posAgenteX-1][posAgenteY] < 2) posAgenteX -= 1;
    else if (acao == 3 && ambiente[posAgenteX+1][posAgenteY] < 2) posAgenteX += 1;
    ambiente[posAgenteX][posAgenteY] = 5;
}    

void mostrarAmbiente(){
	system("cls");
	int count = 0;
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            // 0 é espaço vazio
            if (ambiente[i][j] == 0) printf(" ");
            // 1 é item
            else if (ambiente[i][j] == 1) { count++; printf("*");}
            //diagonal
            else if (ambiente[i][j] == 2) printf("+");
            //topo ou baixo
            else if (ambiente[i][j] == 3) printf("-");
            //parede esquerda ou direita
            else if (ambiente[i][j] == 4) printf("|");
            //agente
            else if (ambiente[i][j] == 5) printf("A");
        }
        printf("\n");
    }
	printf("Faltam %d objetos.\n", count);
}

bool verificarSucesso(){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if (ambiente[i][j] == 1) return false;
        }
    }
    return true;
}

int lerSensor(int lado){
    if (lado == 0) return ambiente[posAgenteX][posAgenteY-1];
    if (lado == 1) return ambiente[posAgenteX][posAgenteY+1];
    if (lado == 2) return ambiente[posAgenteX-1][posAgenteY];
    if (lado == 3) return ambiente[posAgenteX+1][posAgenteY];
    return 2;
}
//AGENTE ALEATORIO
int funcaoAgente(int esquerda, int direita, int cima, int baixo){
    delay(10000); //como o ambiente é muito pequeno, esse delay serve para que o tempo seja mensurável
	//aleatorio
	return rand()%4;
}
//AGENTE REATIVO SIMPLES 
int funcaoAgenteRS(int esquerda, int direita, int cima, int baixo){
    delay(10000);

    //se parede topo e esquerda vá para direita
    if(cima == 3 && esquerda == 4)
        return 1;//direita
    //se parede esquerda e linha par, desce
    if(esquerda == 4 && posAgenteX%2==0)
        return 3;//desce
    //se parede direita e linha impar, desce
    if(direita == 4 && posAgenteX%2!=0)
        return 3;//desce
    //ele vai para  direita nas linhas pares
    if(posAgenteX%2!=0)
        return 1;//direita
    //ele vai para  direita nas linhas impares        
    if(posAgenteX%2!=1)
        return 0;//esquerda    
}
//AGENTE REATIVO BASEADO EM OBJETIVO
typedef struct
{
    /* data */
    int x;
    int y;
}LocItem;
LocItem itens[1500];
int countItem = 0;
int inicioFila = 0;

void vendoAmbiente(){
    int direita = 1;
    for(int i = 1; i < SIZE; i = i +2)
    {
        if(direita){
            for(int j = 1; j < SIZE; j++)
            {
                /* code */
                if(ambiente[i][j] == 1){
                    itens[countItem].x = i;
                    itens[countItem].y = j;
                    countItem++;
                }
                //da fileira de baixo
                if(ambiente[i+1][j] == 1){
                    itens[countItem].x = i+1;
                    itens[countItem].y = j;
                    countItem++;
                }
            }
            direita = 0;
        }else{
            for(int j = SIZE; j > 0; j--)
            {
                /* code */
                if(ambiente[i][j] == 1){
                    itens[countItem].x = i;
                    itens[countItem].y = j;
                    countItem++;
                }
                //da fileira de baixo
                if(ambiente[i+1][j] == 1){
                    itens[countItem].x = i+1;
                    itens[countItem].y = j;
                    countItem++;
                }
            }
            direita = 1;
        } 
    }
}

int funcaoAgenteOO(int acao,int esquerda, int direita, int cima, int baixo){
    delay(10000); //como o ambiente é muito pequeno, esse delay serve para que o tempo seja mensurável
       
    if(posAgenteX == itens[inicioFila].x && posAgenteY == itens[inicioFila].y){
        inicioFila++;
    }
    //
    if(posAgenteY < itens[inicioFila].y)
        return 1;//direita
    //
    if(posAgenteY > itens[inicioFila].y)
        return 0;//esq
    //
    if(posAgenteX < itens[inicioFila].x)
        return 3;//baixo
    //
    if(posAgenteX > itens[inicioFila].x)
        return 2;//cima   
}
//baseado em utilidade
int funcaoAgenteUU(int acao,int esquerda, int direita, int cima, int baixo){
    delay(10000); //como o ambiente é muito pequeno, esse delay serve para que o tempo seja mensurável
       
    if(posAgenteX == itens[inicioFila].x && posAgenteY == itens[inicioFila].y){
        inicioFila++;
    }
    //
    if(esquerda == 1)
        return 0;
    if(direita == 1)
        return 1;
    if(cima == 1)
        return 2;
    if(baixo == 1)
        return 3;
    //
    if(posAgenteY < itens[inicioFila].y)
        return 1;//direita
    //
    if(posAgenteY > itens[inicioFila].y)
        return 0;//esq
    //
    if(posAgenteX < itens[inicioFila].x)
        return 3;//baixo
    //
    if(posAgenteX > itens[inicioFila].x)
        return 2;//cima   
}
//main
int main()
{
    clock_t tempo[2];
	construirAmbiente();
	mostrarAmbiente();
    tempo[0] = clock();
    vendoAmbiente();
    //printf("total de itens %d",countItem);
    int acao;
	while(!verificarSucesso()){
        //acao = funcaoAgente(lerSensor(0), lerSensor(1), lerSensor(2), lerSensor(3));
        //acao = funcaoAgenteRS(lerSensor(0), lerSensor(1), lerSensor(2), lerSensor(3));
        //acao = funcaoAgenteOO(acao, lerSensor(0), lerSensor(1), lerSensor(2), lerSensor(3));
        acao = funcaoAgenteUU(acao, lerSensor(0), lerSensor(1), lerSensor(2), lerSensor(3));
        atualizarAmbiente(acao);
        //mostrarAmbiente(); //mostra o que esta acontecendo, mas atrasa a execução
        delay(10000);
    }
    mostrarAmbiente();
	tempo[1] = clock();
	printf("Tempo gasto: %g ms.", ((tempo[1] - tempo[0]) / ((double)CLOCKS_PER_SEC)));
    return 0;
}