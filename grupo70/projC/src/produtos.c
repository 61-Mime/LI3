#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define MAX 10
#define SIZE 676

int hashP(char c,char c2)
{
  return (c - 'a')*26 + c2 - 'a';
}

void initTblP(THashP* tprod)
{
  int i;

  tprod = malloc(sizeof(THashP));

  tprod->sizet = 0;

  for(i=0; i<SIZE; i++)
    tprod->tbl[i].size = 0;
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

void tblProd(THashP* tprod)
{
  FILE* fprod;
  char* buffer= malloc(sizeof(char) * MAX);
  int i, pos;

  if((fprod = fopen("../files/Produtos.txt", "r")) == NULL) {
    printf("ERROR");
    return;
  }

  initTblP(tprod);

  while(fgets(buffer,MAX,fprod))
  {
    buffer = strsep(&buffer, "\r");

    if(prodVal(buffer))
    {
      i = hashP(buffer[0],buffer[1]);

      pos = tprod->tbl[i].size;

      tprod->tbl[i].list = realloc(tprod->tbl[i].list,sizeof(char*) * (pos + 1));

      tprod->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
      strcpy(tprod->tbl[i].list[pos],buffer);

      tprod->tbl[i].size ++;
      tprod->sizet ++;
    }
  }

  fclose(fprod);

  for(i=0; i<SIZE; i++)
    quickSort(tprod->tbl[i].list, 0, tprod->tbl[i].size - 1);
}
