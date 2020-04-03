#ifndef __faturacao_h
#define __faturacao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

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
void loadFactFromCat(THashFact* fact, Catalogo* prod);
void addFact(THashFact* fact, int hash, int pos, int month, int branch, char type, float price, int uni);
void freeFact(THashFact* fact);

// GETTERS
int getFatVendasN(THashFact* fact, int i, int j, int month, int branch);
int getFatVendasP(THashFact* fact, int i, int j, int month, int branch);
float getFatFaturacaoN(THashFact* fact, int i, int j, int month, int branch);
float getFatFaturacaoP(THashFact* fact, int i, int j, int month, int branch);
int getFatListSize(THashFact* fact, int i);

#endif
