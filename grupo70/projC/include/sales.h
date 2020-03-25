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
  TSale tblp[676];
  TSale tblc[26];
} THashSales;

// Functions
int tblSales(THashSales* salesp, THashP* prod, THashC* cli);
void printSales(THashSales* salesp);

#endif

// ESTA AQUI PARA NAO OCUPAR ESPAÇO

/*
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
*/