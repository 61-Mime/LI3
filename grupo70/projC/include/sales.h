#ifndef __sales_h
#define __sales_h

#include "produtos.h"
#include "clientes.h"

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
  int size1;
  int comprados;
  int compradores;
  TSale tblp[78];
  TSale tblc[78];
} THashSales;

// Functions
THashSales* initSales();
int tblSales(THashSales* salesp, THashP* prod, THashC* cli, char* filePath);
void printSales(THashSales* salesp);
void freeSales(THashSales* sales);

#endif
