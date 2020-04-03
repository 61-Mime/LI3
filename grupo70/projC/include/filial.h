#ifndef __filial_h
#define __filial_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

typedef struct pordcli{
  char *prod;
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
  int compradores;
  THashFilial fil[3];
} GFiliais;

//Functions
GFiliais* initGFil();
void loadGFilFromCat(GFiliais* gfil, Catalogo* prod, Catalogo* cli);
void addGFilP(GFiliais* gfil, int hash, int pos, char* cli, int branch, char type);
void addGFilC(GFiliais* gfil, int hash, int pos, char* prod, int branch, int month, float price, int uni);
void freeGFil(GFiliais* fil);

//Getters
int getGFilPSizeP(GFiliais* gfil, int branch, int i, int j);
int getGFilPSizeN(GFiliais* gfil, int branch, int i, int j);
char* getGFilPCliP(GFiliais* gfil, int branch, int i, int j, int k);
char* getGFilPCliN(GFiliais* gfil, int branch, int i, int j, int k);
ListP* getGFilPList(GFiliais* gfil, int branch, int i, int j);
int getGFilPListSize(GFiliais* gfil, int branch, int i);
ListC* getGFilCList(GFiliais* gfil, int branch, int i, int j);
int getGFilCListSize(GFiliais* gfil, int branch, int i);
char* getGFilCprod(GFiliais*gfil,int branch,int i,int j,int k);
int getGFilCuni(GFiliais*gfil,int branch,int i,int j,int k,int m);
float getGFilCfat(GFiliais*gfil,int branch,int i,int j,int k);
int getGFilCsizeProds(GFiliais*gfil,int branch,int i,int j);
int getGFilComp(GFiliais*gfil);

#endif
