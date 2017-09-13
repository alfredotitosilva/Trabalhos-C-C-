#ifndef _HASH_H_
#define _HASH_H_
#include <stdlib.h>
#include <string.h>
#include "structs.h"
typedef struct _hash_{
   int qtd, TABLE_SIZE;
   Data **itens;
} Hash;

Hash* createHash(int TABLE_SIZE);
void freeHash(Hash* ha);
int buscaHash_EnderAberto(Hash* ha, int key, Data** dado,int* passos);
int insereHash_EnderAberto(Hash* ha, Data* dado);

#endif
