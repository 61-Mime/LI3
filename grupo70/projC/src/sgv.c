#include "sgv.h"

FileInfo* initFileInfo() {
    FileInfo* f = malloc(sizeof(FileInfo));
    
    f->prodV = 0;
    f->prodL = 0;
    f->cliV = 0;
    f->cliL = 0;
    f->saleV = 0;
    f->saleL = 0;

    return f;
}

SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initCat();
    sgv->cli = initCat();
    sgv->fact = initFact();
    sgv->gfil = initGFil();
    sgv->info = initFileInfo();

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    tblCat(sgv->prod, productsFilePath, 'p', &sgv->info->prodV, &sgv->info->prodL);
    tblCat(sgv->cli, clientsFilePath, 'c', &sgv->info->cliV, &sgv->info->cliL);
    loadFactFromCat(sgv->fact, sgv->prod);
    loadGFilFromCat(sgv->gfil, sgv->prod, sgv->cli);
    loadFromSales(sgv->prod, sgv->cli, sgv->fact, sgv->gfil, salesFilePath, &sgv->info->saleV, &sgv->info->saleL);

    return sgv;
}

void destroySGV(SGV sgv) {
    freeCat(sgv->prod);
    freeCat(sgv->cli);
    freeFact(sgv->fact);
    freeGFil(sgv->gfil);
    free(sgv->info);
    free(sgv);
}

int getSGVprodV(FileInfo* info) {
    return info->prodV;
}

int getSGVprodL(FileInfo* info) {
    return info->prodL;
}

int getSGVcliV(FileInfo* info) {
    return info->cliV;
}

int getSGVcliL(FileInfo* info) {
    return info->cliL;
}

int getSGVsaleV(FileInfo* info) {
    return info->saleV;
}

int getSGVsaleL(FileInfo* info) {
    return info->saleL;
}