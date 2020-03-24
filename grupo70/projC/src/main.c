#include <stdio.h>
#include "clientes.h"
#include "produtos.h"
#include "sales.h"

THashP prod;
THashC cli;
ARR sales;
SALES s;

int main()
{
  tblProd(&prod);
  //tblCli(&cli);
  //salesToStructs(&sales, &s, &prod, &cli);

  printProd(&prod);
  //printCli(&cli);
  //printSales(&s);

  //freeProd(&prod);
  //freeCli(&cli);

  return 0;
}
