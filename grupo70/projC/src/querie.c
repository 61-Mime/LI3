#include "querie.h"

#define SIZE 26
#define SMAX 10

// Querie 2
Q2* getProductsStartedByLetter(SGV sgv, char letter) {
  int i, hash;
  Q2* querie2 = malloc(sizeof(Q2));

  hash = hashCat(letter);

  if(hash == -1)
    return NULL;

  querie2->size = getCatListSize(sgv->prod, hash);
  querie2->prods = malloc(sizeof(char*)*querie2->size);

  for(i=0; i<querie2->size; i++) {
    querie2->prods[i] = malloc(sizeof(char)*SMAX);
    strcpy(querie2->prods[i], getCatKey(sgv->prod, hash, i));
  }

  return querie2;
}

// Querie 3
Q3* getProductSalesAndProfit(SGV sgv, char* productID, int month, int type) {
  int i, pos, hash;
  Q3* querie3 = malloc(sizeof(Q3));

  hash=hashCat(productID[0]);
  pos=searchCat(productID, sgv->prod);

  if(hash == -1 || pos == -1)
    return NULL;

  if(type == 0) {
    querie3->size = 1;
    querie3->fat = malloc(sizeof(Q3fat));

    querie3->fat->fatN = 0;
    querie3->fat->fatP = 0;
    querie3->fat->nVendasN = 0;
    querie3->fat->nVendasP = 0;


    for(i=0; i<3; i++) {
      querie3->fat->fatN += getFatFaturacaoN(sgv->fact,hash,pos,month-1,i);
      querie3->fat->fatP += getFatFaturacaoP(sgv->fact,hash,pos,month-1,i);
      querie3->fat->nVendasN += getFatVendasN(sgv->fact,hash,pos,month-1,i);
      querie3->fat->nVendasP += getFatVendasP(sgv->fact,hash,pos,month-1,i);
    }
  }

  else {
    querie3->size = 3;
    querie3->fat = malloc(sizeof(Q3fat) * querie3->size);

    for(i=0; i<3; i++) {
      querie3->fat[i].fatN = getFatFaturacaoN(sgv->fact,hash,pos,month-1,i);
      querie3->fat[i].fatP = getFatFaturacaoP(sgv->fact,hash,pos,month-1,i);
      querie3->fat[i].nVendasN = getFatVendasN(sgv->fact,hash,pos,month-1,i);
      querie3->fat[i].nVendasP = getFatVendasP(sgv->fact,hash,pos,month-1,i);
    }
  }

  return querie3;
}

// Querie 4
Q4* getProductsNeverBough(SGV sgv,int branch) {
  int i,i2, size;

  Q4 *querie4 = malloc(sizeof(Q4));
  querie4->size = 0;
  querie4->prods = NULL;

  if(branch == 0)
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < getGFilPListSize(sgv->gfil,0,i);i2++) {
        size = getGFilPSizeN(sgv->gfil, 0, i, i2) + getGFilPSizeP(sgv->gfil, 0, i, i2) +
               getGFilPSizeN(sgv->gfil, 1, i, i2) + getGFilPSizeP(sgv->gfil, 1, i, i2) +
               getGFilPSizeN(sgv->gfil, 2, i, i2) + getGFilPSizeP(sgv->gfil, 2, i, i2);
        if(size == 0) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4->prods[querie4->size], getCatKey(sgv->prod, i, i2));
          querie4->size++;
        }
      }

  else {
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < getGFilPListSize(sgv->gfil,branch-1,i);i2++) {
        size = getGFilPSizeN(sgv->gfil, branch-1, i, i2) + getGFilPSizeP(sgv->gfil, branch-1, i, i2);
        if(size == 0) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4->prods[querie4->size], getCatKey(sgv->prod, i, i2));
          querie4->size++;
        }
      }
  }
  return querie4;
}

// Querie 5
Q5* getClientsOfAllBranches(SGV sgv) {
    int i, j, size1, size2, size3;
    Q5* querie5 = malloc(sizeof(Q5));

    querie5->cli = NULL;
    querie5->size = 0;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getGFilCListSize(sgv->gfil,0,i); j++) {
        size1 = getGFilCsizeProds(sgv->gfil, 0, i, j);
        size2 = getGFilCsizeProds(sgv->gfil, 1, i, j);
        size3 = getGFilCsizeProds(sgv->gfil, 2, i, j);

        if(size1>0 && size2>0 && size3>0){
          querie5->cli = realloc(querie5->cli, sizeof(char*) * (querie5->size + 1));
          querie5->cli[querie5->size] = malloc(sizeof(char)*SMAX);
          strcpy(querie5->cli[querie5->size], getCatKey(sgv->prod, i, j));
          querie5->size++;
        }
      }
    return querie5;
}

// Querie 6
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv) {
    int i, j, k, l, size;
    Q6* querie6 = malloc(sizeof(Q6));

    querie6->nCli = 0;
    querie6->nProd = 0;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getGFilCListSize(sgv->gfil, 0, i); j++)
        if(getGFilCsizeProds(sgv->gfil, 0, i, j)==0 &&
           getGFilCsizeProds(sgv->gfil, 1, i, j)==0 &&
           getGFilCsizeProds(sgv->gfil, 2, i, j)==0)
           querie6->nCli++;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getFatListSize(sgv->fact, i); j++) {
        size = 0;
        for(k=0; k<12; k++) {
          for(l=0; l<3; l++) {
            size += getFatVendasN(sgv->fact, i, j, k, l)
                  + getFatVendasP(sgv->fact, i, j, k, l);
          }
        }
        if(size == 0)
          querie6->nProd++;
      }

    return querie6;
}

// Querie 7
Q7* getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, j, k, hash, pos;
    Q7* querie7 = malloc(sizeof(Q7));

    hash = hashCat(clientID[0]);
    pos = searchCat(clientID, sgv->cli);

    if(hash == -1 || pos == -1)
      return NULL;

    for(i=0; i<12; i++)
      for(j=0; j<3; j++)
        querie7->tabela[i][j] = 0;

    for(i=0; i<12; i++)
      for(j=0; j<3; j++)
        for(k=0; k<getGFilCsizeProds(sgv->gfil, j, i, k); k++)
          querie7->tabela[i][j] += getGFilCuni(sgv->gfil, j, hash, pos, k, i);

    return querie7;
}

// Querie 8
Q8* getSalesAndProfit(SGV sgv,int minMonth,int maxMonth) {
  int i,i2,i3,i4;
  Q8* querie8 = malloc(sizeof(Q8));

  querie8->vendas = 0;
  querie8->fact = 0.0;

  for(i = 0;i < SIZE;i++)
    for(i2 = 0;i2 < getFatListSize(sgv -> fact,i);i2++)
      for(i3 = minMonth-1;i3 < maxMonth;i3++)
        for(i4 = 0;i4 < 3;i4++) {
          querie8->vendas += getFatVendasN(sgv->fact,i,i2,i3,i4) +
                             getFatVendasP(sgv->fact,i,i2,i3,i4);
          querie8->fact += getFatFaturacaoN(sgv->fact,i,i2,i3,i4) +
                           getFatFaturacaoP(sgv->fact,i,i2,i3,i4);
        }

  return querie8;
}

// Querie 9

Q9* getProductBuyers(SGV sgv,char *prodID,int branch) {
    int pos, hash, n, r, c, i;
    char *cliN = NULL, *cliN1 = NULL;
    Q9* querie9 = malloc(sizeof(Q9));

    hash = hashCat(prodID[0]);
    pos = searchCat(prodID, sgv->prod);

    if(hash == -1 || pos == -1)
      return NULL;

    ListP *prod;
    querie9->total = 0;
    querie9->lista = NULL;

    prod = getGFilPList(sgv->gfil, branch-1, hash, pos);

    quickSort(prod->cliN,0,prod->sizeN-1);
    quickSort(prod->cliP,0,prod->sizeP-1);


    for(i = 0;i < prod->sizeN;i++) {
      cliN = getGFilPCliN(sgv->gfil, branch-1, hash, pos, i);
      cliN1 = getGFilPCliN(sgv->gfil, branch-1, hash, pos, i-1);
      if(i == 0 || strcmp(cliN, cliN1)) {
        querie9->lista = realloc(querie9->lista,sizeof(Cl)*(querie9->total+1));
        querie9->lista[querie9->total].tipocompra = 1;
        strcpy(querie9->lista[querie9->total].cliente, prod->cliN[i]);
        querie9->total++;
      }
    }

    c = querie9->total;
    for(i = 0;i < prod->sizeP;i++) {
      for(n = 0;n < c && r < 0;n++) {
        r = strcmp(prod->cliP[i],querie9->lista[n].cliente);
        if(n == 0) {
          querie9->lista[n].tipocompra = 3;
        }
      }
      if(!r && (!i || strcmp(prod->cliN[i],prod->cliN[i-1]))) {
        querie9->lista = realloc(querie9->lista,sizeof(Cl)*(querie9->total+1));
        querie9->lista[querie9->total].tipocompra = 2;
        strcpy(querie9->lista[querie9->total].cliente,prod->cliN[i]);
        querie9->total++;
      }
    }

    return querie9;
}

// Querie 10
void swapP(P *a, P *b)
{
    P aux = *a;
    *a = *b;
    *b = aux;
}

void quickSortbyP(P *prods, int low, int high)
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
              swapP(&prods[i], &prods[j]);
          }
      }
      swapP(&prods[i + 1], &prods[high]);

      int pi = i + 1;

      quickSortbyP(prods, low, pi - 1);
      quickSortbyP(prods, pi + 1, high);
    }
}

void quickSortbyQP(P *prods, int low, int high)
{
    if (low < high)
    {
      int pivot = prods[high].quantidade;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (prods[j].quantidade > pivot)
          {
              i++;
              swapP(&prods[i], &prods[j]);
          }
      }
      swapP(&prods[i + 1], &prods[high]);

      int pi = i + 1;

      quickSortbyQP(prods, low, pi - 1);
      quickSortbyQP(prods, pi + 1, high);
    }
}

Q10* getClientFavouriteProducts(SGV sgv,char *cliID,int month) {
  int pos = searchCat(cliID, sgv->cli),hash = hashCat(cliID[0]),i,i2,r,c;

  if(hash == -1 || pos == -1)
    return NULL;

  ListC *l1,*l2,*l3;
  Q10 *querie10 = malloc(sizeof(Q10));
  querie10 -> size = 0;
  querie10 -> produtos = NULL;

  l1 = &sgv -> gfil -> fil[0].tblc[hash].list[pos];
  l2 = &sgv -> gfil -> fil[1].tblc[hash].list[pos];
  l3 = &sgv -> gfil -> fil[2].tblc[hash].list[pos];

  querie10 -> size = l1->sizeProds + l2->sizeProds + l3->sizeProds;
  querie10 -> produtos = malloc(sizeof(P)*querie10->size);

  for(i = 0;i < l1->sizeProds;i++) {
    querie10 -> produtos[i].quantidade = l1 -> prods[i].uni[month - 1];
    strcpy(querie10 -> produtos[i].prod,l1 -> prods[i].prod);
  }

  for(i2 = 0;i2 <l2->sizeProds;i2++,i++) {
    querie10 -> produtos[i].quantidade = l2 -> prods[i2].uni[month - 1];
    strcpy(querie10 -> produtos[i].prod,l2 -> prods[i2].prod);
  }
  for(i2 = 0;i2 < l3->sizeProds;i++,i2++) {
    querie10 -> produtos[i].quantidade = l3 -> prods[i2].uni[month - 1];
    strcpy(querie10 -> produtos[i].prod,l3 -> prods[i2].prod);
  }

  quickSortbyP(querie10->produtos,0,querie10->size - 1);

  for(i = 0,r = 1,c = 1;c < querie10 -> size;i++) {
    for(i2 = c,r = 1;r;i2++,i2++){
      if(!strcmp(querie10->produtos[i2].prod,querie10->produtos[i].prod))
        querie10->produtos[i].quantidade += querie10->produtos[i2].quantidade;
      else r = 0;
    }
    if(i2 != c)
      swapP(&querie10->produtos[i + 1],&querie10->produtos[i2]);
    c = i2;
  }
  querie10 -> size = i;

  quickSortbyQP(querie10->produtos,0,querie10->size - 1);

  return querie10;
}
// Querie 11

// Querie 12
void swapPF(PF *a, PF *b)
{
    PF aux = *a;
    *a = *b;
    *b = aux;
}

void quickSortbyPF(PF *prods, int low, int high)
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
              swapPF(&prods[i], &prods[j]);
          }
      }
      swapPF(&prods[i + 1], &prods[high]);

      int pi = i + 1;

      quickSortbyPF(prods, low, pi - 1);
      quickSortbyPF(prods, pi + 1, high);
    }
}

void quickSortbyFP(PF *prods, int low, int high)
{
    if (low < high)
    {
      float pivot = prods[high].faturacao;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (prods[j].faturacao > pivot)
          {
              i++;
              swapPF(&prods[i], &prods[j]);
          }
      }
      swapPF(&prods[i + 1], &prods[high]);

      int pi = i + 1;

      quickSortbyFP(prods, low, pi - 1);
      quickSortbyFP(prods, pi + 1, high);
    }
}

Q12* getClientTopProfitProducts(SGV sgv, char* clientID, int limit) {
  int pos = searchCat(clientID, sgv->cli),hash = hashCat(clientID[0]),i,i2,r,c;

  if(hash == -1 || pos == -1)
    return NULL;

  ListC *l1,*l2,*l3;
  Q12 *querie12 = malloc(sizeof(Q12));
  querie12 -> size = 0;
  querie12 -> prods = NULL;

  l1 = getGFilCList(sgv->gfil, 0, hash, pos);
  l2 = getGFilCList(sgv->gfil, 1, hash, pos);
  l3 = getGFilCList(sgv->gfil, 2, hash, pos);

  querie12 -> size = l1->sizeProds + l2->sizeProds + l3->sizeProds;
  querie12 -> prods = malloc(sizeof(PF)*querie12->size);

  for(i = 0;i < l1->sizeProds;i++) {
    querie12 -> prods[i].faturacao = l1 -> prods[i].fat;
    strcpy(querie12 -> prods[i].prod,l1 -> prods[i].prod);
  }

  for(i2 = 0;i2 <l2->sizeProds;i2++,i++) {
    querie12 -> prods[i].faturacao = l2 -> prods[i2].fat;
    strcpy(querie12 -> prods[i].prod,l2 -> prods[i2].prod);
  }
  for(i2 = 0;i2 < l3->sizeProds;i++,i2++) {
    querie12 -> prods[i].faturacao = l3 -> prods[i2].fat;
    strcpy(querie12 -> prods[i].prod,l3 -> prods[i2].prod);
  }

  quickSortbyPF(querie12->prods,0,querie12->size - 1);

  for(i = 0,r = 1,c = 1;c < querie12 -> size;i++) {
    for(i2 = c,r = 1;r;i2++,i2++){
      if(!strcmp(querie12->prods[i2].prod,querie12->prods[i].prod))
        querie12->prods[i].faturacao += querie12->prods[i2].faturacao;
      else r = 0;
    }
    if(i2 != c)
      swapPF(&querie12->prods[i + 1],&querie12->prods[i2]);
    c = i2;
  }
  querie12 -> size = i;

  quickSortbyFP(querie12->prods,0,querie12->size - 1);

  if(limit < i) querie12->size = limit;

  return querie12;
}

// Querie 13
Q13* getCurrentFilesInfo(SGV sgv) {
    Q13* querie13 = malloc(sizeof(Q13));

    querie13->cliL = getCatLinhaLida(sgv->cli);
    querie13->cliV = getCatLinhaVal(sgv->cli);
    querie13->prodL = getCatLinhaLida(sgv->prod);
    querie13->prodV = getCatLinhaVal(sgv->prod);
    //querie13->salesL = sgv->sales->nLidas;
    //querie13->salesV = sgv->sales->nValidas;

    return querie13;
}
