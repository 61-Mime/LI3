#include "sgv.h"
#include "intrepertador.h"
#include <stdio.h>

SGV sgv;

int main()
{
  sgv = initSGV();

  intrepertador(sgv);

  //sgv = loadSGVFromFiles(sgv, clientPath, productPath, salesPath);

  //printSGV(sgv);

  //getProductsStartedByLetter(sgv, 'A');

  //getClientsAndProductsNeverBoughtCount(sgv);

  //getProductsBoughtByClient(sgv, clientID);
  //getProductBuyers(sgv,"ZZ1804",3);

  //getSalesAndProfit(sgv,1,10);

  //destroySGV(sgv);

  return 0;
}
