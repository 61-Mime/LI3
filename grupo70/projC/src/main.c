#include "sgv.h"
#include <stdio.h>

SGV sgv;

int main()
{
  char path[] = "../files";
  
  sgv = initSGV();

  sgv = loadSGVFromFiles(sgv, path);

  printSGV(sgv);

  //destroySGV(sgv);

  return 0;
}
