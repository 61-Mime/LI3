#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"

#define SIZE 26
#define SMAX 10

GFiliais* initGFil() {
  GFiliais* gfil = malloc(sizeof(GFiliais));

  for(int i=0; i<SIZE; i++) {
    gfil->fil1.tblc[i].list = NULL;
    gfil->fil1.tblc[i].sizeCli = 0;
    gfil->fil1.tblp[i].list = NULL;
    gfil->fil1.tblp[i].sizeProd = 0;

    gfil->fil2.tblc[i].list = NULL;
    gfil->fil2.tblc[i].sizeCli = 0;
    gfil->fil2.tblp[i].list = NULL;
    gfil->fil2.tblp[i].sizeProd = 0;

    gfil->fil3.tblc[i].list = NULL;
    gfil->fil3.tblc[i].sizeCli = 0;
    gfil->fil3.tblp[i].list = NULL;
    gfil->fil3.tblp[i].sizeProd = 0;
  }

  return gfil;
}

void initLists(GFiliais* gfil, THashSales* sales, int i) {
  gfil->fil1.tblc[i].list = malloc(sizeof(ListC) * sales->tblc[i].size2);
  gfil->fil1.tblc[i].sizeCli = sales->tblc[i].size2;
  gfil->fil1.tblp[i].list = malloc(sizeof(ListP) * sales->tblp[i].size2);
  gfil->fil1.tblp[i].sizeProd = sales->tblp[i].size2;

  gfil->fil2.tblc[i].list = malloc(sizeof(ListC) * sales->tblc[i].size2);
  gfil->fil2.tblc[i].sizeCli = sales->tblc[i].size2;
  gfil->fil2.tblp[i].list = malloc(sizeof(ListP) * sales->tblp[i].size2);
  gfil->fil2.tblp[i].sizeProd = sales->tblp[i].size2;

  gfil->fil3.tblc[i].list = malloc(sizeof(ListC) * sales->tblc[i].size2);
  gfil->fil3.tblc[i].sizeCli = sales->tblc[i].size2;
  gfil->fil3.tblp[i].list = malloc(sizeof(ListP) * sales->tblp[i].size2);
  gfil->fil3.tblp[i].sizeProd = sales->tblp[i].size2;
}

void initFCli(THashSales* sales, GFiliais* gfil, int i, int j) {
  gfil->fil1.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil1.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil1.tblc[i].list[j].sizeProds = 0;

  gfil->fil2.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil2.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil2.tblc[i].list[j].sizeProds = 0;

  gfil->fil3.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil3.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil3.tblc[i].list[j].sizeProds = 0;
}

void initFProd(THashSales* sales, GFiliais* gfil, int i, int j) {
  gfil->fil1.tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil1.tblp[i].list[j].key,sales->tblp[i].list[j].key);
  gfil->fil1.tblp[i].list[j].sizeN = 0;
  gfil->fil1.tblp[i].list[j].sizeP = 0;

  gfil->fil2.tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil2.tblp[i].list[j].key,sales->tblp[i].list[j].key);
  gfil->fil2.tblp[i].list[j].sizeN = 0;
  gfil->fil2.tblp[i].list[j].sizeP = 0;

  gfil->fil3.tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil3.tblp[i].list[j].key,sales->tblp[i].list[j].key);
  gfil->fil3.tblp[i].list[j].sizeN = 0;
  gfil->fil3.tblp[i].list[j].sizeP = 0;
}

void preencheListC(ListC* list, Sale s) {
  int i, pos= list->sizeProds;
  list->prods = realloc(list->prods, sizeof(ProdCli)*(pos + 1));
  
  for(i=0; i<12; i++)
    list->prods[pos].uni[i] = 0;

  strcpy(list->prods[pos].prod, s.p);
  list->prods[pos].uni[s.month - 1] = s.uni;
  list->prods[pos].fat = s.uni * s.price;

  list->sizeProds ++;
}

void preencheListP(ListP* list, Sale s) {
  int pos;

  if (s.type[0] == 'N') {
    pos = list->sizeN;
    list->cliN = realloc(list->cliN, sizeof(char*)*(pos+1));
    list->cliN[pos] = realloc(list->cliN[pos], sizeof(char) * SMAX);
    strcpy(list->cliN[pos], s.c);

    list->sizeN++;
  }

  else {
    pos = list->sizeP;
    list->cliP = realloc(list->cliP, sizeof(char*)*(pos+1));
    list->cliP[pos] = realloc(list->cliP[pos], sizeof(char) * SMAX);
    strcpy(list->cliN[pos], s.c);

    list->sizeP++;
  }
}

void tblGFil(GFiliais* gfil, THashSales* sales) {
  int i,j,k;

  for(i=0; i<SIZE; i++) {
    initLists(gfil, sales, i);

    for(j=0; j<sales->tblc[i].size2; j++) {
      initFCli(sales, gfil, i, j);
      for(k = 0;k < sales->tblc[i].list[j].size3;k++) {
        if(sales->tblp[i].list[j].venda[k].branch == 1) {
          preencheListC(&gfil->fil1.tblc[i].list[j], sales->tblc[i].list[j].venda[k]);
        }
        else if(sales->tblp[i].list[j].venda[k].branch == 2) {
          preencheListC(&gfil->fil2.tblc[i].list[j], sales->tblc[i].list[j].venda[k]);
        }
        else {
          preencheListC(&gfil->fil3.tblc[i].list[j], sales->tblc[i].list[j].venda[k]);
        }
      }
    }

    for(j = 0;j < sales->tblp[i].size2;j++) {
      initFProd(sales, gfil, i, j);
      for(k = 0;k < sales->tblp[i].list[j].size3;k++) {
        if(sales->tblp[i].list[j].venda[k].branch == 1) {
          preencheListP(&gfil->fil1.tblp[i].list[j], sales->tblp[i].list[j].venda[k]);
        }
        else if(sales->tblp[i].list[j].venda[k].branch == 2) {
          preencheListP(&gfil->fil2.tblp[i].list[j], sales->tblp[i].list[j].venda[k]);
        }
        else {
          preencheListP(&gfil->fil3.tblp[i].list[j], sales->tblp[i].list[j].venda[k]);
        }
      }
    }
  }
}

void freeGFil(GFiliais* gfil) {
  return;
}
