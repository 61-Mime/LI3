#include "faturacao.h"

#define SIZE 26
#define MAX 10

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));

  fact->prodComprado = 0;

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

  f->prod = key;

  for(i=0; i<12; i++)
    for(j=0 ; j<3; j++) {
      f->mesfilial[i][j].vendasN = 0;
      f->mesfilial[i][j].vendasP = 0;
      f->mesfilial[i][j].facturacaoN = 0;
      f->mesfilial[i][j].facturacaoP = 0;
    }
}

void loadFactFromProds(THashFact* fact, Catalogo* prod) {
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
  
  if(f->vendasN == 0 && f->vendasP == 0)
    fact->prodComprado ++;
  
  if(type == 'N') {
    f->vendasN ++;
    f->facturacaoN += (price * uni);
  }

  else {
    f->vendasP ++;
    f->facturacaoP += (price * uni);
  }
}

void freeFact(THashFact* fact) {
    int i;

    for(i=0; i<SIZE; i++)
        free(fact->tbl[i].list);

    free(fact);
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

int getFatListSize(THashFact* fact, int i) {
  return fact->tbl[i].size;
}

int getFatProdC(THashFact* fact) {
  return fact->prodComprado;
}
