#include "sgv.h"
#include <stdio.h>

SGV sgv;

int main()
{
  char productPath[] = "../files/Produtos.txt";
  char clientPath[] = "../files/Clientes.txt";
  char salesPath[] = "../files/Vendas_1M.txt";
  char clientID[] = "R2292";

  sgv = initSGV();

  sgv = loadSGVFromFiles(sgv, clientPath, productPath, salesPath);

  //printSGV(sgv);
  
  //getProductsStartedByLetter(sgv, 'A');

  //getClientsAndProductsNeverBoughtCount(sgv);

  getProductsBoughtByClient(sgv, clientID);

  destroySGV(sgv);

  return 0;
}
