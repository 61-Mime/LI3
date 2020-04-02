#ifndef __sales_h
#define __sales_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

// Struct que suporta uma venda
typedef struct sale{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} Sale;

typedef struct list {
  char* key;
  int size3;
  Sale* venda;
} List;

//struct uma letra de vendas
typedef struct tsale {
  int size2;
  List* list;
} TSale;

typedef struct thashsalesp {
  int nValidas;
  int nLidas;
  TSale tblp[26];
  TSale tblc[26];
} THashSales;

// Functions
THashSales* initSales();
int tblSales(THashSales* salesp, Catalogo* prod, Catalogo* cli, char* filePath);
void printSales(THashSales* salesp);
void freeSales(THashSales* sales);

#endif
