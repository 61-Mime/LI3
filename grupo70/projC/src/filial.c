#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"

#define SIZE 26

TblFil* initFil() {
  TblFil* fil = malloc(sizeof(TblFil));

  fil->size1 = 0;

  for(int i=0; i<SIZE; i++) {
    fil->tblc[i].list = NULL;
    fil->tblc[i].size2 = 0;

    fil->tblp[i].list = NULL;
    fil->tblp[i].size2 = 0;
  }

  return fil;
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

void swapS(Sale *a, Sale *b)
{
    Sale aux = *a;
    *a = *b;
    *b = aux;
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