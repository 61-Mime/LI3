#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sales.h"

#define SMAX 10
#define MAX 64
#define SIZEP 676
#define SIZEC 26

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(THashSales* sales, char* buffer, THashP* tprod, THashC* tcli)
{
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, posp, posc, size;
  int uni, month, branch;
  float price;

  aux = strsep(&buffer, " ");
  prod = aux;

  aux = strsep(&buffer, " ");
  price = atof(aux);

  aux = strsep(&buffer, " ");
  uni = atoi(aux);

  aux = strsep(&buffer, " ");
  type = aux;

  aux = strsep(&buffer, " ");
  cli = aux;

  aux = strsep(&buffer, " ");
  month = atoi(aux);

  aux = strsep(&buffer, " ");
  branch = atoi(aux);

  hashc = hashC(aux[0]);
  hashp = hashP(aux[0], aux[1]);

  posp = searchProd(prod, tprod);
  posc = searchCli(cli, tcli);

  if(posp!=(-1) && posc!=(-1))
  {
    size = sales->tblp[hashp].list[posp].size3;

    sales->tblp[hashp].list[posp].venda = realloc(sales->tblp[hashp].list[posp].venda, sizeof(Sale) * (size + 1));
    sales->tblp[hashp].list[posp].venda[size].p = prod;
    sales->tblp[hashp].list[posp].venda[size].price = price;
    sales->tblp[hashp].list[posp].venda[size].uni = uni;
    sales->tblp[hashp].list[posp].venda[size].type = type;
    sales->tblp[hashp].list[posp].venda[size].c = cli;
    sales->tblp[hashp].list[posp].venda[size].month = month;
    sales->tblp[hashp].list[posp].venda[size].branch = branch;
    sales->tblp[hashp].list[posp].size3++;

    size = sales->tblc[hashp].list[posc].size3;

    sales->tblc[hashc].list[posc].venda = realloc(sales->tblc[hashc].list[posc].venda ,sizeof(Sale) * (size + 1));
    sales->tblc[hashc].list[posc].venda[size].p = prod;
    sales->tblc[hashc].list[posc].venda[size].price = price;
    sales->tblc[hashc].list[posc].venda[size].uni = uni;
    sales->tblc[hashc].list[posc].venda[size].type = type;
    sales->tblc[hashc].list[posc].venda[size].c = cli;
    sales->tblc[hashc].list[posc].venda[size].month = month;
    sales->tblc[hashc].list[posc].venda[size].branch = branch;
    sales->tblc[hashc].list[posc].size3++;

    sales->size1++;
  }
}

void initSales(THashSales* sales, THashP* tprod, THashC* tcli)
{
  int i, j;

  sales = malloc(sizeof(THashSales));
  sales->size1 = 0;

  for(i=0; i<SIZEP; i++) {
    sales->tblp[i].list = malloc(sizeof(List) * tprod->tbl[i].size);
    sales->tblp[i].size2 = tprod->tbl[i].size;

    for(j=0; j<tprod->tbl[i].size; j++) {
      sales->tblp[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblp[i].list[j].key, tprod->tbl[i].list[j]);

      sales->tblp[i].list[j].size3 = 0;
      sales->tblp[i].list[j].venda = NULL;
    }
  }

  for(i=0; i<SIZEC; i++) {
    sales->tblc[i].list = malloc(sizeof(List) * tcli->tbl[i].size);
    sales->tblc[i].size2 = tcli->tbl[i].size;

    for(j=0; j<tcli->tbl[i].size; j++) {
      sales->tblc[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblc[i].list[j].key, tcli->tbl[i].list[j]);
      
      sales->tblc[i].list[j].size3 = 0;
      sales->tblc[i].list[j].venda = NULL;
    }
  }
}

// Abre o array das vendas e passa-as para uma struct
int tblSales(THashSales* sales, THashP* tprod, THashC* tcli) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);

  if((fsales = fopen("../files/Vendas_1M.txt", "r")) == NULL)
    return -1;
  
  initSales(sales, tprod, tcli);

  while(fgets(buffer,MAX,fsales)) {
    buffer = strsep(&buffer, "\r");
    saleS(sales, buffer, tprod, tcli);
  }

  fclose(fsales);  
    
   return 0;
}

/*
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

  printf("Vendas Válidas: %d\n", sales->size1);
}
*/