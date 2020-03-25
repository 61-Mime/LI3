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
  Prod tbl[676];
} THashP;

int searchProd(char* prod, THashP* tprod);
int hashP(char c,char c2);
int tblProd(THashP* tprod);
void printProd(THashP* prod);
void freeProd(THashP* prod);

#endif
