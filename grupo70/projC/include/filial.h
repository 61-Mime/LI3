#ifndef __filial_h
#define __filial_h

#include "sales.h"

typedef struct venda{
  char p[10];
  char type[2];
  char c[10];
  int month;
  int uni;
  float price;
  int branch;
} Venda;

typedef struct lista{
  char* key;
  int size3;
  Venda* venda;
} Lista;

typedef struct hsale{
  int size2;
  Lista* list;
} HSale;

typedef struct filial{
  HSale tblc[26];
  HSale tblp[26];
} TblFil;

TblFil* initFil();
void tblFil(THashSales *sales,TblFil *fil,int branch);
void printFil(TblFil* fil);
void freeFil(TblFil* fil);

#endif
