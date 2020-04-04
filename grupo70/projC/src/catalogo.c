#include "catalogo.h"

#define MAX 10
#define SIZE 26

Catalogo* initCat()
{
  Catalogo* cat = malloc(sizeof(Catalogo));
  cat->tbl = malloc(sizeof(Cat) * SIZE);
  int i;

  for(i=0; i<SIZE; i++) {
    cat->tbl[i].size = 0;
    cat->tbl[i].list = NULL;
  }

  return cat;
}

int searchCat(char* key, Catalogo* cat){
  int hash, res;

  hash = hashCat(key[0]);
  res = binarySearch(cat->tbl[hash].list, key, 0, cat->tbl[hash].size-1);

  return res;
}

int hashCat(char c) {
  if(c <'A' || c > 'Z') return -1;
  return (c - 65);
}

int isVal(char *key, char type)
{
  int i, res=1;

  if(type == 'c') {
    if(strlen(key) < 5 || key[0] < 'A' || key[0] > 'Z' || key[1] < '1' || key[1] > '5')
      res = 0;

    for(i = 2; i < 5; i++)
      if(key[i] < '0' || key[i] > '9')
        res = 0;
  }

  else {
    if(strlen(key) < 5 || key[0] < 'A' || key[0] > 'Z' || key[1] < 'A' || key[1] > 'Z' || key[2] < '1')
      res = 0;

    for(i = 2; i < 6; i++)
      if(key[i] < '0' || key[i] > '9')
        res = 0;
  }

  return res;
}

void addKey(Catalogo* cat, char* key, int i, int* val) {
  int pos = cat->tbl[i].size;

  cat->tbl[i].list = realloc(cat->tbl[i].list,sizeof(char*) * (cat->tbl[i].size + 1));
  cat->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
  strcpy(cat->tbl[i].list[pos], key);

  cat->tbl[i].size ++;
  (*val)++;
}

int tblCat(Catalogo* cat, char* filePath, char type, int* val, int* lida) {
  FILE* f;
  char* buffer= malloc(sizeof(char) * MAX);
  int i;

  if((f = fopen(filePath, "r")) == NULL) {
    perror(filePath);
    return -1;
  }

  while(fgets(buffer,MAX,f)) {
    buffer = strsep(&buffer, "\r");

    if(isVal(buffer, type))
      addKey(cat, buffer, hashCat(buffer[0]), val);

    (*lida)++;
  }

  fclose(f);

  for(i=0; i<SIZE; i++)
    quickSort(cat->tbl[i].list, 0, cat->tbl[i].size - 1);

  free(buffer);

  return 0;
}

void freeCat(Catalogo* cat) {
  int i, j;

  for(i=0; i<SIZE; i++) {
    for(j=0; j<cat->tbl[i].size; j++) {
      free(cat->tbl[i].list[j]);
      cat->tbl[i].list[j] = NULL;
    }
    free(cat->tbl[i].list);
    cat->tbl[i].list = NULL;
  }

  free(cat->tbl);
  cat->tbl = NULL;
  
  free(cat);
  cat = NULL;
}

//GETTERS

int getCatListSize(Catalogo* cat, int i) {
  return cat->tbl[i].size;
}

char* getCatKey(Catalogo* cat, int i, int j) {
  return cat->tbl[i].list[j];
}
