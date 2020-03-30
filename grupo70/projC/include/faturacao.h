#ifndef __faturacao_h
#define __faturacao_h

#include "sales.h"

typedef struct factM {
  int vendasN;
  int vendasP;
  float facturacaoN;
  float facturacaoP;
} FMensal;

typedef struct fact {
  char *prod;
  FMensal mesfilial[12][3];
} Facturacao;

typedef struct Tfact {
  int size;
  Facturacao *list;
} TFacturacao;

typedef struct thashfact {
  TFacturacao tbl[26];
} THashFact;

THashFact* initFact();
void tblFact(THashSales *sales,THashFact *fact);
void printFact(THashFact* fact);
void freeFact(THashFact* fact);

#endif
