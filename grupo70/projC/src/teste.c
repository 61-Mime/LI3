#include "interpretador.h"
#include "interface.h"

SGV sgv;
#define SMAX 100

int main() {
  char c1[SMAX], c2[SMAX], c3[SMAX];
  int i;
  sgv = NULL;

  strcpy(c1, "/Users/luissobral/grupo70/grupo70/projC/files/Clientes.txt");
  strcpy(c2, "/Users/luissobral/grupo70/grupo70/projC/files/Produtos.txt");
  strcpy(c3, "/Users/luissobral/grupo70/grupo70/projC/files/Vendas_1M.txt");

  sgv = loadSGVFromFiles(sgv, c1, c2, c3);
  Q13* querie13 = getCurrentFilesInfo(sgv);
  Q2* querie2 = getProductsStartedByLetter(sgv, 'A');
  Q3* querie3 = getProductSalesAndProfit(sgv, "AF1184", 5, 0);
  Q4* querie4 = getProductsNeverBough(sgv, 0);
  Q5* querie5 = getClientsOfAllBranches(sgv);
  Q6* querie6 = getClientsAndProductsNeverBoughtCount(sgv);
  Q7* querie7 = getProductsBoughtByClient(sgv, "Z5000");
  Q8* querie8 = getSalesAndProfit(sgv, 1, 12);
  Q9* querie9 = getProductBuyers(sgv, "AF1184", 1);
  Q10* querie10 = getClientFavouriteProducts(sgv,"Z5000",4);
  Q11* querie11 = getTopSelledProducts(sgv, 30);
  Q12* querie12 = getClientTopProfitProducts(sgv, "Z5000", 30);

  free(querie13);
  querie13 = NULL;
  for(i=0; i<querie2->size; i++) {
    free(querie2->prods[i]);
    querie2->prods[i] = NULL;
  }
  free(querie2->prods);
  querie2->prods = NULL;
  free(querie2);
  querie2 = NULL;
  free(querie3->fat);
  querie3->fat = NULL;
  free(querie3);
  querie3 = NULL;
  for(i=0; i<querie4->size; i++) {
      free(querie4->prods[i]);
      querie4->prods[i] = NULL;
  }
  free(querie4->prods);
  querie4->prods = NULL;
  free(querie4);
  querie4 = NULL;
  for(i=0; i<querie5->size; i++) {
    free(querie5->cli[i]);
    querie5->cli[i] = NULL;
  }
  free(querie5->cli);
  querie5->cli = NULL;
  querie5 = NULL;
  free(querie5);
  querie5 = NULL;
  free(querie6);
  querie6 = NULL;
  free(querie7);
  querie7 = NULL;
  free(querie8);
  querie8 = NULL;
  free(querie9->lista);
  querie9->lista = NULL;
  free(querie9);
  querie9 = NULL;
  free(querie10->produtos);
  querie10->produtos = NULL;
  free(querie10);
  querie10 = NULL;
  free(querie11->produtos);
  querie11->produtos = NULL;
  free(querie11);
  querie11 = NULL;
  free(querie12->prods);
  querie12->prods = NULL;
  free(querie12);
  querie12 = NULL;

  destroySGV(sgv);
  return 0;
}
