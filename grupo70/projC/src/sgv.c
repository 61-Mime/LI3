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
    sgv->fil1 = initFil();
    sgv->fil2 = initFil();
    sgv->fil3 = initFil();

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    tblProd(sgv->prod, productsFilePath);
    tblCli(sgv->cli, clientsFilePath);
    tblSales(sgv->sales, sgv->prod, sgv->cli, salesFilePath);
    tblFact(sgv->sales,sgv->fact);
    tblFil(sgv->sales,sgv->fil1,1);
    tblFil(sgv->sales,sgv->fil2,2);
    tblFil(sgv->sales,sgv->fil3,3);

    return sgv;
}

void getCurrentFilesInfo(SGV sgv) {
    return;
}

void printSGV(SGV sgv) {
    //printProd(sgv->prod);
    //printCli(sgv->cli);
    //printSales(sgv->sales);
    //printFact(sgv->fact);
    printFil(sgv->fil1);
}

void destroySGV(SGV sgv) {
    freeProd(sgv->prod);
    freeCli(sgv->cli);
    freeSales(sgv->sales);
    freeFact(sgv->fact);

    free(sgv);
}
