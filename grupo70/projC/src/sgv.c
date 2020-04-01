#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgv.h"

SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initProd();
    sgv->cli = initCli();
    sgv->sales = initSales();
    sgv->fact = initFact();
    sgv->gfil = initGFil();
    sgv->load = 0;

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    tblProd(sgv->prod, productsFilePath);
    tblCli(sgv->cli, clientsFilePath);
    tblSales(sgv->sales, sgv->prod, sgv->cli, salesFilePath);
    tblFact(sgv->sales, sgv->fact);
    tblGFil(sgv->gfil, sgv->sales);
    sgv->load = 1;

    return sgv;
}

void destroySGV(SGV sgv) {
    freeProd(sgv->prod);
    freeCli(sgv->cli);
    freeSales(sgv->sales);
    freeFact(sgv->fact);
    freeGFil(sgv->gfil);
    sgv->load = 0;
    
    free(sgv);
}
