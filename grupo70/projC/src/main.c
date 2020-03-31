#include "sgv.h"
#include "intrepertador.h"
#include <stdio.h>

SGV sgv;

int main()
{
  sgv = initSGV();

  loadSGVFromFiles(sgv, "../files/Clientes.txt", "../files/Produtos.txt", "../files/Vendas_1M.txt"),
  //intrepertador(sgv);

  destroySGV(sgv);

  return 0;
}
