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

void tblFil(THashSales *sales,TblFil *fil1,TblFil *fil2,TblFil *fil3) {
  int i,j,k;

  for(i = 0;i < SIZE;i++) {
    fil1->tblp[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
    fil1 ->tblp[i].size2 = sales->tblp[i].size2;
    fil2->tblp[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
    fil2 ->tblp[i].size2 = sales->tblp[i].size2;
    fil2->tblp[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
    fil3 ->tblp[i].size2 = sales->tblp[i].size2;

    for(j = 0;j < sales->tblp[i].size2;j++) {
      fil1->tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil1->tblp[i].list[j].key,sales->tblp[i].list[j].key);
      fil1->tblp[i].list[j].size3 = 0;

      fil2->tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil2->tblp[i].list[j].key,sales->tblp[i].list[j].key);
      fil2->tblp[i].list[j].size3 = 0;

      fil3->tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil3->tblp[i].list[j].key,sales->tblp[i].list[j].key);
      fil3->tblp[i].list[j].size3 = 0;

      for(k = 0;k < sales->tblp[i].list[j].size3;k++) {
        if(sales->tblp[i].list[j].venda[k].branch == 1) {
          fil1->tblp[i].list[j].venda = realloc(fil1->tblp[i].list[j].venda,sizeof(Venda) * (fil1->tblp[i].list[j].size3 + 1));
          fil1->tblp[i].list[j].size3++;
          preenchevenda(&fil1->tblp[i].list[j].venda[k],sales->tblp[i].list[j].venda[k]);
        }
        else if(sales->tblp[i].list[j].venda[k].branch == 2) {
          fil2->tblp[i].list[j].venda = realloc(fil2->tblp[i].list[j].venda,sizeof(Venda) * (fil2->tblp[i].list[j].size3 + 1));
          fil2->tblp[i].list[j].size3++;
          preenchevenda(&fil2->tblp[i].list[j].venda[k],sales->tblp[i].list[j].venda[k]);
        }
        else {
          fil3->tblp[i].list[j].venda = realloc(fil3->tblp[i].list[j].venda,sizeof(Venda) * (fil3->tblp[i].list[j].size3 + 1));
          fil3->tblp[i].list[j].size3++;
          preenchevenda(&fil3->tblp[i].list[j].venda[k],sales->tblp[i].list[j].venda[k]);
        }
      }

      fil1->tblc[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
      fil1 ->tblc[i].size2 = sales->tblc[i].size2;
      fil2->tblc[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
      fil2 ->tblp[i].size2 = sales->tblp[i].size2;
      fil2->tblc[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
      fil3 ->tblp[i].size2 = sales->tblp[i].size2;

      for(k = 0;k < sales->tblc[i].list[j].size3;k++) {
        if(sales->tblc[i].list[j].venda[k].branch == 1) {
          fil1->tblc[i].list[j].venda = realloc(fil1->tblc[i].list[j].venda,sizeof(Venda) * (fil1->tblc[i].list[j].size3 + 1));
          fil1->tblc[i].list[j].size3++;
          preenchevenda(&fil1->tblp[i].list[j].venda[k],sales->tblc[i].list[j].venda[k]);
        }
        else if(sales->tblc[i].list[j].venda[k].branch == 2) {
          fil2->tblc[i].list[j].venda = realloc(fil2->tblc[i].list[j].venda,sizeof(Venda) * (fil2->tblc[i].list[j].size3 + 1));
          fil2->tblc[i].list[j].size3++;
          preenchevenda(&fil2->tblp[i].list[j].venda[k],sales->tblc[i].list[j].venda[k]);
        }
        else {
          fil3->tblc[i].list[j].venda = realloc(fil3->tblc[i].list[j].venda,sizeof(Venda) * (fil3->tblc[i].list[j].size3 + 1));
          fil3->tblc[i].list[j].size3++;
          preenchevenda(&fil3->tblp[i].list[j].venda[k],sales->tblc[i].list[j].venda[k]);
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
        printf("%s %f %d %s %s %d %d\r\n",
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






























/*
void ProdCliComp(THashSales* sales,int hash,int pos,int tabela) {
  int p1,p2;
  if(hash < 26) {
    p1 = hash + 26; p2 = hash + 52;
  }
  else if(hash > 51) {
    p1 = hash - 26; p2 = hash - 52;
  }
  else {
    p1 = hash - 26; p2 = hash + 26;
  }

  if(!tabela && sales->tblp[p1].list[pos].venda == NULL &&
     sales->tblp[p2].list[pos].venda == NULL)
     sales -> comprados++;
  else if(tabela && sales->tblc[p1].list[pos].venda == NULL &&
          sales->tblc[p2].list[pos].venda == NULL)
          sales -> compradores++;
}



void quickSortS(Sale *sales, int low, int high)
{
    if (low < high)
    {
      int pivot = sales[high].month;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (sales[j].month < pivot)
          {
              i++;
              swapS(&sales[i], &sales[j]);
          }
      }
      swapS(&sales[i + 1], &sales[high]);

      int pi = i + 1;

      quickSortS(sales, low, pi - 1);
      quickSortS(sales, pi + 1, high);
    }
}
*/
