#include "querie.h"

#define SMAX 10

// Querie 2
Q2* getProductsStartedByLetter(SGV sgv, char letter) {
  int i, hash;
  Q2* querie2 = malloc(sizeof(Q2));

  hash = hashCat(letter);

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

  if(type == 0) {
    querie3->size = 1;
    querie3->fat = malloc(sizeof(Q3fat));

    querie3->fat->fatN = 0;
    querie3->fat->fatP = 0;
    querie3->fat->nVendasN = 0;
    querie3->fat->nVendasP = 0;


    for(i=0; i<3; i++) {
      querie3->fat->fatN += sgv->fact->tbl[hash].list[pos].mesfilial[month][i].facturacaoN;
      querie3->fat->fatP += sgv->fact->tbl[hash].list[pos].mesfilial[month][i].facturacaoP;
      querie3->fat->nVendasN += sgv->fact->tbl[hash].list[pos].mesfilial[month][i].vendasN;
      querie3->fat->nVendasP += sgv->fact->tbl[hash].list[pos].mesfilial[month][i].vendasP;
    }
  }

  else {
    querie3->size = 3;
    querie3->fat = malloc(sizeof(Q3fat) * querie3->size);

    for(i=0; i<4; i++) {
      querie3->fat[i].fatN = sgv->fact->tbl[hash].list[pos].mesfilial[month][i].facturacaoN;
      querie3->fat[i].fatP = sgv->fact->tbl[hash].list[pos].mesfilial[month][i].facturacaoP;
      querie3->fat[i].nVendasN = sgv->fact->tbl[hash].list[pos].mesfilial[month][i].vendasN;
      querie3->fat[i].nVendasP = sgv->fact->tbl[hash].list[pos].mesfilial[month][i].vendasP;
    }
  }

  return querie3;
}

// Querie 4
Q4* getProductsNeverBough(SGV sgv,int branch) {
  int i,i2;
  Q4 *querie4 = malloc(sizeof(Q4));
  querie4->size = 0;
  querie4->prods = NULL;

  THashFilial *f;

  if(branch == 0) {
  ListP *p,*p2,*p3;
    for(i = 0;i < 26;i++)
      for(i2 = 0;i2 < sgv->gfil->fil1.tblp[i].sizeProd;i2++) {
        p = &sgv->gfil->fil1.tblp[i].list[i2];
        p2 = &sgv->gfil->fil2.tblp[i].list[i2];
        p3 = &sgv->gfil->fil3.tblp[i].list[i2];
        if(!p -> sizeN && !p -> sizeP && !p2 -> sizeN &&
           !p2 -> sizeP && !p3 -> sizeN && !p3 -> sizeP) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4 -> prods[querie4->size],p->key);
          querie4 -> size ++;
        }
      }
  }
  else {
    ListP *p;

    if(branch == 1)
      f = &sgv->gfil->fil1;
    else if(branch == 2)
      f = &sgv->gfil->fil2;
    else
      f = &sgv->gfil->fil3;

    for(i = 0;i < 26;i++)
      for(i2 = 0;i2 < f->tblp[i].sizeProd;i2++) {
        p = &f -> tblp[i].list[i2];
        if((p -> sizeN == 0) && (p -> sizeP == 0)) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4 -> prods[querie4->size],p->key);
          querie4 -> size ++;
        }
      }
  }
  return querie4;
}

// Querie 5
Q5* getClientsOfAllBranches(SGV sgv) {
    int i, j;
    Q5* querie5 = malloc(sizeof(Q5));
    ListC *p,*p2,*p3;

    querie5->cli = NULL;
    querie5->size = 0;

    for(i=0; i<26; i++)
      for(j=0; j<sgv->gfil->fil1.tblc[i].sizeCli; j++) {
        p = &sgv->gfil->fil1.tblc[i].list[j];
        p2 = &sgv->gfil->fil2.tblc[i].list[j];
        p3 = &sgv->gfil->fil3.tblc[i].list[j];

        if(p->sizeProds>0 && p2->sizeProds>0 && p3->sizeProds>0){
          querie5->cli = realloc(querie5->cli, sizeof(char*) * (querie5->size + 1));
          querie5->cli[querie5->size] = malloc(sizeof(char)*SMAX);
          strcpy(querie5->cli[querie5->size], p->key);
          querie5->size++;
        }
      }
    return querie5;
}

// Querie 6
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv) {
    Q6* querie6 = malloc(sizeof(Q6));

    //querie6->nProd = sgv->fact->prodNaoComprado;
    //querie6->nCli = sgv->fact->cliNaoComprador;

    return querie6;
}

// Querie 7
Q7* getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, k, hash, pos;
    Q7* querie7 = malloc(sizeof(Q7));
    ListC *l;

    hash = hashCat(clientID[0]);
    pos = searchCat(clientID, sgv->cli);

    for(i=0; i<12; i++)
      for(k=0; k<3; k++)
        querie7->tabela[i][k] = 0;

    for(i=0; i<12; i++) {
      l = &sgv->gfil->fil1.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        querie7->tabela[i][0] += l->prods[k].uni[i];

      l = &sgv->gfil->fil2.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        querie7->tabela[i][1] += l->prods[k].uni[i];

      l = &sgv->gfil->fil3.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        querie7->tabela[i][2] += l->prods[k].uni[i];
    }

    return querie7;
}

// Querie 8
Q8* getSalesAndProfit(SGV sgv,int minMonth,int maxMonth) {
  int i,i2,i3,i4;
  FMensal *f;
  Q8* querie8 = malloc(sizeof(Q8));

  querie8->vendas = 0;
  querie8->fact = 0.0;

  for(i = 0;i < 26;i++)
    for(i2 = 0;i2 < sgv->fact->tbl[i].size;i2++)
      for(i3 = minMonth-1;i3 < maxMonth;i3++)
        for(i4 = 0;i4 < 3;i4++) {
          f = &sgv->fact->tbl[i].list[i2].mesfilial[i3][i4];
          querie8->vendas += f->vendasN + f->vendasP;
          querie8->fact += f->facturacaoP + f->facturacaoN;
        }

  return querie8;
}

// Querie 9

Q9* getProductBuyers(SGV sgv,char *prodID,int branch) {
  int pos = searchCat(prodID, sgv->prod),n,r,c,i;
  Q9* querie9 = malloc(sizeof(Q9));

  if(pos != -1) {
    ListP *prod;
    int hash = hashCat(prodID[0]);
    querie9->total = 0;
    querie9->lista = NULL;

    if(branch == 1)
      prod = &sgv->gfil->fil1.tblp[hash].list[pos];
    else if(branch == 2)
      prod = &sgv->gfil->fil2.tblp[hash].list[pos];
    else
      prod = &sgv->gfil->fil3.tblp[hash].list[pos];

    quickSort(prod->cliN,0,prod->sizeN-1);
    quickSort(prod->cliP,0,prod->sizeP-1);

    for(i = 0;i < prod->sizeN;i++)
      if(i == 0 || strcmp(prod->cliN[i],prod->cliN[i-1])) {
        querie9->lista = realloc(querie9->lista,sizeof(Cl)*(querie9->total+1));
        querie9->lista[querie9->total].tipocompra = 1;
        strcpy(querie9->lista[querie9->total].cliente,prod->cliN[i]);
        querie9->total++;
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
printf("%d %d\n", hash,pos);
  if(hash == -1 || pos == -1) return NULL;

  ListC *l1,*l2,*l3;
  Q10 *querie10 = malloc(sizeof(Q10));
  querie10 -> size = 0;
  querie10 -> produtos = NULL;

  l1 = &sgv -> gfil -> fil1.tblc[hash].list[pos];
  l2 = &sgv -> gfil -> fil2.tblc[hash].list[pos];
  l3 = &sgv -> gfil -> fil3.tblc[hash].list[pos];

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
