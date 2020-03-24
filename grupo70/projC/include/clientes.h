#ifndef __clientes_h
#define __clientes_h

#include "sort.h"

//STRUCTS CLIENTES
typedef struct cli {
  int size;
  char** list;
} Cli;

typedef struct thashcli {
  int sizet;
  Cli tbl[26];
} THashC;

int hashC(char c);
void tblCli(THashC* tcli);
void printCli(THashC* cli);
void freeCli(THashC* cli);

#endif
