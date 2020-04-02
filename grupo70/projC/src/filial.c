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

void initLists(GFiliais* gfil,int sizec, int sizep,int i) {
  gfil->fil1.tblc[i].list = malloc(sizeof(ListC) * sizec);
  gfil->fil1.tblc[i].sizeCli = sizec;
  gfil->fil1.tblp[i].list = malloc(sizeof(ListP) * sizep);
  gfil->fil1.tblp[i].sizeProd = sizep;

  gfil->fil2.tblc[i].list = malloc(sizeof(ListC) * sizec);
  gfil->fil2.tblc[i].sizeCli = sizec;
  gfil->fil2.tblp[i].list = malloc(sizeof(ListP) * sizep);
  gfil->fil2.tblp[i].sizeProd = sizep;

  gfil->fil3.tblc[i].list = malloc(sizeof(ListC) * sizec);
  gfil->fil3.tblc[i].sizeCli = sizec;
  gfil->fil3.tblp[i].list = malloc(sizeof(ListP) * sizep);
  gfil->fil3.tblp[i].sizeProd = sizep;
}

void initFCli(THashSales* sales, GFiliais* gfil, int i, int j) {
  gfil->fil1.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil1.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil1.tblc[i].list[j].sizeProds = 0;
  gfil->fil1.tblc[i].list[j].prods = NULL;

  gfil->fil2.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil2.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil2.tblc[i].list[j].sizeProds = 0;
  gfil->fil2.tblc[i].list[j].prods = NULL;

  gfil->fil3.tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
  strcpy(gfil->fil3.tblc[i].list[j].key,sales->tblc[i].list[j].key);
  gfil->fil3.tblc[i].list[j].sizeProds = 0;
  gfil->fil3.tblc[i].list[j].prods = NULL;
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

void preencheListC(ProdCli* prods, Sale s) {
  int i;

  for(i=0; i<12; i++)
    prods->uni[i] = 0;

  strcpy(prods->prod, s.p);
  prods->uni[s.month - 1] = s.uni;
  prods->fat = s.uni * s.price;
}

char** preencheListP(char** list, Sale s,int pos) {
  if (s.type[0] == 'N') {
    list = realloc(list, sizeof(char*)*(pos+1));
    list[pos] = malloc(sizeof(char) * SMAX);
    strcpy(list[pos], s.c);
  }
  else {
    list = realloc(list,sizeof(char*)*(pos+1));
    list[pos] = malloc(sizeof(char) * SMAX);
    strcpy(list[pos], s.c);
  }
  return list;
}

void insereFilC(GFiliais* gfil,Sale s,int i,int j) {
  int size;
  if(s.branch == 1) {
    size = gfil->fil1.tblc[i].list[j].sizeProds;
    gfil->fil1.tblc[i].list[j].prods = realloc(gfil->fil1.tblc[i].list[j].prods, sizeof(ProdCli)*(size + 1));
    preencheListC(&gfil->fil1.tblc[i].list[j].prods[size], s);
    gfil->fil1.tblc[i].list[j].sizeProds++;
  }
  else if(s.branch == 2) {
    size = gfil->fil2.tblc[i].list[j].sizeProds;
    gfil->fil2.tblc[i].list[j].prods = realloc(gfil->fil2.tblc[i].list[j].prods, sizeof(ProdCli)*(size + 1));
    preencheListC(&gfil->fil2.tblc[i].list[j].prods[size], s);
    gfil->fil2.tblc[i].list[j].sizeProds++;
  }
  else {
    size = gfil->fil3.tblc[i].list[j].sizeProds;
    gfil->fil3.tblc[i].list[j].prods = realloc(gfil->fil3.tblc[i].list[j].prods, sizeof(ProdCli)*(size + 1));
    preencheListC(&gfil->fil3.tblc[i].list[j].prods[size], s);
    gfil->fil3.tblc[i].list[j].sizeProds++;
  }
}

void insereFilP(GFiliais* gfil,Sale s,int i,int j) {
  int size;
  if(s.branch == 1) {
    if(s.type[0] == 'N') {
      size = gfil->fil1.tblp[i].list[j].sizeN;
      gfil->fil1.tblp[i].list[j].sizeN++;
      gfil->fil1.tblp[i].list[j].cliN = preencheListP(gfil->fil1.tblp[i].list[j].cliN, s,size);
    }
    else {
      size = gfil->fil1.tblp[i].list[j].sizeP;
      gfil->fil1.tblp[i].list[j].sizeP++;
      gfil->fil1.tblp[i].list[j].cliP = preencheListP(gfil->fil1.tblp[i].list[j].cliP, s,size);
    }
  }
  else if(s.branch == 2) {
    if(s.type[0] == 'N') {
      size = gfil->fil2.tblp[i].list[j].sizeN;
      gfil->fil2.tblp[i].list[j].sizeN++;
      gfil->fil2.tblp[i].list[j].cliN = preencheListP(gfil->fil2.tblp[i].list[j].cliN, s,size);
    }
    else {
      size = gfil->fil2.tblp[i].list[j].sizeP;
      gfil->fil2.tblp[i].list[j].sizeP++;
      gfil->fil2.tblp[i].list[j].cliP = preencheListP(gfil->fil2.tblp[i].list[j].cliP, s,size);
    }
  }
  else {
    if(s.type[0] == 'N') {
      size = gfil->fil3.tblp[i].list[j].sizeN;
      gfil->fil3.tblp[i].list[j].sizeN++;
      gfil->fil3.tblp[i].list[j].cliN = preencheListP(gfil->fil3.tblp[i].list[j].cliN, s,size);
    }
    else {
      size = gfil->fil3.tblp[i].list[j].sizeP;
      gfil->fil3.tblp[i].list[j].sizeP++;
      gfil->fil3.tblp[i].list[j].cliP = preencheListP(gfil->fil3.tblp[i].list[j].cliP, s,size);
    }
  }
}

void tblGFil(GFiliais* gfil, THashSales* sales) {
  int i,j,k;

  for(i=0; i<SIZE; i++) {
    initLists(gfil,sales->tblc[i].size2,sales->tblp[i].size2,i);

    for(j=0; j<sales->tblc[i].size2; j++) {
      initFCli(sales, gfil, i, j);
      for(k = 0;k < sales->tblc[i].list[j].size3;k++) {
        insereFilC(gfil,sales->tblc[i].list[j].venda[k],i,j);
      }
    }

    for(j = 0;j < sales->tblp[i].size2;j++) {
      initFProd(sales, gfil, i, j);
      for(k = 0;k < sales->tblp[i].list[j].size3;k++) {
        insereFilP(gfil,sales->tblp[i].list[j].venda[k],i,j);
      }
    }
  }
}

void freeGFil(GFiliais* gfil) {
  int i, j, k;

  for(i=0; i<SIZE; i++) {
    for(j=0; j<gfil->fil1.tblc[i].sizeCli; j++) {
      free(gfil->fil1.tblc[i].list[j].prods);
      free(gfil->fil2.tblc[i].list[j].prods);
      free(gfil->fil3.tblc[i].list[j].prods);
    }

    for(j=0; j<gfil->fil1.tblp[i].sizeProd; j++) {
      for(k=0; k<gfil->fil1.tblp[i].list[j].sizeN; k++) {
        free(gfil->fil1.tblp[i].list[j].cliN[k]);
      }

      for(k=0; k<gfil->fil2.tblp[i].list[j].sizeN; k++) {
        free(gfil->fil2.tblp[i].list[j].cliN[k]);
      }

      for(k=0; k<gfil->fil3.tblp[i].list[j].sizeN; k++) {
        free(gfil->fil3.tblp[i].list[j].cliN[k]);
      }

      for(k=0; k<gfil->fil1.tblp[i].list[j].sizeP; k++) {
        free(gfil->fil1.tblp[i].list[j].cliP[k]);
      }

      for(k=0; k<gfil->fil2.tblp[i].list[j].sizeP; k++) {
        free(gfil->fil2.tblp[i].list[j].cliP[k]);
      }

      for(k=0; k<gfil->fil3.tblp[i].list[j].sizeP; k++) {
        free(gfil->fil3.tblp[i].list[j].cliP[k]);
      }

      free(gfil->fil1.tblp[i].list[j].cliN);
      free(gfil->fil2.tblp[i].list[j].cliN);
      free(gfil->fil3.tblp[i].list[j].cliN);

      free(gfil->fil1.tblp[i].list[j].cliP);
      free(gfil->fil2.tblp[i].list[j].cliP);
      free(gfil->fil3.tblp[i].list[j].cliP);
    }

    free(gfil->fil1.tblc[i].list);
    free(gfil->fil2.tblc[i].list);
    free(gfil->fil3.tblc[i].list);

    free(gfil->fil1.tblp[i].list);
    free(gfil->fil2.tblp[i].list);
    free(gfil->fil3.tblp[i].list);
  }

  free(gfil);
}
