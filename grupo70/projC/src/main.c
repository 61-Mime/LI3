#include "sgv.h"
#include "intrepertador.h"
#include "time.h"

SGV sgv;

int main() {
  sgv = initSGV();

  intrepertador(sgv);

  destroySGV(sgv);

  return 0;
}
