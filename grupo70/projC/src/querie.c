#include "querie.h"

#define SMAX 10

// Querie 2
Q2* getProductsStartedByLetter(SGV sgv, char letter) {
  int i, hash;
  Q2* querie2 = malloc(sizeof(Q2));

  hash = hashP(letter);

  querie2->size = sgv->prod->tbl[hash].size;
  querie2->prods = malloc(sizeof(char*)*querie2->size);

  for(i=0; i<querie2->size; i++) {
    querie2->prods[i] = malloc(sizeof(char)*SMAX);
    strcpy(querie2->prods[i],sgv->prod->tbl[hash].list[i]);
  }

  return querie2;
}

// Querie 3
Q3* getProductSalesAndProfit(SGV sgv, char* productID, int month, int type) {
  int i, pos, hash;
  Q3* querie3 = malloc(sizeof(Q3));

  hash=hashP(productID[0]);
  pos=searchProd(productID, sgv->prod);

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


// Querie 5

// Querie 6
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv) {
    Q6* querie6 = malloc(sizeof(Q6));
    
    querie6->nProd = sgv->fact->prodNaoComprado;
    querie6->nCli = sgv->fact->cliNaoComprador;

    return querie6;
}

// Querie 7
Q7* getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, k, hash, pos;
    Q7* querie7 = malloc(sizeof(Q7));
    ListC *l;

    hash = hashC(clientID[0]);
    pos = searchCli(clientID, sgv->cli);

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
/*
void getProductBuyers(SGV sgv,char *prodID,int branch)
{
  int pos = searchProd(prodID, sgv->prod),n,r,c,i;
  if(pos != -1) {
    ListP *prod;
    int hash = hashP(prodID[0]);
    Q9 l = malloc(sizeof(Q9));
    l->total = 0;
    l->lista = NULL;

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
        l->lista = realloc(l->lista,sizeof(Cl)*(l->total+1));
        l->lista[l->total].tipocompra = 1;
        strcpy(l->lista[l->total].cliente,prod->cliN[i]);
        l->total++;
      }

    c = l->total;
    for(i = 0;i < prod->sizeP;i++) {
      for(n = 0;n < c && r < 0;n++) {
        r = strcmp(prod->cliP[i],l->lista[n].cliente);
        if(n == 0) {
          l->lista[n].tipocompra = 3;
        }
      }
      if(!r && (!i || strcmp(prod->cliN[i],prod->cliN[i-1]))) {
        l->lista = realloc(l->lista,sizeof(Cl)*(l->total+1));
        l->lista[l->total].tipocompra = 2;
        strcpy(l->lista[l->total].cliente,prod->cliN[i]);
        l->total++;
      }
    }

    for(i = 0;i < l->total;i++)
        printf("cliente:%s Tipo compra:%d\n",l->lista[i].cliente,l->lista[i].tipocompra);
    printf("Total:%d\n", l->total);
  }
}
*/
// Querie 10

// Querie 11

// Querie 12

// Querie 13
Q13* getCurrentFilesInfo(SGV sgv) {
    Q13* querie13 = malloc(sizeof(Q13));

    querie13->cliL = sgv->cli->nLidas;
    querie13->cliV = sgv->cli->nValidas;
    querie13->prodL = sgv->prod->nLidas;
    querie13->prodV = sgv->prod->nValidas;
    querie13->salesL = sgv->sales->nLidas;
    querie13->salesV = sgv->sales->nValidas;

    return querie13;
}