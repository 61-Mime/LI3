/**
 * @file    sgv.c
 * @brief   Ficheiro que contém funções relativas ao módulo SGV
 */

#include "sgv.h"

typedef struct filesinfo {
    int prodV;
    int prodL;
    int cliV;
    int cliL;
    int saleV;
    int saleL;
} FileInfo;

typedef struct sgv {
    Catalogo* cli;
    Catalogo* prod;
    THashFact* fact;
    GFiliais* gfil;
    FileInfo* info;
}*SGV;

/**
 * @brief   Função que inicializa a estrutura FileInfo
 * @return  Apontador para FileInfo 
 */
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

/**
 * @brief   Função que inicializa a estrutura SGV
 * @return  SGV inicializado
 */
SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initCat();
    sgv->cli = initCat();
    sgv->fact = initFact();
    sgv->gfil = initGFil();
    sgv->info = initFileInfo();

    return sgv;
}

/**
 * @brief                   Função carrega a estrutura SGV a partir de ficheiros
 * @param sgv               SGV a carregar
 * @param clientsFilePath   Caminho para o ficheiro de Clientes
 * @param productsFilePath  Caminho para o ficheiro de Produtos
 * @param salesFilePath     Caminho para o ficheiro de Vendas
 * @return                  SGV carregado
 */
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    sgv = initSGV();

    tblCat(sgv->prod, productsFilePath, 'p', &sgv->info->prodV, &sgv->info->prodL);
    tblCat(sgv->cli, clientsFilePath, 'c', &sgv->info->cliV, &sgv->info->cliL);
    loadFactFromCat(sgv->fact, sgv->prod);
    loadGFilFromCat(sgv->gfil, sgv->prod, sgv->cli);
    loadFromSales(sgv->prod, sgv->cli, sgv->fact, sgv->gfil, salesFilePath, &sgv->info->saleV, &sgv->info->saleL);

    return sgv;
}

/**
 * @brief       Função que liberta o espaço de memória ocupado pelo SGV
 * @param sgv   SGV a destruir
 */
void destroySGV(SGV sgv) {
    freeCat(sgv->prod);
    freeCat(sgv->cli);
    freeFact(sgv->fact);
    freeGFil(sgv->gfil);
    free(sgv->info);
    free(sgv);
}

/**
 * @brief       Função que retorna o numero de Produtos Validados
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Produtos Validados
 */
int getSGVprodV(SGV sgv) {
    return sgv->info->prodV;
}

/**
 * @brief       Função que retorna o numero de Produtos Lidos
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Produtos Lidos
 */
int getSGVprodL(SGV sgv) {
    return sgv->info->prodL;
}

/**
 * @brief       Função que retorna o numero de Clientes Validados
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Clientes Validados
 */
int getSGVcliV(SGV sgv) {
    return sgv->info->cliV;
}

/**
 * @brief       Função que retorna o numero de Clientes Lidos
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Clientes Lidos
 */
int getSGVcliL(SGV sgv) {
    return sgv->info->cliL;
}

/**
 * @brief       Função que retorna o numero de Vendas Validadas
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Vendas Validadas
 */
int getSGVsaleV(SGV sgv) {
    return sgv->info->saleV;
}

/**
 * @brief       Função que retorna o numero de Vendas Lidas
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Vendas Lidas
 */
int getSGVsaleL(SGV sgv) {
    return sgv->info->saleL;
}

/**
 * @brief       Função que retorna um apontador para Catalogo de Produtos
 * @param sgv   Estrutura SGV
 * @return      Apontador para Catalogo de Produtos
 */
void* getSGVProd(SGV sgv) {
    return sgv->prod;
}

/**
 * @brief       Função que retorna um apontador para Catalogo de Clientes
 * @param sgv   Estrutura SGV
 * @return      Apontador para Catalogo de Clientes
 */
void* getSGVCli(SGV sgv) {
    return sgv->cli;
}

/**
 * @brief       Função que retorna um apontador para GFiliais
 * @param sgv   Estrutura SGV
 * @return      Apontador para GFiliais
 */
void* getSGVGFiliais(SGV sgv) {
    return sgv->gfil;
}

/**
 * @brief       Função que retorna um apontador para THashFact
 * @param sgv   Estrutura SGV
 * @return      Apontador para THashFact
 */
void* getSGVFact(SGV sgv) {
    return sgv->fact;
}