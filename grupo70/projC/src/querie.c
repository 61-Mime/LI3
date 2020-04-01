#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "querie.h"

// Querie 2
void getProductsStartedByLetter(SGV sgv, char letter) {
    int i, hash = hashP(letter);
    char **l = malloc(sizeof(char*)*sgv->prod->tbl[hash].size);

    for(i=0; i<sgv->prod->tbl[hash].size; i++) {
      l[i] = malloc(sizeof(char)*10);
      strcpy(l[i],sgv->prod->tbl[hash].list[i]);
    }

    for(i=0; i<sgv->prod->tbl[hash].size; i++)
      printf("%s\n",l[i]);

    printf("Produtos começados por %c: %d\n", letter, sgv->prod->tbl[hash].size);
}

// Querie 3

// Querie 4

// Querie 5

// Querie 6

void getClientsAndProductsNeverBoughtCount(SGV sgv) {
    int prod = sgv->fact->prodNaoComprado;
    int cli = sgv->fact->cliNaoComprador;

    printf("Produtos não comprados: %d\n", prod);
    printf("Clientes não compradores: %d\n", cli);
}


// Querie 7

void getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, k, hash, pos;
    int tabela[12][3];
    ListC *l;

    hash = hashC(clientID[0]);
    pos = searchCli(clientID, sgv->cli);

    if(pos==(-1)) {
        printf("O código de Cliente não é valido\n");
        return;
    }

    for(i=0; i<12; i++)
      for(k=0; k<3; k++)
        tabela[i][k] = 0;


    for(i=0; i<12; i++) {
      l = &sgv->gfil->fil1.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        tabela[i][0] += l->prods[k].uni[i];
      l = &sgv->gfil->fil2.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        tabela[i][1] += l->prods[k].uni[i];
      l = &sgv->gfil->fil3.tblc[hash].list[pos];
      for(k = 0;k < l->sizeProds;k++)
        tabela[i][2] += l->prods[k].uni[i];
    }

    printf("Filial  1   2   3\n" );
    for(i=0; i<12; i++)
        printf("Mes %d: %d   %d   %d\n", (i+1), tabela[i][0],tabela[i][1],tabela[i][2]);
}
/*
void swapS(Venda *a, Venda *b)
{
    Venda aux = *a;
    *a = *b;
    *b = aux;
}

void quickSortS2(Venda *sale, int low, int high)
{
    if (low < high)
    {
      char* pivot = sale[high].c;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(sale[j].c, pivot) < 0)
          {
              i++;
              swapS(&sale[i], &sale[j]);
          }
      }
      swapS(&sale[i+1], &sale[high]);

      int pi = i + 1;

      quickSortS2(sale, low, pi - 1);
      quickSortS2(sale, pi + 1, high);
    }
}
*/
// Querie 8
void getSalesAndProfit(SGV sgv,int minMonth,int maxMonth) {
  int n = 0,i,i2,i3,i4;
  float total = 0.0;
  if(minMonth < 1 || maxMonth>12) {
    printf("Mês inválido\n");
    return;
  }
  FMensal *f;

  for(i = 0;i < 26;i++)
    for(i2 = 0;i2 < sgv->fact->tbl[i].size;i2++)
      for(i3 = minMonth-1;i3 < maxMonth;i3++)
        for(i4 = 0;i4 < 3;i4++) {
          f = &sgv->fact->tbl[i].list[i2].mesfilial[i3][i4];
          n += f -> vendasN +
               f -> vendasP;
          total += f -> facturacaoP +
                   f -> facturacaoN;
          if(total < 0) {printf("%d %d %d\n", i,i2,i3);return;}
        }

  printf("Total vendas:%d\nTotal faturado:%f", n,total);
}

// Querie 9

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
// Querie 10

// Querie 11

// Querie 12

// Querie 13
