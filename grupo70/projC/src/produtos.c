#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define MAX 10
#define SIZE 26

THashP* initProd()
{
  THashP* tprod = malloc(sizeof(THashP));
  int i;
  
  tprod->sizet = 0;

  for(i=0; i<SIZE; i++) {
    tprod->tbl[i].size = 0;
    tprod->tbl[i].list = NULL;
  }

  return tprod;
}

int searchProd(char* prod, THashP* tprod){
  int hash, res;

  hash = hashP(prod[0]);
  res = binarySearch(tprod->tbl[hash].list, prod, 0, tprod->tbl[hash].size-1);

  return res;
}

int hashP(char c)
{
  return (c - 'A');
}

int prodVal(char *prod)
{
  int i;

  if(strlen(prod) < 5 || prod[0] < 'A' || prod[0] > 'Z' || prod[1] < 'A' ||
    prod[1] > 'Z' || prod[2] < '1')
    return 0;

  for(i = 2; i < 6; i++)
    if(prod[i] < '0' || prod[i] > '9')
      return 0;

  return 1;
}

int tblProd(THashP* tprod)
{
  FILE* fprod;
  char* buffer= malloc(sizeof(char) * MAX);
  int i, pos;

  if((fprod = fopen("../files/Produtos.txt", "r")) == NULL)
    return -1;

  while(fgets(buffer,MAX,fprod))
  {
    buffer = strsep(&buffer, "\r");

    if(prodVal(buffer))
    {
      i = hashP(buffer[0]);

      pos = tprod->tbl[i].size;

      tprod->tbl[i].list = realloc(tprod->tbl[i].list,sizeof(char*) * (pos+ 1));

      tprod->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
      strcpy(tprod->tbl[i].list[pos],buffer);

      tprod->tbl[i].size ++;
      tprod->sizet ++;
    }
  }

  fclose(fprod);

  for(i=0; i<SIZE; i++)
    quickSort(tprod->tbl[i].list, 0, tprod->tbl[i].size - 1);

  return 0;
}

void printProd(THashP* prod) {
  int i, j;

  for(i=0; i<SIZE; i++)
    for(j=0; j<prod->tbl[i].size; j++)
      printf("%s\n", prod->tbl[i].list[j]);

  printf("Total Produtos: %d\n", prod->sizet);
}

void freeProd(THashP* prod) {
  int i, j;

  for(i=0; i<SIZE; i++) {
    for(j=0; j<prod->tbl[i].size; j++)
      free(prod->tbl[i].list[j]);
    free(prod->tbl[i].list);
  }

  free(prod);
}