#include "sgv.h"
#include "interface.h"
#include "time.h"

SGV sgv;

int main() {
  //intrepertador(sgv);

  sgv = loadSGVFromFiles(sgv, "../files/Clientes.txt", "../files/Produtos.txt", "../files/Vendas_1M.txt");

  //printf("%d\n", getGFilPListSize(sgv->gfil, 0, 1));

  return 0;
}
