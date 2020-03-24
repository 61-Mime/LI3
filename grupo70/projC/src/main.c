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
  salesToStructs(&sales, &s, &prod, &cli);

<<<<<<< HEAD

  //for(int i=0; i<TSIZEC; i++)
    //for(int j=0, i=0; j<cli.tbl[i].size; j++)
      //printf("%s\n", cli.tbl[i].list[j]);
=======
  //printProd(&prod);
  //printCli(&cli);
  //printSales(&s);
>>>>>>> 0128f0c775d79fc1cdd738f08fff1e989b8518e3

  freeProd(&prod);
  freeCli(&cli);

<<<<<<< HEAD
  salesToStructs(&sales, &s, &prod, &cli);
=======
>>>>>>> 0128f0c775d79fc1cdd738f08fff1e989b8518e3
  return 0;
}
