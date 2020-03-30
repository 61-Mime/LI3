#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "querie.h"

// Querie 2
void getProductsStartedByLetter(SGV sgv, char letter) {
    int i, hash = hashP(letter);

    for(i=0; i<sgv->prod->tbl[hash].size; i++)
        printf("%s\n", sgv->prod->tbl[hash].list[i]);

    printf("Produtos começados por %c: %d\n", letter, sgv->prod->tbl[hash].size);
}

// Querie 3

// Querie 4

// Querie 5

// Querie 6
/*
void getClientsAndProductsNeverBoughtCount(SGV sgv) {
    int prod = sgv->prod->sizet - sgv->sales->comprados;
    int cli = sgv->cli->sizet - sgv->sales->compradores;

    printf("Produtos não comprados: %d\n", prod);
    printf("Clientes não compradores: %d\n", cli);
}
*/
// Querie 7
void getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, k, hash, pos, mes;
    int prods[12];

    hash = hashC(clientID[0]);
    pos = searchCli(clientID, sgv->cli);

    if(pos==(-1)) {
        printf("O código de Cliente não é valido\n");
        return;
    }

    for(k=1; k<4; k++) {
        printf("Filial %d\n", k);

        for(i=0; i<12; i++)
            prods[i] = 0;

        for(i=0; i<sgv->sales->tblc[hash+(k-1)*26].list[pos].size3; i++) {
            mes = sgv->sales->tblc[hash+(k-1)*26].list[pos].venda[i].month;
            prods[mes-1] += sgv->sales->tblc[hash+(k-1)*26].list[pos].venda[i].uni;
        }

        for(i=0; i<12; i++)
            printf("Mes %d: %d\n", (i+1), prods[i]);

        printf("\n");
    }
}

// Querie 8
void getSalesAndProfit(SGV sgv,int minMonth,int maxMonth) {
  int n = 0,i,i2,i3,i4;
  float total = 0.0;
  if(minMonth < 1 || maxMonth>12) {
    printf("Mês inválido\n");
    return;
  }

  for(i = 0;i < 26;i++)
    for(i2 = 0;i2 < sgv->fact->tbl[i].size;i2++)
      for(i3 = minMonth-1;i3 < maxMonth;i3++)
        for(i4 = 0;i4 < 3;i4++) {
          n += sgv->fact->tbl[i].list[i2].mesfilial[i3][i4].vendasN +
               sgv->fact->tbl[i].list[i2].mesfilial[i3][i4].vendasP;
          total += sgv->fact->tbl[i].list[i2].mesfilial[i3][i4].facturacaoP +
                   sgv->fact->tbl[i].list[i2].mesfilial[i3][i4].facturacaoN;
          if(total < 0) {printf("%d %d %d\n", i,i2,i3);return;}
        }

  printf("Total vendas:%d\nTotal faturado:%f", n,total);
}
/*
// Querie 9
void quickSortS2(Sale *sale, int low, int high)
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

void getProductBuyers(SGV sgv,char *prodID,int branch)
{
  int pos = searchProd(prodID, sgv->prod),n = 0,j,r = 1;
  if(pos != -1) {
    int hash = hashP(prodID[0]) + 26*(branch - 1);
    Sale *s = NULL;
    s = realloc(s, sizeof(Sale) * (sgv->sales->tblp[hash].list[pos].size3));

    for(int i = 0;i < sgv->sales->tblp[hash].list[pos].size3;i++) {
      s[i] = sgv->sales->tblp[hash].list[pos].venda[i];
    }

    quickSortS2(s,0,sgv->sales->tblp[hash].list[pos].size3 - 1);

    for(int i = 0;i < sgv->sales->tblp[hash].list[pos].size3;i++) {
      if(i > 0 && strcmp(s[i].c,s[i - 1].c) == 0) {
        for(j = i - 1;i >= 0 && !strcmp(s[i].c,s[j].c) && r;j--)
          if(s[j].type[0] == s[j + 1].type[0])
            r = 0;

        if(r)
          printf("Cliente:%s Tipo de compra:%s\n", s[i].c,s[i].type);
      }
      else {
        n++;
        printf("Cliente:%s Tipo de compra:%s\n", s[i].c,s[i].type);
      }
      r = 1;
    }
    printf("Total clientes %d\n", n);
  }
}
*/
// Querie 10

// Querie 11

// Querie 12

// Querie 13
