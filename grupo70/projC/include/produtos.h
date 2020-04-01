#ifndef __produtos_h
#define __produtos_h

#include "sort.h"

//STRUCTS PRODUTOS
typedef struct prod {
  int size;
  char** list;
} Prod;

typedef struct thashprod {
  int nValidas;
  int nLidas;
  Prod tbl[26];
} THashP;

THashP* initProd();
int searchProd(char* prod, THashP* tprod);
int hashP(char c);
int tblProd(THashP* tprod, char* filePath);
void freeProd(THashP* prod);

#endif
