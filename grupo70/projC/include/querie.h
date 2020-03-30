#ifndef __querie_h
#define __querie_h

#include "sgv.h"
#include "faturacao.h"

void getProductsStartedByLetter(SGV sgv, char letter);
void getClientsAndProductsNeverBoughtCount(SGV sgv);
void getProductsBoughtByClient(SGV sgv, char* clientID);
void getProductBuyers(SGV sgv,char *prodID,int branch);
void getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);

#endif
