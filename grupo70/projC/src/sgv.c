#include <stdio.h>
#include <stdlib.h>
#include "sgv.h"

SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initProd();
    sgv->cli = initCli();
    sgv->sales = initSales();
    sgv->fact = initFact();

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath) {
    tblProd(sgv->prod);
    tblCli(sgv->cli);
    tblSales(sgv->sales, sgv->prod, sgv->cli);
    //tblFact(sgv->sales,sgv->fact);

    return sgv;
}

void printSGV(SGV sgv) {
    //printProd(sgv->prod);
    //printCli(sgv->cli);
    printSales(sgv->sales);
    //printFact(sgv->fact);
}

void destroySGV(SGV sgv) {
    freeProd(sgv->prod);
    freeCli(sgv->cli);
    freeSales(sgv->sales);
    freeFact(sgv->fact);
    free(sgv);
}
