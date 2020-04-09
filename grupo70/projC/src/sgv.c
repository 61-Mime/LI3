/**
 * @file    sgv.c
 * @brief   Ficheiro que contém funções relativas ao módulo SGV
 */

#include "sgv.h"

/**
 *@brief Estrutura com a informação do carregamento dos ficheiros
 */
typedef struct filesinfo {
    int prodV;
    int prodL;
    int cliV;
    int cliL;
    int saleV;
    int saleL;
} FileInfo;

/**
 *@brief Estrutura do Sistema de Gestão de Vendas, com a informação necessária para a execução do programa
 */
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
static FileInfo* initFileInfo() {
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
static SGV initSGV() {
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

int getCListsize(SGV sgv,int hash,int type) {
  if(type == 0)
    return getCatListSize(sgv->prod,hash);

  return getCatListSize(sgv->cli,hash);
}

char* getCKey(SGV sgv,int type,int i,int j) {
  if(type == 0)
    return getCatKey(sgv->prod,i,j);

  return getCatKey(sgv->cli,i,j);
}

int getPos(SGV sgv,int type,char *buffer) {
  if(type == 0)
    return searchCat(buffer,sgv->prod);

  return searchCat(buffer,sgv->cli);
}

int getFVendasN(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatVendasN(sgv->fact,hash,pos,branch,mes);
}

int getFVendasP(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatVendasP(sgv->fact,hash,pos,branch,mes);
}

float getFFaturacaoN(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatFaturacaoN(sgv->fact,hash,pos,branch,mes);
}

float getFFaturacaoP(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatFaturacaoP(sgv->fact,hash,pos,branch,mes);
}

void* getSGVGFiliais(SGV sgv) {
  return sgv->gfil;
}

void* getSGVCli(SGV sgv) {
  return sgv->cli;
}

void* getSGVFact(SGV sgv) {
  return sgv->fact;
}

void* getSGVProd(SGV sgv) {
  return sgv->prod;
}
