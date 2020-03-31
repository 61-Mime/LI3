#include "sgv.h"
#include "intrepertador.h"
#include <stdio.h>

SGV sgv;

int main()
{
  sgv = initSGV();

  loadSGVFromFiles(sgv, "../files/Clientes.txt", "../files/Produtos.txt", "../files/Vendas_1M.txt"),
  //intrepertador(sgv);
  //printSGV(sgv);
  getProductBuyers(sgv,"ZZ1999",1);

  destroySGV(sgv);

  return 0;
}
