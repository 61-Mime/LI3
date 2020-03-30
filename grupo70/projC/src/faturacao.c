#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faturacao.h"

#define SIZE 26

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));

  fact -> size1 = 0;

  for(int i=0; i<SIZE; i++) {
    fact->tbl[i].size2 = 0;
    fact->tbl[i].list = NULL;
  }

  return fact;
}

void tblFact(THashSales *sales, THashFact *fact) {
  int i,i2,i3,f;

  for(i = 0;i < SIZE;i++) {
    fact -> tbl[i].size2 = sales -> tblp[i].size2;
    fact -> size1 += fact -> tbl[i].size2;
    fact -> tbl[i].list = malloc(sizeof(Facturacao) * fact -> tbl[i].size2);

    for(i2 = 0;i2 < fact->tbl[i].size2;i2++) {
      fact -> tbl[i].list[i2].prod = sales -> tblp[i].list[i2].key;
      fact -> tbl[i].list[i2].numeroN = 0;
      fact -> tbl[i].list[i2].numeroP = 0;
      fact -> tbl[i].list[i2].facturacaoN = 0;
      fact -> tbl[i].list[i2].facturacaoP = 0;

      for(i3 = 0;i3 < sales -> tblp[i].list[i2].size3;i3++) {
        f = sales->tblp[i].list[i2].venda[i3].price * sales->tblp[i].list[i2].venda[i3].uni;
        if(sales -> tblp[i].list[i2].venda[i3].type[0] == 'N') {
          fact -> tbl[i].list[i2].numeroN++;
          fact -> tbl[i].list[i2].facturacaoN += f;
        }
        else {
          fact -> tbl[i].list[i2].numeroP++;
          fact -> tbl[i].list[i2].facturacaoP += f;
        }
      }
    }
  }
}

void printFact(THashFact* fact) {
  int i,j;

  for(i=0; i<SIZE; i++){
    for(j=0 ;j<fact->tbl[i].size2; j++) {
        printf("%s %d %d %d %d\r\n",
                fact->tbl[i].list[j].prod,
                fact->tbl[i].list[j].numeroN,
                fact->tbl[i].list[j].numeroP,
                fact->tbl[i].list[j].facturacaoN,
                fact->tbl[i].list[j].facturacaoP);
    }
  }
}

void freeFact(THashFact* fact) {
    int i;

    for(i=0; i<SIZE; i++)
        free(fact->tbl[i].list);

    free(fact);
}
