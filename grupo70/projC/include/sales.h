#ifndef __sales_h
#define __sales_h

#include "produtos.h"
#include "clientes.h"
#include "sort.h"

// Struct array
typedef struct arr{
  int used;
  char** list;
} ARR;

// Struct que suporta uma venda
typedef struct selling{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} SALE;

//struct uma letra de vendas
typedef struct tsale {
  int size;
  SALE* list;
} TSALE;

// Struct que suporta duas listas de vendas
typedef struct sellings{
  int usedV;
  int usedT;
  //SALE* listV;
  TSALE listV[676];
  SALE* listT;
} SALES;

void salesToStructs(ARR* sales, SALES* s, THashP* prod, THashC* cli);
void printSales(SALES* s);

#endif
