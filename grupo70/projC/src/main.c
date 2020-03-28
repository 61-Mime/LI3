#include "sgv.h"
#include <stdio.h>

SGV sgv;

int main()
{
  sgv = initSGV();

  sgv = loadSGVFromFiles(sgv);

  //printSGV(sgv);

  //destroySGV(sgv);

  return 0;
}
