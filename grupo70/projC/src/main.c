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
  tblCli(&cli);

  //printProd(&prod);
  //printCli(&cli);

  salesToStructs(&sales, &s, &prod, &cli);

  //printSales(&s);

  return 0;
}