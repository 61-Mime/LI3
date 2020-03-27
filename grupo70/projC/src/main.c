#include "sgv.h"

SGV sgv;

int main()
{
  sgv = initSGV();

  sgv = loadSGVFromFiles(sgv);

  destroySGV(sgv);

  return 0;
}
