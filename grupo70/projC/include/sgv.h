#ifndef __sgv_h
#define __sgv_h

#include "produtos.h"
#include "clientes.h"
#include "sales.h"
#include "faturacao.h"

typedef struct sgv
{
    THashC* cli;
    THashP* prod;
    THashSales* sales;
    THashFact* fact;
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
void getProductsStartedByLetter(SGV sgv, char letter);
void getClientsAndProductsNeverBoughtCount(SGV sgv);
void getProductsBoughtByClient(SGV sgv, char* clientID);
void getProductBuyers(SGV sgv,char *prodID,int branch);
void getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);

#endif
