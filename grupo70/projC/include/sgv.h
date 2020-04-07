#ifndef __sgv_h
#define __sgv_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "sales.h"
#include "faturacao.h"
#include "filial.h"

typedef struct filesinfo FileInfo;
typedef struct sgv *SGV;

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
