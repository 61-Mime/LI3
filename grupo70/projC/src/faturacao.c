#include "faturacao.h"

#define SIZE 26
#define MAX 10

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));

  fact->cliNaoComprador = 0;
  fact->prodNaoComprado = 0;

  for(int i=0; i<SIZE; i++) {
    fact->tbl[i].size = 0;
    fact->tbl[i].list = NULL;
  }

  return fact;
}

Facturacao initFacturacao() {
  int i,i2;
  Facturacao *f = malloc(sizeof(Facturacao));

  f->prod = malloc(sizeof(char)*MAX);

  for(i = 0;i < 3;i++)
    for(i2 = 0;i2 < 12;i2++) {
      f->mesfilial[i2][i].vendasN = 0;
      f->mesfilial[i2][i].vendasP = 0;
      f->mesfilial[i2][i].facturacaoN = 0;
      f->mesfilial[i2][i].facturacaoP = 0;
    }

  return *f;
}

void tblFact(THashSales *sales, THashFact *fact) {
  int i,i2,i3,mes,filial;
  float f;

  for(i = 0;i < SIZE;i++) {
    fact -> tbl[i].size = sales -> tblp[i].size2;
    fact -> tbl[i].list = malloc(sizeof(Facturacao) * fact -> tbl[i].size);

    for(i2 = 0;i2 < fact->tbl[i].size;i2++) {
      fact -> tbl[i].list[i2] = initFacturacao();
      strcpy(fact -> tbl[i].list[i2].prod,sales -> tblp[i].list[i2].key);

      if(sales->tblp[i].list[i2].size3 == 0)
        fact->prodNaoComprado++;

      for(i3=0; i3<sales->tblp[i].list[i2].size3; i3++) {
        f = sales->tblp[i].list[i2].venda[i3].price * sales->tblp[i].list[i2].venda[i3].uni;
        mes = sales->tblp[i].list[i2].venda[i3].month;
        filial = sales->tblp[i].list[i2].venda[i3].branch;

        if(sales -> tblp[i].list[i2].venda[i3].type[0] == 'N') {
          fact -> tbl[i].list[i2].mesfilial[mes-1][filial-1].vendasN++;
          fact -> tbl[i].list[i2].mesfilial[mes-1][filial-1].facturacaoN += f;
        }
        else {
          fact -> tbl[i].list[i2].mesfilial[mes-1][filial-1].vendasP++;
          fact -> tbl[i].list[i2].mesfilial[mes-1][filial-1].facturacaoP += f;
        }
      }
    }

    for(i2=0; i2<sales->tblc[i].size2; i2++)
      if(sales->tblc[i].list[i2].size3 == 0)
        fact->cliNaoComprador++;
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

int getFatNumeroCli(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].numeroCli;
}

int getFatListSize(THashFact* fact, int i) {
  return fact->tbl[i].size;
}

int getFatProdNC(THashFact* fact) {
  return fact->prodNaoComprado;
}

int getFatCliNC(THashFact* fact) {
  return fact->cliNaoComprador;
}

