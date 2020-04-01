#ifndef __sgv_h
#define __sgv_h

#include "produtos.h"
#include "clientes.h"
#include "sales.h"
#include "faturacao.h"
#include "filial.h"

typedef struct sgv
{
    THashC* cli;
    THashP* prod;
    THashSales* sales;
    THashFact* fact;
    GFiliais* gfil;
    int load;
}*SGV;

// Functions
SGV initSGV();
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath,
                              char* productsFilePath,
                              char* salesFilePath
                              );
void destroySGV(SGV sgv);

#endif
