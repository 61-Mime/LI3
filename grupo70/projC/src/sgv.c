#include "sgv.h"

SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initCat();
    sgv->cli = initCat();
    sgv->sales = initSales();
    sgv->fact = initFact();
    sgv->gfil = initGFil();
    sgv->load = 0;

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    tblCat(sgv->prod, productsFilePath, 'p');
    tblCat(sgv->cli, clientsFilePath, 'c');
    tblSales(sgv->sales, sgv->prod, sgv->cli, salesFilePath);
    tblFact(sgv->sales, sgv->fact);
    tblGFil(sgv->gfil, sgv->sales);
    sgv->load = 1;

    return sgv;
}

void destroySGV(SGV sgv) {
    freeCat(sgv->prod);
    freeCat(sgv->cli);
    freeSales(sgv->sales);
    freeFact(sgv->fact);
    freeGFil(sgv->gfil);
    sgv->load = 0;
    
    free(sgv);
}
