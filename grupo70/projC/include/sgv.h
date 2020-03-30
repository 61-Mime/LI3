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
    TblFil* fil1;
    TblFil* fil2;
    TblFil* fil3;
}*SGV;

// Functions
SGV initSGV();
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath,
                              char* productsFilePath,
                              char* salesFilePath
                              );
void getCurrentFilesInfo(SGV sgv);
void printSGV(SGV sgv);
void destroySGV(SGV sgv);

#endif
