#ifndef __filial_h
#define __filial_h

#include "sales.h"

typedef struct pordcli{
  char prod[10];
  int uni[12];
  float fat;
} ProdCli;

typedef struct listc{
  char* key;
  int sizeProds;
  ProdCli* prods;
} ListC;

typedef struct tfilc{
  int sizeCli;
  ListC* list;
} TFilialC;

typedef struct listp{
  char* key;
  int sizeN;
  int sizeP;
  char** cliN;
  char** cliP;
} ListP;

typedef struct tfilp{
  int sizeProd;
  ListP* list;
} TFilialP;

typedef struct filial{
  TFilialC tblc[26];
  TFilialP tblp[26];
} THashFilial;

typedef struct gfiliais{
  THashFilial fil1;
  THashFilial fil2;
  THashFilial fil3;
} GFiliais;
 
GFiliais* initGFil();
void tblGFil(GFiliais *fil, THashSales *sales);
void freeGFil(GFiliais* fil);

#endif
