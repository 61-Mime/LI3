#include "sort.h"

#ifndef __produtos_h
#define __produtos_h
typedef struct prod {
  int size;
  char** list;
} Prod;

typedef struct thashprod {
  int sizet;
  Prod tbl[676];
} THashP;
#endif

int hashP(char c,char c2);
void tblProd(THashP* tprod);
