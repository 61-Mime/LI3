#include "sgv.h"
#include "intrepertador.h"
#include "time.h"

SGV sgv;

int main() {
  sgv = initSGV();

  intrepertador(sgv);

  //sgv = loadSGVFromFiles(sgv, "../files/Clientes.txt", "../files/Produtos.txt", "../files/Vendas_1M.txt");
//print(sgv->gfil);
  destroySGV(sgv);

  return 0;
}
