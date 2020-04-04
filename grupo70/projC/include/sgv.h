#ifndef __sgv_h
#define __sgv_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "sales.h"
#include "faturacao.h"
#include "filial.h"

typedef struct filesinfo {
    int prodV;
    int prodL;
    int cliV;
    int cliL;
    int saleV;
    int saleL;
} FileInfo;

typedef struct sgv {
    Catalogo* cli;
    Catalogo* prod;
    THashFact* fact;
    GFiliais* gfil;
    FileInfo* info;
}*SGV;

// Functions
SGV initSGV();
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath,
                              char* productsFilePath,
                              char* salesFilePath
                              );
void destroySGV(SGV sgv);
int getSGVprodV(FileInfo* info);
int getSGVprodL(FileInfo* info);
int getSGVcliV(FileInfo* info);
int getSGVcliL(FileInfo* info);
int getSGVsaleV(FileInfo* info);
int getSGVsaleL(FileInfo* info);

#endif
