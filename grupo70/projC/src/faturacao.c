#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faturacao.h"

#define SIZE 26
#define MAX 10

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));

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

      for(i3 = 0;i3 < sales -> tblp[i].list[i2].size3;i3++) {
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
  }
}

void printFact(THashFact* fact) {
  int i,i2,i3;

  for(i=0; i<SIZE; i++)
    for(i2=0 ;i2<fact->tbl[i].size; i2++)
      for(i3=0 ;i3<12; i3++)
        printf("mês%d %s %d %d %f %f\r\n",i3,
                fact->tbl[i].list[i2].prod,
                fact->tbl[i].list[i2].mesfilial[i3][0].vendasP,
                fact->tbl[i].list[i2].mesfilial[i3][0].vendasN,
                fact->tbl[i].list[i2].mesfilial[i3][0].facturacaoP,
                fact->tbl[i].list[i2].mesfilial[i3][0].facturacaoN);
}

void freeFact(THashFact* fact) {
    int i;

    for(i=0; i<SIZE; i++)
        free(fact->tbl[i].list);

    free(fact);
}
