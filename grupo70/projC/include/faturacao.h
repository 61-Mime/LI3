#ifndef __faturacao_h
#define __faturacao_h

#include "sales.h"

typedef struct fact {
  char *prod;
  int numeroN;
  int numeroP;
  int facturacaoN;
  int facturacaoP;
} Facturacao;

typedef struct Tfact {
  int size2;
  Facturacao *list;
} TFacturacao;

typedef struct thashfact {
  int size1;
  TFacturacao tbl[26];
} THashFact;

THashFact* initFact();
void tblFact(THashSales *sales,THashFact *fact);
void printFact(THashFact* fact);
void freeFact(THashFact* fact);

#endif