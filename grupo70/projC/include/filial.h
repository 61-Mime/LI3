#ifndef __filial_h
#define __filial_h

#include "sales.h"

typedef struct venda{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
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
  int size1;
  HSale tbl[26];
} Filial;

typedef struct filiais{
  Filial f1;
  Filial f2;
  Filial f3;
} Filiais;

Filiais* initFil();
void freeFil(Filiais* fil);

#endif
