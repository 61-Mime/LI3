/**
 * @file  filial.c
 * @brief Ficheiro que contém funções relativas ao módulo Filial
 */

#include "filial.h"

#define SIZE 26
#define SMAX 10

typedef struct prodcli{
  char* prod;
  int* uni;
  int mes;
  float fat;
} ProdCli;

typedef struct listc{
  char* key;
  int sizeProds;
  ProdCli* prods;
} ListC;

typedef struct tfilc{
  int sizeCli;
  ListC* list;
} TFilialC;

typedef struct listp{
  char* key;
  int sizeN;
  int sizeP;
  int sizeC;
  char** cliN;
  char** cliP;
} ListP;

typedef struct tfilp{
  int sizeProd;
  ListP* list;
} TFilialP;

typedef struct filial{
  TFilialC* tblc;
  TFilialP* tblp;
} THashFilial;

typedef struct gfiliais{
  THashFilial* fil;
} GFiliais;

/**
 * @brief   Função inicializa a estrutura GFiliais
 * @return  Apontador para GFiliais
 */
GFiliais* initGFil() {
  GFiliais* gfil = malloc(sizeof(GFiliais));
  gfil->fil = malloc(sizeof(THashFilial) * 3);

  for(int i=0; i<3; i++) {
    gfil->fil[i].tblc = malloc(sizeof(TFilialC)*SIZE);
    gfil->fil[i].tblp = malloc(sizeof(TFilialP)*SIZE);
    for(int j=0; j<SIZE; j++)
      {
        gfil->fil[i].tblc[i].list = NULL;
        gfil->fil[i].tblc[i].sizeCli = 0;
        gfil->fil[i].tblp[i].list = NULL;
        gfil->fil[i].tblp[i].sizeProd = 0;
      }
  }

  return gfil;
}

/**
 * @brief       Função inicializa a estrutura TFilialP
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblp
 * @param size  Inteiro com o tamanho para a estrutura
 */
void initTFilialP(GFiliais* gfil, int fil, int i, int size) {
  TFilialP* f = &gfil->fil[fil].tblp[i];

  f->sizeProd = size;
  f->list = malloc(sizeof(ListP)*size);
}

/**
 * @brief       Função inicializa a estrutura ListP
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblp
 * @param j     Posição no array list
 * @param prod  String com o produto
 */
void initListP(GFiliais* gfil, int fil, int i, int j, char* prod) {
  ListP* l = &gfil->fil[fil].tblp[i].list[j];

  l->cliN = NULL;
  l->cliP = NULL;
  l->sizeN = 0;
  l->sizeP = 0;
  l->sizeC = 0;
  // FAZER FREE DO KEY
  l->key = malloc(sizeof(char)*SMAX);
  strcpy(l->key, prod);
}

/**
 * @brief       Função inicializa a estrutura TFilialC
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblc
 * @param size  Inteiro com o tamanho para a estrutura
 */
void initTFilialC(GFiliais* gfil, int fil, int i, int size) {
  TFilialC* f = &gfil->fil[fil].tblc[i];

  f->sizeCli = size;
  f->list = malloc(sizeof(ListC)*size);
}

/**
 * @brief       Função inicializa a estrutura ListC
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblc
 * @param j     Posição no array list
 * @param prod  String com o cliente
 */
void initListC(GFiliais* gfil, int fil, int i, int j, char* cli) {
  ListC* l = &gfil->fil[fil].tblc[i].list[j];

  l->prods = NULL;
  l->sizeProds = 0;
  //FAZER FREE DO KEY
  l->key = malloc(sizeof(char)*SMAX);
  strcpy(l->key, cli);
}

/**
 * @brief       Função carrega a estrutura GFiliais com todos os Produtos e Clientes
 * @param gfil  Apontador para GFiliais
 * @param prod  Apontador para Catalogo de Produtos
 * @param cli   Apontador para Catalogo de Clientes
 */
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

/**
 * @brief       Função conta clientes diferentes de um produto
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblp
 * @param i2    Posição no array list
 */
void contaCli(GFiliais *gfil,int i,int i2,int fil) {
  int i3;
  ListP* lp;

  lp = &gfil->fil[fil].tblp[i].list[i2];
  if(lp -> sizeN == 0) lp -> sizeC = lp -> sizeP;
  if(lp -> sizeP == 0) lp -> sizeC = lp -> sizeN;

  else {
    lp -> sizeC = lp -> sizeP;
    for(i3 = 0;i3 < lp -> sizeN;i3++)
      if(binarySearch(lp -> cliP,lp -> cliN[i3],0,lp -> sizeP - 1)==-1)
        lp -> sizeC++;
  }
}

/**
 * @brief       Função da free dos clientes repetidos de um produto
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblp
 * @param i2    Posição no array list
 * @param size  Tamanho lista cliente com repetidos
 * @param t     destinge cliente N(1) de cliente P(0)
 */
void freeRepP(GFiliais *gfil,int fil,int i,int i2,int size,int t) {
  int i3;
  ListP* lp = &gfil->fil[fil].tblp[i].list[i2];

  if(t) i3 = lp -> sizeN;
  else i3 = lp -> sizeP;
  for(;i3 < size;i3++){
    if(t){
      free(lp->cliN[i3]);
      lp->cliN[i3] = NULL;
    }
    else {
      free(lp->cliP[i3]);
      lp->cliP[i3] = NULL;
    }
  }
}

/**
 * @brief       Função remove para cada produto os clientes repetidos
 */
void remRepP(GFiliais *gfil) {
  int i,i2,i3,i4,fil,c,size;
  ListP* lc;

  for(fil = 0;fil < 3;fil++)
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < gfil->fil[fil].tblp[i].sizeProd;i2++){
        lc = &gfil->fil[fil].tblp[i].list[i2];
        if(lc->sizeN != 0) {
          size = lc->sizeN;
          quickSort(lc->cliN,0,size-1);

          for(i3 = 0,c = 1;c < size;i3++) {
            for(i4 = c;i4 < size && !strcmp(lc->cliN[i4],lc->cliN[i3]);i4++);

            if(i4 != i3+1 && i4 < size)
              swap(&lc->cliN[i3 + 1],&lc->cliN[i4]);

            c = i4 + 1;
            if(i4 == size) i3--;
          }
          if(lc->sizeN != i3 + 1) {
            lc->sizeN = i3 + 1;
            freeRepP(gfil,fil,i,i2,size,1);
          }
        }

        if(lc->sizeP != 0) {
          size = lc->sizeP;
          quickSort(lc->cliP,0,size-1);

          for(i3 = 0,c = 1;c < size;i3++) {
            for(i4 = c;i4 < size && !strcmp(lc->cliP[i4],lc->cliP[i3]);i4++);

            if(i4 != i3+1 && i4 < size)
              swap(&lc->cliP[i3 + 1],&lc->cliP[i4]);

            c = i4 + 1;
            if(i4 == size) i3--;
          }
          if(lc->sizeP != i3 + 1) {
            lc->sizeP = i3 + 1;
            freeRepP(gfil,fil,i,i2,size,0);
          }
          contaCli(gfil,i,i2,fil);
        }
      }
}

/**
 * @brief         Função adiciona venda à parte da GFiliais organizada por produtos
 * @param gfil    Apontador para GFiliais
 * @param hash    Inteiro com posição no array tblp
 * @param pos     Inteiro com posição no array list
 * @param cli     String com Cliente da venda
 * @param branch  Inteiro com Filial da venda
 * @param type    Char com o tipo de venda
 */
void addGFilP(GFiliais* gfil, int hash, int pos, char* cli, int branch, char type) {
  ListP *lp = &gfil->fil[branch-1].tblp[hash].list[pos];

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

void swapPCli(ProdCli *a, ProdCli *b)
{
    ProdCli aux = *a;
    *a = *b;
    *b = aux;
}

void quickSortbyProd(ProdCli *prods, int low, int high)
{
    if (low < high)
    {
      char* pivot = prods[high].prod;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(prods[j].prod, pivot) < 0)
          {
              i++;
              swapPCli(&prods[i], &prods[j]);
          }
      }
      swapPCli(&prods[i + 1], &prods[high]);

      int pi = i + 1;

      quickSortbyProd(prods, low, pi - 1);
      quickSortbyProd(prods, pi + 1, high);
    }
}

/**
 * @brief       Função da free dos produtos repetidos de um cliente
 * @param gfil  Apontador para GFiliais
 * @param fil   Posição no array fil
 * @param i     Posição no array tblc
 * @param i2    Posição no array list
 * @param size  Tamanho lista produtos com repetidos
 */
void freeRepC(GFiliais *gfil,int fil,int i,int i2,int size) {
  ListC* lc = &gfil->fil[fil].tblc[i].list[i2];
  for(int i3 = lc -> sizeProds; i3 < size;i3++){
    free(lc->prods[i3].prod);
    lc->prods[i3].prod = NULL;
    free(lc->prods[i3].uni);
    lc->prods[i3].uni = NULL;
  }
}

/**
 * @brief       Função remove para cada cliente os produtos repetidos
 */
void remRepC(GFiliais *gfil) {
  int i,i2,i3,i4,fil,c,size;
  ListC* lc;

  for(fil = 0;fil < 3;fil++)
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < gfil->fil[fil].tblc[i].sizeCli;i2++){
        lc = &gfil->fil[fil].tblc[i].list[i2];
        if(lc->prods != NULL) {
          size = lc->sizeProds;
          quickSortbyProd(lc->prods,0,size-1);

          for(i3 = 0,c = 1;c < size;i3++) {
            for(i4 = c;i4 < size && !strcmp(lc->prods[i4].prod,lc->prods[i3].prod);i4++)
                lc->prods[i3].uni[lc->prods[i4].mes-1] += lc->prods[i4].uni[lc->prods[i4].mes-1];

            if(i4 != i3+1 && i4 < size)
              swapPCli(&lc->prods[i3 + 1],&lc->prods[i4]);

            c = i4 + 1;
            if(i4 == size) i3--;
          }
          if(lc->sizeProds != i3 + 1) {
            lc->sizeProds = i3 + 1;
            freeRepC(gfil,fil,i,i2,size);
          }
        }
      }
}

/**
 * @brief         Função adiciona venda à parte da GFiliais organizada por clientes
 * @param gfil    Apontador para GFiliais
 * @param hash    Posição no array tblc
 * @param pos     Posição no array list
 * @param prod    String com Produto da venda
 * @param branch  Inteiro com Filial da venda
 * @param month   Inteiro com Mes da venda
 * @param price   Float com Preço do produto da venda
 * @param uni     Inteiro com numero de unidades da venda
 */
void addGFilC(GFiliais* gfil, int hash, int pos, char* prod, int branch, int month, float price, int uni) {
  int i;
  ListC* lc = &gfil->fil[branch-1].tblc[hash].list[pos];

  lc->prods = realloc(lc->prods, sizeof(ProdCli)*(lc->sizeProds + 1));
  lc->prods[lc->sizeProds].uni = malloc(sizeof(int) * 12);

  for(i=0; i<12; i++)
    lc->prods[lc->sizeProds].uni[i] = 0;

  lc->prods[lc->sizeProds].prod = malloc(sizeof(char) * SMAX);
  strcpy(lc->prods[lc->sizeProds].prod, prod);
  lc->prods[lc->sizeProds].uni[month - 1] = uni;
  lc->prods[lc->sizeProds].mes = month;
  lc->prods[lc->sizeProds].fat = uni * price;
  lc->sizeProds++;
}

/**
 * @brief       Função liberta o espaço de memoria ocupado pela GFiliais
 * @param gfil  Apontador para GFiliais
 */
void freeGFil(GFiliais* gfil) {
  int fil, i, j, k;
  ListC *lc;
  ListP *lp;

  for(fil=0; fil<3; fil++) {
    for(i=0; i<SIZE; i++) {
      for(j=0; j<gfil->fil[fil].tblc[i].sizeCli; j++) {
        lc = &gfil->fil[fil].tblc[i].list[j];
        for(k=0; k<lc->sizeProds; k++) {
          free(lc->prods[k].prod);
          lc->prods[k].prod = NULL;
          free(lc->prods[k].uni);
          lc->prods[k].uni = NULL;
        }
        free(lc->prods);
        lc->prods = NULL;
      }

      for(j=0; j<gfil->fil[fil].tblp[i].sizeProd; j++) {
        lp = &gfil->fil[fil].tblp[i].list[j];
        for(k=0; k<lp->sizeN; k++) {
          free(lp->cliN[k]);
          lp->cliN[k] = NULL;
        }

        for(k=0; k<lp->sizeP; k++) {
          free(lp->cliP[k]);
          lp->cliP[k] = NULL;
        }

        free(lp->cliN);
        free(lp->cliP);
        free(lp->key);

        lp->cliN = NULL;
        lp->cliP = NULL;
        lp->key = NULL;
      }

      free(gfil->fil[fil].tblc[i].list);
      free(gfil->fil[fil].tblp[i].list);

      gfil->fil[fil].tblc[i].list = NULL;
      gfil->fil[fil].tblp[i].list = NULL;
    }
    free(gfil->fil[fil].tblc);
    free(gfil->fil[fil].tblp);

    gfil->fil[fil].tblc = NULL;
    gfil->fil[fil].tblp = NULL;
  }

  free(gfil);
  gfil = NULL;
}

/**
 * @brief         Função retorna o tamanho da array cliN e cliP da estrutura ListP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @return        Inteiro com o tamanho
 */
int getGFilPSizeP(GFiliais* gfil, int branch, int i, int j) {
  return gfil->fil[branch].tblp[i].list[j].sizeP;
}

/**
 * @brief         Função retorna o tamanho da array cliP da estrutura ListP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @return        Inteiro com o tamanho
 */
int getGFilPSizeC(GFiliais* gfil, int branch, int i, int j) {
  return gfil->fil[branch].tblp[i].list[j].sizeC;
}

/**
 * @brief         Função retorna o tamanho da array cliN da estrutura ListP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @return        Inteiro com o tamanho
 */
int getGFilPSizeN(GFiliais* gfil, int branch, int i, int j) {
  return gfil->fil[branch].tblp[i].list[j].sizeN;
}

/**
 * @brief         Função retorna o cliente da array cliP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @param k       Posição no array cliP
 * @return        String com o cliente
 */
char* getGFilPCliP(GFiliais* gfil, int branch, int i, int j, int k) {
  return gfil->fil[branch].tblp[i].list[j].cliP[k];
}

/**
 * @brief         Função retorna o cliente da array cliN
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @param k       Posição no array cliN
 * @return        String com o cliente
 */
char* getGFilPCliN(GFiliais* gfil, int branch, int i, int j, int k) {
  return gfil->fil[branch].tblp[i].list[j].cliN[k];
}

/**
 * @brief         Função retorna o endereço da estrutura ListP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @return        Apontador para estrutura ListP
 */
ListP* getGFilPList(GFiliais* gfil, int branch, int i, int j) {
  return &(gfil->fil[branch].tblp[i].list[j]);
}

/**
 * @brief         Função retorna o tamanho do array de ListP
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @return        Inteiro com o tamanho
 */
int getGFilPListSize(GFiliais* gfil, int branch, int i) {
  return gfil->fil[branch].tblp[i].sizeProd;
}

/**
 * @brief         Função retorna o endereço da estrutura ListC
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblp
 * @param j       Posição no array list
 * @return        Apontador para estrutura ListC
 */
ListC* getGFilCList(GFiliais* gfil, int branch, int i, int j) {
  return &(gfil->fil[branch].tblc[i].list[j]);
}

/**
 * @brief         Função retorna o tamanho do array de ListC
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblc
 * @return        Inteiro com o tamanho
 */
int getGFilCListSize(GFiliais* gfil, int branch, int i) {
  return gfil->fil[branch].tblc[i].sizeCli;
}

/**
 * @brief         Função retorna produto da estrutura ProdCli
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblc
 * @param j       Posição no array list
 * @param k       Posição no array prods
 * @return        String com o produto
 */
char* getGFilCprod(GFiliais*gfil,int branch,int i,int j,int k) {
  return gfil->fil[branch].tblc[i].list[j].prods[k].prod;
}

/**
 * @brief         Função retorna unidades da estrutura ProdCli
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblc
 * @param j       Posição no array list
 * @param k       Posição no array prods
 * @param m       Posição no array uni
 * @return        Inteiro com a unidade
 */
int getGFilCuni(GFiliais*gfil,int branch,int i,int j,int k,int m) {
  return gfil->fil[branch].tblc[i].list[j].prods[k].uni[m];
}

/**
 * @brief         Função retorna faturação da estrutura ProdCli
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblc
 * @param j       Posição no array list
 * @param k       Posição no array prods
 * @return        Float com a faturação
 */
float getGFilCfat(GFiliais*gfil,int branch,int i,int j,int k) {
  return gfil->fil[branch].tblc[i].list[j].prods[k].fat;
}

/**
 * @brief         Função retorna tamanho do array de ProdCli
 * @param gfil    Apontador para GFiliais
 * @param branch  Posição no array fil
 * @param i       Posição no array tblc
 * @param j       Posição no array list
 * @return        Inteiro com o tamanho
 */
int getGFilCsizeProds(GFiliais*gfil,int branch,int i,int j) {
  return gfil->fil[branch].tblc[i].list[j].sizeProds;
}
