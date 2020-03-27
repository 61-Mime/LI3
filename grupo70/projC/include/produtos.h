#ifndef __produtos_h
#define __produtos_h

#include "sort.h"

//STRUCTS PRODUTOS
typedef struct prod {
  int size;
  char** list;
} Prod;

typedef struct thashprod {
  int sizet;
  Prod tbl[26];
} THashP;

THashP* initProd();
int searchProd(char* prod, THashP* tprod);
int hashP(char c);
int tblProd(THashP* tprod);
void printProd(THashP* prod);
void freeProd(THashP* prod);

#endif
