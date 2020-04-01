#ifndef __clientes_h
#define __clientes_h

#include "sort.h"

//STRUCTS CLIENTES
typedef struct cli {
  int size;
  char** list;
} Cli;

typedef struct thashcli {
  int nValidas;
  int nLidas;
  Cli tbl[26];
} THashC;

THashC* initCli();
int searchCli(char* cli, THashC* tcli);
int hashC(char c);
int tblCli(THashC* tcli, char* filePath);
void freeCli(THashC* cli);

#endif
