#include <stdio.h>
#include "clientes.h"
#include "produtos.h"
#include "sales.h"

THashP prod;
THashC cli;
THashSales sales;

int main()
{
  tblProd(&prod);
  tblCli(&cli);
  tblSales(&sales, &prod, &cli);

  //printProd(&prod);
  //printCli(&cli);
  //printSales(&sales);

  freeProd(&prod);
  freeCli(&cli);


  return 0;
}
