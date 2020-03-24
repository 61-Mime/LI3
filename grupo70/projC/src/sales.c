#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sales.h"

#define MAX 64
#define SIZEP 676
#define SIZEC 26

void swapS(Sale* a, Sale* b)
{
    void* aux = a;
    a = b;
    b = aux;
}

void quickSortByCli(Sale* list, int low, int high)
{
    if (low < high)
    {
      char* pivot = list[high].c;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(list[j].c, pivot) < 0)
          {
              i++;
              swapS(&list[i], &list[j]);
          }
      }
      swapS(&list[i + 1], &list[high]);

      int pi = i + 1;

      quickSortByCli(list, low, pi - 1);
      quickSortByCli(list, pi + 1, high);
    }
}

void quickSortByProd(Sale* list, int low, int high)
{
    if (low < high)
    {
      char* pivot = list[high].p;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(list[j].p, pivot) < 0)
          {
              i++;
              swapS(&list[i], &list[j]);
          }
      }
      swapS(&list[i + 1], &list[high]);

      int pi = i + 1;

      quickSortByProd(list, low, pi - 1);
      quickSortByProd(list, pi + 1, high);
    }
}

void initSales(THashSales* sales)
{
  int i;

  sales = malloc(sizeof(THashSales));
  sales->sizet = 0;

  for(i=0; i<SIZEP; i++) {
    sales->tblp[i].size = 0;
    sales->tblp[i].list = NULL;
  }

  for(i=0; i<SIZEC; i++) {
    sales->tblc[i].size = 0;
    sales->tblc[i].list = NULL;
  }
}

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(THashSales* sales, char* buffer, THashP* tprod, THashC* tcli)
{
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, pos;
  int uni, month, branch;
  float price;

  aux = strsep(&buffer, " ");
  prod = aux;
  hashp = hashP(aux[0], aux[1]);

  aux = strsep(&buffer, " ");
  price = atof(aux);

  aux = strsep(&buffer, " ");
  uni = atoi(aux);

  aux = strsep(&buffer, " ");
  type = aux;

  aux = strsep(&buffer, " ");
  cli = aux;
  hashc = hashC(aux[0]);

  aux = strsep(&buffer, " ");
  month = atoi(aux);

  aux = strsep(&buffer, " ");
  branch = atoi(aux);

  if((binarySearch(tprod->tbl[hashp].list, prod, 0, tprod->tbl[hashp].size-1)!=(-1))
  &&(binarySearch(tcli->tbl[hashc].list, cli, 0, tcli->tbl[hashc].size-1)!=(-1)))
  {
    pos = sales->tblp[hashp].size;

    sales->tblp[hashp].list = realloc(sales->tblp[hashp].list ,sizeof(Sale) * (pos + 1));
    sales->tblp[hashp].list[pos].p = prod;
    sales->tblp[hashp].list[pos].price = price;
    sales->tblp[hashp].list[pos].uni = uni;
    sales->tblp[hashp].list[pos].type = type;
    sales->tblp[hashp].list[pos].c = cli;
    sales->tblp[hashp].list[pos].month = month;
    sales->tblp[hashp].list[pos].branch = branch;
    sales->tblp[hashp].size++;

    pos = sales->tblc[hashc].size;

    sales->tblc[hashc].list = realloc(sales->tblc[hashc].list ,sizeof(Sale) * (pos + 1));
    sales->tblc[hashc].list[pos].p = prod;
    sales->tblc[hashc].list[pos].price = price;
    sales->tblc[hashc].list[pos].uni = uni;
    sales->tblc[hashc].list[pos].type = type;
    sales->tblc[hashc].list[pos].c = cli;
    sales->tblc[hashc].list[pos].month = month;
    sales->tblc[hashc].list[pos].branch = branch;
    sales->tblc[hashc].size++;

    sales->sizet++;
  }
}

// Abre o array das vendas e passa-as para uma struct
int tblSales(THashSales* sales, THashP* tprod, THashC* tcli) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);

  if((fsales = fopen("../files/Vendas_1M.txt", "r")) == NULL)
    return -1;
  
  initSales(sales);

  while(fgets(buffer,MAX,fsales)) {
    buffer = strsep(&buffer, "\r");
    saleS(sales, buffer, tprod, tcli);
  }

  fclose(fsales);  

  for(int i=0; i<SIZEP; i++)
    quickSortByProd(sales->tblp[i].list, 0, sales->tblp[i].size - 1);
  
  for(int i=0; i<SIZEC; i++)
    quickSortByCli(sales->tblc[i].list, 0, sales->tblc[i].size - 1);
    
   return 0;
}

void printSales(THashSales* sales) {
  int i,j;

  for(i=0; i<SIZEC; i++){
    for(j=0 ;j<sales->tblc[i].size; j++)
      printf("%s %f %d %s %s %d %d\r\n",
              sales->tblc[i].list[j].p,
              sales->tblc[i].list[j].price,
              sales->tblc[i].list[j].uni,
              sales->tblc[i].list[j].type,
              sales->tblc[i].list[j].c,
              sales->tblc[i].list[j].month,
              sales->tblc[i].list[j].branch);
  }

  printf("Vendas Válidas: %d\n", sales->sizet);
}

