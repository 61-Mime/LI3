#ifndef __sgv_h
#define __sgv_h

#include "produtos.h"
#include "clientes.h"
#include "sales.h"

typedef struct sgv
{
    THashC* cli;
    THashP* prod;
    THashSales* sales;
    THashFact* fact;
    // Faturação
}*SGV;

// Functions
SGV initSGV();
SGV loadSGVFromFiles(SGV sgv/*, char* filesFolderPath*/);
void printSGV(SGV sgv);
void destroySGV(SGV sgv);

#endif
