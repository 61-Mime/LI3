/**
 * @file  catalogo.c
 * @brief Ficheiro que contém funções relativas ao módulo Catálogo
 */

#include "catalogo.h"

#define MAX 10
#define SIZE 26

typedef struct cat {
  int size;
  char** list;
} Cat;

typedef struct catalogo {
  Cat* tbl;
} Catalogo;

/**
 * @brief   Função inicializa a estrutura Catalogo
 * @return  Apontador para Catalogo
 */
Catalogo* initCat() {
  Catalogo* cat = malloc(sizeof(Catalogo));
  cat->tbl = malloc(sizeof(Cat) * SIZE);
  int i;

  for(i=0; i<SIZE; i++) {
    cat->tbl[i].size = 0;
    cat->tbl[i].list = NULL;
  }

  return cat;
}

/**
 * @brief     Função procura uma key num Catalogo
 * @param key Chave a procurar
 * @param cat Apontador para o Catalogo
 * @return    Inteiro com a posição
 */
int searchCat(char* key, Catalogo* cat){
  int hash, res;

  hash = hashCat(key[0]);
  res = binarySearch(cat->tbl[hash].list, key, 0, cat->tbl[hash].size-1);

  return res;
}

/**
 * @brief   Função calcula a posição no Catalogo
 * @param c Char Chave
 * @return  Inteiro com a posição
 */
int hashCat(char c) {
  if(c <'A' || c > 'Z') return -1;
  return (c - 65);
}

/**
 * @brief       Função verifica se a chave é válida
 * @param key   Chave a verificar
 * @param type  Char que indica o tipo do catálogo
 * @return      Inteiro usado como booleano
 */
int isVal(char *key, char type) {
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

/**
 * @brief     Função adiciona uma chave ao Catalogo
 * @param cat Apontador para Catalogo
 * @param key Chave a adicionar
 * @param i   Posicao da tabela a adicionar
 * @param val Apontador para inteiro que contem o numero de chaves validadas
 */
void addKey(Catalogo* cat, char* key, int i, int* val) {
  int pos = cat->tbl[i].size;

  cat->tbl[i].list = realloc(cat->tbl[i].list,sizeof(char*) * (cat->tbl[i].size + 1));
  cat->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
  strcpy(cat->tbl[i].list[pos], key);

  cat->tbl[i].size ++;
  (*val)++;
}

int comparatorC(const void *p,const void *q) {
   return strcmp(*(char **)p,*(char **)q);
}

/**
 * @brief           Função le um ficheiro, valida e adiciona as keys ao Catalogo
 * @param cat       Apontador para Catalogo
 * @param filePath  Caminho para o ficheiro
 * @param type      Char que indica o tipo do catálogo
 * @param val       Apontador para inteiro que contem o numero de chaves validadas
 * @param lida      Apontador para inteiro que contem o numero de chaves lidas
 * @return          Inteiro usado como booleano
 */
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
    qsort(cat->tbl[i].list, cat->tbl[i].size, sizeof(char *),comparatorC);
    //quickSort(cat->tbl[i].list, 0, cat->tbl[i].size - 1);

  free(buffer);
  //for(i=0; i<cat->tbl[0].size; i++)
//printf("%s\n",cat->tbl[0].list[i]);
  return 0;
}

/**
 * @brief     Função liberta o espaço de memoria ocupado pelo Catalogo
 * @param cat Apontador para Catalogo
 */
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

/**
 * @brief     Função devolve tamanho da Lista
 * @param cat Apontador para Catalogo
 * @param i   Posição na Tabela
 * @return    Inteiro com o tamanho da Lista
 */
int getCatListSize(Catalogo* cat, int i) {
  return cat->tbl[i].size;
}

/**
 * @brief     Função devolve a chave do Catalogo
 * @param cat Apontador para o Catalogo
 * @param i   Posição na Tabela
 * @param j   Posição na Lista
 * @return    Apontador para a Key
 */
char* getCatKey(Catalogo* cat, int i, int j) {
  return cat->tbl[i].list[j];
}
