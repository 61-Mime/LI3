#ifndef __querie_h
#define __querie_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgv.h"
#include "faturacao.h"

typedef struct q2 {
    int size;
    char** prods;
} Q2;

typedef struct q3fat {
    int nVendasN;
    int nVendasP;
    float fatN;
    float fatP;
} Q3fat;

typedef struct q3 {
    int size;
    Q3fat* fat;
} Q3;

typedef struct q6 {
    int nProd;
    int nCli;
} Q6;

typedef struct q7 {
    int tabela[12][3];
} Q7;

typedef struct q8 {
    int vendas;
    float fact;
} Q8;

typedef struct cl9
{
    int tipocompra;
    char cliente[10];
} Cl;

typedef struct q9
{
    int total;
    Cl *lista;
}*Q9;

typedef struct q13 {
    int prodL;
    int prodV;
    int cliL;
    int cliV;
    int salesL;
    int salesV;
} Q13;

Q2* getProductsStartedByLetter(SGV sgv, char letter);
Q3* getProductSalesAndProfit(SGV sgv, char* productID, int month, int type);
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv);
Q7* getProductsBoughtByClient(SGV sgv, char* clientID);
Q8* getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);
Q9 getProductBuyers(SGV sgv,char *prodID,int branch);
Q13* getCurrentFilesInfo(SGV sgv);

#endif
