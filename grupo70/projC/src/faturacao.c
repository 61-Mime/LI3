#include "faturacao.h"

#define SIZE 26
#define SMAX 10

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));
  fact->tbl = malloc(sizeof(TFacturacao) * SIZE);

  for(int i=0; i<SIZE; i++) {
    fact->tbl[i].size = 0;
    fact->tbl[i].list = NULL;
  }

  return fact;
}

void initTFacturacao(THashFact* fact, int i, int size) {
  TFacturacao* f = &fact->tbl[i];

  f->list = malloc(sizeof(Facturacao)*size);
  f->size = size;
}

void initFacturacao(THashFact* fact, int i, int j, char* key) {
  Facturacao *f = &fact->tbl[i].list[j];

  f->prod = malloc(sizeof(char) * SMAX);
  strcpy(f->prod, key);
  f->ocup = 0;

  for(i=0; i<12; i++)
    for(j=0 ; j<3; j++) {
      f->mesfilial[i][j].vendasN = 0;
      f->mesfilial[i][j].vendasP = 0;
      f->mesfilial[i][j].facturacaoN = 0;
      f->mesfilial[i][j].facturacaoP = 0;
      f->mesfilial[i][j].unidades = 0;
    }
}

void loadFactFromCat(THashFact* fact, Catalogo* prod) {
  int i, j, size;

  for(i=0; i<SIZE; i++) {
    size = getCatListSize(prod, i);
    initTFacturacao(fact, i, size);

    for(j=0; j<size; j++)
      initFacturacao(fact, i, j, getCatKey(prod, i, j));
  }
}

void addFact(THashFact* fact, int hash, int pos, int month, int branch, char type, float price, int uni) {
  FMensal* f = &fact->tbl[hash].list[pos].mesfilial[month-1][branch-1];

  if(type == 'N') {
    f->vendasN ++;
    f->facturacaoN += (price * uni);
  }

  else {
    f->vendasP ++;
    f->facturacaoP += (price * uni);
  }

  f->unidades += uni;

  if(fact->tbl[hash].list[pos].ocup == 0) fact->tbl[hash].list[pos].ocup = 1;
}

void freeFact(THashFact* fact) {
    int i, j;

    for(i=0; i<SIZE; i++) {
        for(j=0; j<fact->tbl[i].size; j++) {
          free(fact->tbl[i].list[j].prod);
          fact->tbl[i].list[j].prod = NULL;
        }
        free(fact->tbl[i].list);
        fact->tbl[i].list = NULL;
    }
    free(fact->tbl);
    fact->tbl = NULL;

    free(fact);
    fact = NULL;
}

//GETTERS

int getFatVendasN(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].vendasN;
}

int getFatVendasP(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].vendasP;
}

float getFatFaturacaoN(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].facturacaoN;
}

float getFatFaturacaoP(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].facturacaoP;
}

int getFatUnidades(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].unidades;
}

int getFatListSize(THashFact* fact, int i) {
  return fact->tbl[i].size;
}

int getFatOcup(THashFact* fact, int i, int j) {
  return fact->tbl[i].list[j].ocup;
}
