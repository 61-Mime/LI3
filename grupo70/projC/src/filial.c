#include "filial.h"

#define SIZE 26
#define SMAX 10

GFiliais* initGFil() {
  GFiliais* gfil = malloc(sizeof(GFiliais));

  gfil -> compradores = 0;

  for(int i=0; i<3; i++) {
    for(int j=0; j<SIZE; j++)
      gfil->fil[i].tblc[i].list = NULL;
      gfil->fil[i].tblc[i].sizeCli = 0;
      gfil->fil[i].tblp[i].list = NULL;
      gfil->fil[i].tblp[i].sizeProd = 0;
  }

  return gfil;
}

void initTFilialP(GFiliais* gfil, int fil, int i, int size) {
  TFilialP* f = &gfil->fil[fil].tblp[i];

  f->sizeProd = size;
  f->list = malloc(sizeof(ListP)*size);
}

void initListP(GFiliais* gfil, int fil, int i, int j, char* key) {
  ListP* l = &gfil->fil[fil].tblp[i].list[j];

  l->cliN = NULL;
  l->cliP = NULL;
  l->sizeN = 0;
  l->sizeP = 0;
  l->key = key;
}

void initTFilialC(GFiliais* gfil, int fil, int i, int size) {
  TFilialC* f = &gfil->fil[fil].tblc[i];

  f->sizeCli = size;
  f->list = malloc(sizeof(ListC)*size);
}

void initListC(GFiliais* gfil, int fil, int i, int j, char* key) {
  ListC* l = &gfil->fil[fil].tblc[i].list[j];

  l->prods = NULL;
  l->sizeProds = 0;
  l->key = key;
}

void loadGFilFromCat(GFiliais* gfil, Catalogo* prod, Catalogo* cli) {
  int i, j, fil, size;

  for(fil=0; fil<3; fil++)
    for(i=0; i<SIZE; i++) {
      size = getCatListSize(prod, i);
      initTFilialP(gfil, fil, i, size);

      for(j=0; j<size; j++)
        initListP(gfil, fil, i, j, getCatKey(prod, i, j));

      size = getCatListSize(cli, i);
      initTFilialC(gfil, fil, i, size);

      for(j=0; j<size; j++)
        initListC(gfil, fil, i, j, getCatKey(cli, i, j));
    }
}

int existsGFilP(ListP* lp, char* cli, char type) {
  int i, r=0;

  if(type == 'N') {
    for(i=0; i<lp->sizeN && r; i++)
      if(strcmp(lp->cliN[i], cli)==0)
        r = 1;
  }
  
  else {
    for(i=0; i<lp->sizeP && r; i++)
      if(strcmp(lp->cliP[i], cli)==0)
        r = 1;
  }
  
  return r;
}

void addGFilP(GFiliais* gfil, int hash, int pos, char* cli, int branch, char type) {
  ListP *lp = &gfil->fil[branch-1].tblp[hash].list[pos];

  if(existsGFilP(lp, cli, type) == 0) {
    if(type == 'N') {
      lp->cliN = realloc(lp->cliN, sizeof(char*)*(lp->sizeN + 1));
      lp->cliN[lp->sizeN] = malloc(sizeof(char) * SMAX);
      strcpy(lp->cliN[lp->sizeN], cli);
      lp->sizeN++;
    }

    else {
      lp->cliP = realloc(lp->cliP, sizeof(char*)* (lp->sizeP + 1));
      lp->cliP[lp->sizeP] = malloc(sizeof(char) * SMAX);
      strcpy(lp->cliP[lp->sizeP], cli);
      lp->sizeP++;
    }
  }
}

int existsGFilC(ListC* lc, char* prod) {
  int i, r=0;

  for(i=0; i<lc->sizeProds && r==0; i++)
    if(strcmp(lc->prods[i].prod, prod)==0)
      r=i;

  return r;
}

void addGFilC(GFiliais* gfil, int hash, int pos, char* prod, int branch, int month, float price, int uni) {
  int i, j;
  ListC* lc = &gfil->fil[branch-1].tblc[hash].list[pos];
  
  /*
  if(lc->sizeProds == 0) 
    gfil -> compradores++;
  */

  if((j = existsGFilC(lc, prod)) != 0) {
    lc->prods[j].uni[month - 1] += uni;
    lc->prods[j].fat += uni * price;
  }

  else {
    lc->prods = realloc(lc->prods, sizeof(ProdCli)*(lc->sizeProds + 1));

    for(i=0; i<12; i++)
      lc->prods[lc->sizeProds].uni[i] = 0;

    lc->prods[lc->sizeProds].prod = malloc(sizeof(char) * SMAX);
    strcpy(lc->prods[lc->sizeProds].prod, prod);
    lc->prods[lc->sizeProds].uni[month - 1] = uni;
    lc->prods[lc->sizeProds].fat = uni * price;
    lc->sizeProds++;
  }
}

void freeGFil(GFiliais* gfil) {
  int fil, i, j, k;

  for(fil=0; fil<3; fil++) {
    for(i=0; i<SIZE; i++) {
      for(j=0; j<gfil->fil[fil].tblc[i].sizeCli; j++)
        free(gfil->fil[fil].tblc[i].list[j].prods);

      for(j=0; j<gfil->fil[fil].tblp[i].sizeProd; j++) {
        for(k=0; k<gfil->fil[fil].tblp[i].list[j].sizeN; k++)
          free(gfil->fil[fil].tblp[i].list[j].cliN[k]);

        for(k=0; k<gfil->fil[fil].tblp[i].list[j].sizeP; k++)
          free(gfil->fil[fil].tblp[i].list[j].cliP[k]);

        free(gfil->fil[fil].tblp[i].list[j].cliN);
        free(gfil->fil[fil].tblp[i].list[j].cliP);
      }

      free(gfil->fil[fil].tblc[i].list);
      free(gfil->fil[fil].tblp[i].list);
    }
  }

  free(gfil);
}

// GETTERS

int getGFilPSizeP(GFiliais* gfil, int branch, int i, int j) {
  return gfil->fil[branch].tblp[i].list[j].sizeP;
}

int getGFilPSizeN(GFiliais* gfil, int branch, int i, int j) {
  return gfil->fil[branch].tblp[i].list[j].sizeN;
}

char* getGFilPCliP(GFiliais* gfil, int branch, int i, int j, int k) {
  return strdup(gfil->fil[branch].tblp[i].list[j].cliP[k]);
}

char* getGFilPCliN(GFiliais* gfil, int branch, int i, int j, int k) {
  return strdup(gfil->fil[branch].tblp[i].list[j].cliN[k]);
}

ListP* getGFilPList(GFiliais* gfil, int branch, int i, int j) {
  return &(gfil->fil[branch].tblp[i].list[j]);
}

int getGFilPListSize(GFiliais* gfil, int branch, int i) {
  return gfil->fil[branch].tblp[i].sizeProd;
}

ListC* getGFilCList(GFiliais* gfil, int branch, int i, int j) {
  return &(gfil->fil[branch].tblc[i].list[j]);
}

int getGFilCListSize(GFiliais* gfil, int branch, int i) {
  return gfil->fil[branch].tblc[i].sizeCli;
}

char* getGFilCprod(GFiliais*gfil,int branch,int i,int j,int k) {
  return strdup(gfil->fil[branch].tblc[i].list[j].prods[k].prod);
}

int getGFilCuni(GFiliais*gfil,int branch,int i,int j,int k,int m) {
  return gfil->fil[branch].tblc[i].list[j].prods[k].uni[m];
}

float getGFilCfat(GFiliais*gfil,int branch,int i,int j,int k) {
  return gfil->fil[branch].tblc[i].list[j].prods[k].fat;
}

int getGFilCsizeProds(GFiliais*gfil,int branch,int i,int j) {
  return gfil->fil[branch].tblc[i].list[j].sizeProds;
}

int getGFilComp(GFiliais*gfil) {
  return gfil->compradores;
}