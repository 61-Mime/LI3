#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sales.h"

#define MAX 64
#define SIZE 676

void initSales(SALES* s)
{
  int i;

  s = malloc(sizeof(SALES));
  s -> usedV = 0;
  s -> usedT = 0;

  s -> listT = NULL;

  for(i=0; i<SIZE; i++) {
    s->listV[i].size = 0;
    s->listV[i].list = NULL;
  }
}

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(SALES* s, char* buffer, THashP* tprod, THashC* tcli)
{
  char *aux = NULL;
  int p, c,x;

  s->listT = realloc(s->listT,sizeof(SALE) * (s->usedT + 1));

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].p = aux;
  p = hashP(aux[0],aux[1]);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].price = atof(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].uni = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].type = aux;

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].c = aux;
  c = hashC(aux[0]);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].month = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].branch = atoi(aux);

  if((binarySearch(tprod->tbl[p].list, s->listT[s->usedT].p, 0, tprod->tbl[p].size-1)!=(-1))
  &&(binarySearch(tcli->tbl[c].list, s->listT[s->usedT].c, 0, tcli->tbl[c].size-1)!=(-1)))
  {
    //s->listV = realloc(s->listV,sizeof(SALE) * (s->usedV + 1));
    x = s->listV[p].size;
    s->listV[p].list = realloc(s->listV[p].list,sizeof(SALE) * (x + 1));

    s->listV[p].list[x].p = s->listT[s->usedT].p;
    s->listV[p].list[x].price = s->listT[s->usedT].price;
    s->listV[p].list[x].uni = s->listT[s->usedT].uni;
    s->listV[p].list[x].type = s->listT[s->usedT].type;
    s->listV[p].list[x].c = s->listT[s->usedT].c;
    s->listV[p].list[x].month = s->listT[s->usedT].month;
    s->listV[p].list[x].branch = s->listT[s->usedT].branch;
    s->usedV++;
    s->listV[p].size++;
  }

  s ->usedT++;
}

// Passa todas as vendas para um array
void salesToA(ARR* sales) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);
  int used;

  if((fsales = fopen("../files/Vendas_1M.txt", "r")) == NULL) {
    printf("ERROR");
    return;
  }

  for(used=0; fgets(buffer,MAX,fsales); used++) {
    buffer = strsep(&buffer, "\r");

    sales->list = realloc(sales->list,sizeof(char*) * (used + 1));

    sales->list[used] = malloc(MAX * sizeof(char));
    strcpy(sales->list[used],buffer);
  }

  sales->used = used;

  fclose(fsales);
}

// Passa todas as vendas válidas do array para um ficheiro
void salesToF(SALES* s) {
  FILE* fsalesv;

  if((fsalesv = fopen("../files/Vendas_1MValidas.txt", "w")) == NULL) {
    printf("ERROR");
    return;
  }

  for(int i=0; i<SIZE; i++){
    for(int j = 0;j < s -> listV[i].size;j++)
      fprintf(fsalesv,"%s %f %d %s %s %d %d\r\n",
              s->listV[i].list[j].p,
              s->listV[i].list[j].price,
              s->listV[i].list[j].uni,
              s->listV[i].list[j].type,
              s->listV[i].list[j].c,
              s->listV[i].list[j].month,
              s->listV[i].list[j].branch);
  }

  fclose(fsalesv);
}

// Abre o array das vendas e passa-as para uma struct
void salesToStructs(ARR* sales,SALES*s, THashP* tprod, THashC* tcli) {
  initSales(s);
  salesToA(sales);

  for(int i=0; i<sales->used; i++)
    saleS(s, sales->list[i], tprod, tcli);

  for(int i=0; i<SIZE; i++)
    quickSortSALE(s->listV[i].list, 0, s->listV[i].size - 1);

  salesToF(s);

}

void printSales(SALES* s) {
  int i,j;

  for(i=0; i<SIZE; i++){
    for(j = 0;j < s -> listV[i].size;j++)
      printf("%s %f %d %s %s %d %d\r\n",
              s->listV[i].list[j].p,
              s->listV[i].list[j].price,
              s->listV[i].list[j].uni,
              s->listV[i].list[j].type,
              s->listV[i].list[j].c,
              s->listV[i].list[j].month,
              s->listV[i].list[j].branch);
  }

  printf("Vendas Válidas: %d\n", s->usedV);
}
