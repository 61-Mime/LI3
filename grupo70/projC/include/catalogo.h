#ifndef __clientes_h
#define __clientes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

//STRUCTS CLIENTES
typedef struct cat {
  int size;
  char** list;
} Cat;

typedef struct catalogo {
  int nValidas;
  int nLidas;
  Cat tbl[26];
} Catalogo;

Catalogo* initCat();
int searchCat(char* key, Catalogo* cat);
int hashCat(char c);
int tblCat(Catalogo* tcli, char* filePath, char type);
void freeCat(Catalogo* cli);
int getCatLinhaVal(Catalogo* cat);
int getCatLinhaLida(Catalogo* cat);
int getCatListSize(Catalogo* cat, int i);
char* getCatKey(Catalogo* cat, int i, int j);

#endif