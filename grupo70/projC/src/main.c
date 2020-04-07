#include "sgv.h"
#include "interface.h"
#include "time.h"

SGV sgv;

int main() {

  sgv = initSGV();

  //intrepertador(sgv);
runQuerie1e13(sgv,"1",0);
printf("%s\n", getGFilPCliN(sgv->gfil,0,0,0,0));
  destroySGV(sgv);

  return 0;
}
