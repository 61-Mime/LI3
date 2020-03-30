#ifndef __filial_h
#define __filial_h


typedef struct venda{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} Venda;

typedef struct lista{
  char* key;
  int size3;
  Venda* venda;
} Lista;

typedef struct hsale{
  int size2;
  Lista* lista;
} HSale;

typedef struct filial{
  int size1;
  HSale tbf[26];
} Filial;

typedef struct branch{
  Filial filial1;
  Filial filial2;
  Filial filial3;
} Branch;

#endif
