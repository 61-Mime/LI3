#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

#define MAX 10
#define SIZE 26

THashC* initCli()
{
  THashC* tcli = malloc(sizeof(THashC));
  int i;

  tcli->sizet = 0;

  for(i=0; i<SIZE; i++) {
    tcli->tbl[i].size = 0;
    tcli->tbl[i].list = NULL;
  }

  return tcli;
}

int searchCli(char* cli, THashC* tcli){
  int hash, res;

  hash = hashC(cli[0]);
  res = binarySearch(tcli->tbl[hash].list, cli, 0, tcli->tbl[hash].size-1);

  return res;
}

int hashC(char c)
{
  return c - 65;
}

int cliVal(char *cliente)
{
  int i;

  if(strlen(cliente) < 5 || cliente[0] < 'A' || cliente[0] > 'Z' || cliente[1] < '1' || cliente[1] > '5')
    return 0;

  for(i = 2; i < 5; i++)
    if(cliente[i] < '0' || cliente[i] > '9')
      return 0;

  return 1;
}

int tblCli(THashC* tcli)
{
  FILE* fcli = fopen("../files/Clientes.txt", "r");
  char* buffer= malloc(sizeof(char) * MAX);
  int i, pos;

  if((fcli = fopen("../files/Clientes.txt", "r")) == NULL)
    return -1;

  while(fgets(buffer,MAX,fcli))
  {
    buffer = strsep(&buffer, "\r");

    if(cliVal(buffer))
    {
      i = hashC(buffer[0]);
      pos = tcli->tbl[i].size;

      tcli->tbl[i].list = realloc(tcli->tbl[i].list,sizeof(char*) * (tcli->tbl[i].size + 1));

      tcli->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
      strcpy(tcli->tbl[i].list[pos],buffer);

      tcli->tbl[i].size ++;
      tcli->sizet ++;
    }
  }

  fclose(fcli);

  for(i=0; i<SIZE; i++)
    quickSort(tcli->tbl[i].list, 0, tcli->tbl[i].size - 1);

  return 0;
}

void printCli(THashC* cli) {
  int i, j;

  for(i=0; i<SIZE; i++)
    for(j=0; j<cli->tbl[i].size; j++)
      printf("%s\n", cli->tbl[i].list[j]);

  printf("Total Clientes: %d\n", cli->sizet);
}

void freeCli(THashC* cli) {
  int i, j;

  for(i=0; i<SIZE; i++) {
    for(j=0; j<cli->tbl[i].size; j++)
      free(cli->tbl[i].list[j]);
    free(cli->tbl[i].list);
  }

  free(cli);
}
