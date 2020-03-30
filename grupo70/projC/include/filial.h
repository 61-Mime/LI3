#ifndef __filial_h
#define __filial_h

#include "sales.h"

typedef struct venda{
  char* p;
  char* type;
  char* c;
  int month;
} Venda;

typedef struct lista{
  char* key;
  int used; // 0-notused 1-used
  int size3;
  Venda* venda;
} Lista;

typedef struct hsale{
  int size2;
  Lista* list;
} HSale;

typedef struct filial{
  int size1;
  HSale tblc[26];
  HSale tblp[26];
} TblFil;

TblFil* initFil();
void freeFil(TblFil* fil);

#endif
