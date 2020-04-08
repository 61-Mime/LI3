#ifndef __sgv_h
#define __sgv_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "sales.h"
#include "faturacao.h"
#include "filial.h"

typedef struct sgv *SGV;

// Functions
SGV initSGV();
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath,
                              char* productsFilePath,
                              char* salesFilePath
                              );
void destroySGV(SGV sgv);
int getSGVprodV(SGV sgv);
int getSGVprodL(SGV sgv);
int getSGVcliV(SGV sgv);
int getSGVcliL(SGV sgv);
int getSGVsaleV(SGV sgv);
int getSGVsaleL(SGV sgv);

int getCListsize(SGV sgv,int hash,int type);
char* getCKey(SGV sgv,int type,int i,int j);
int getFVendasN(SGV sgv,int hash,int pos,int branch,int mes);
int getFVendasP(SGV sgv,int hash,int pos,int branch,int mes);
float getFFaturacaoP(SGV sgv,int hash,int pos,int branch,int mes);
float getFFaturacaoN(SGV sgv,int hash,int pos,int branch,int mes);
int getPos(SGV sgv,int type,char *buffer);

void* getSGVGFiliais(SGV sgv);
void* getSGVCli(SGV sgv);
void* getSGVProd(SGV sgv);
void* getSGVFact(SGV sgv);

#endif
