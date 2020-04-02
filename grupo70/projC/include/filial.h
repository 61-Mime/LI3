#ifndef __filial_h
#define __filial_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

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
  THashFilial fil[3];
} GFiliais;
 
GFiliais* initGFil();
void loadGFilFromProds(GFiliais* gfil, Catalogo* prod, Catalogo* cli);
void addGFil(GFiliais* gfil, int posp, int posc, int branch, char* prod, char* cli, float price, int uni, char type, int month);
void freeGFil(GFiliais* fil);

#endif
