#include <stdio.h>
#include <stdlib.h>
#include "sgv.h"

// Querie 1
SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initProd();
    sgv->cli = initCli();
    sgv->sales = initSales();
    //sgv->fact = initFact();

    return sgv;
}

SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    tblProd(sgv->prod, productsFilePath);
    tblCli(sgv->cli, clientsFilePath);
    tblSales(sgv->sales, sgv->prod, sgv->cli, salesFilePath);
    //tblFact(sgv->sales,sgv->fact);

    return sgv;
}

void getCurrentFilesInfo(SGV sgv) {
    return;
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
    //freeFact(sgv->fact);
    free(sgv);
}

// Querie 2
void getProductsStartedByLetter(SGV sgv, char letter) {
    int i, hash = hashP(letter);

    for(i=0; i<sgv->prod->tbl[hash].size; i++)
        printf("%s\n", sgv->prod->tbl[hash].list[i]);

    printf("Produtos começados por %c: %d\n", letter, sgv->prod->tbl[hash].size);
}

// Querie 3

// Querie 4

// Querie 5

// Querie 6
void getClientsAndProductsNeverBoughtCount(SGV sgv) {
    int prod = sgv->prod->sizet - sgv->sales->comprados;
    int cli = sgv->cli->sizet - sgv->sales->compradores;

    printf("Produtos não comprados: %d\n", prod);
    printf("Clientes não compradores: %d\n", cli);
}

// Querie 7
void getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, k, hash, pos, mes;
    int prods[12];

    hash = hashC(clientID[0]);
    pos = searchCli(clientID, sgv->cli);

    if(pos==(-1)) {
        printf("O código de Cliente não é valido\n");
        return;
    }

    for(k=1; k<4; k++) {
        printf("Filial %d\n", k);

        for(i=0; i<12; i++)
            prods[i] = 0;

        for(i=0; i<sgv->sales->tblc[hash*k].list[pos].size3; i++) {
            mes = sgv->sales->tblc[hash*k].list[pos].venda[i].month;
            prods[mes-1] += sgv->sales->tblc[hash*k].list[pos].venda[i].uni;
        }

        for(i=0; i<12; i++)
            printf("Mes %d: %d\n", (i+1), prods[i]);
        
        printf("\n");
    }
}

// Querie 8

// Querie 9

// Querie 10

// Querie 11

// Querie 12

// Querie 13
