#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"

#define SIZE 26
#define SMAX 10

TblFil* initFil() {
  TblFil* fil = malloc(sizeof(TblFil));

  for(int i=0; i<SIZE; i++) {
    fil->tblc[i].list = NULL;
    fil->tblc[i].size2 = 0;

    fil->tblp[i].list = NULL;
    fil->tblp[i].size2 = 0;
  }

  return fil;
}

void preenchevenda(Venda *v,Sale v2) {
  v->month = v2.month;
  v->uni = v2.uni;
  v->price = v2.price;
  v->branch = v2.branch;
  v->c = malloc(sizeof(char) * SMAX);
  v->p = malloc(sizeof(char) * SMAX);
  v->type = malloc(sizeof(char) * 2);
  strcpy(v->c,v2.c);
  strcpy(v->p,v2.p);
  strcpy(v->type,v2.type);
}

void tblFil(THashSales *sales,TblFil *fil, int filial) {
  int i,j,k;

  for(i = 0;i < SIZE;i++) {
    fil->tblp[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
    fil->tblp[i].size2 = sales->tblp[i].size2;

    for(j = 0;j < sales->tblp[i].size2;j++) {
      fil->tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil->tblp[i].list[j].key, sales->tblp[i].list[j].key);
      fil->tblp[i].list[j].size3 = 0;

      for(k = 0;k < sales->tblp[i].list[j].size3;k++) {
        if(sales->tblp[i].list[j].venda[k].branch == filial) {
          fil->tblp[i].list[j].venda = realloc(fil->tblp[i].list[j].venda,sizeof(Venda) * (fil->tblp[i].list[j].size3 + 1));
          fil->tblp[i].list[j].size3++;
          preenchevenda(&fil->tblp[i].list[j].venda[k], sales->tblp[i].list[j].venda[k]);
          printf("%d %d %d\n", i, j, k);
        }
      }
    }

    fil->tblc[i].list = malloc(sizeof(Lista) * sales->tblc[i].size2);
    fil ->tblc[i].size2 = sales->tblc[i].size2;

    for(j = 0;j < sales->tblc[i].size2;j++) {
      fil->tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil->tblc[i].list[j].key,sales->tblc[i].list[j].key);
      fil->tblc[i].list[j].size3 = 0;

      for(k = 0;k < sales->tblc[i].list[j].size3;k++) {
        if(sales->tblc[i].list[j].venda[k].branch == filial) {
          fil->tblc[i].list[j].venda = realloc(fil->tblc[i].list[j].venda,sizeof(Venda) * (fil->tblc[i].list[j].size3 + 1));
          fil->tblc[i].list[j].size3++;
          preenchevenda(&fil->tblc[i].list[j].venda[k],sales->tblc[i].list[j].venda[k]);
        }
      }
    }
  }
}

void printFils(TblFil* fil) {
  int i,j,c;

  for(i=0; i<SIZE; i++){
    for(j=0 ;j<fil->tblp[i].size2; j++) {
      for(c=0 ;c<fil->tblp[i].list[j].size3; c++)
        printf("%s %f %d %s %s %d %d\n",
                fil->tblp[i].list[j].venda[c].p,
                fil->tblp[i].list[j].venda[c].price,
                fil->tblp[i].list[j].venda[c].uni,
                fil->tblp[i].list[j].venda[c].type,
                fil->tblp[i].list[j].venda[c].c,
                fil->tblp[i].list[j].venda[c].month,
                fil->tblp[i].list[j].venda[c].branch);
    }
  }
}

void freeFil(TblFil* fil) {
  free(fil);
}