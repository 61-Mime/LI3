/**
 * @file  faturacao.c
 * @brief Ficheiro que contém funções relativas ao módulo Faturacao
 */

#include "faturacao.h"

#define SIZE 26
#define SMAX 10

typedef struct factM {
  int vendasN;
  int vendasP;
  float facturacaoN;
  float facturacaoP;
  int unidades;
} FMensal;

typedef struct fact {
  char* prod;
  int ocup;
  FMensal mesfilial[12][3];
} Facturacao;

typedef struct Tfact {
  int size;
  Facturacao *list;
} TFacturacao;

typedef struct thashfact {
  TFacturacao* tbl;
} THashFact;

/**
 *@brief  função que inicializa a estrutura THashFact
 *@return apontador para THashFact
 */
THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));
  fact->tbl = malloc(sizeof(TFacturacao) * SIZE);
  int i;

  for(i=0; i<SIZE; i++) {
    fact->tbl[i].size = 0;
    fact->tbl[i].list = NULL;
  }

  return fact;
}

/**
 *@brief      função que inicializa a estrutura TFacturacao
 *@param fact apontador para THashFact
 *@param i    posição da tabela a inicializar
 *@param size tamanho TFacturacao
 */
static void initTFacturacao(THashFact* fact, int i, int size) {
  TFacturacao* f = &fact->tbl[i];

  f->list = malloc(sizeof(Facturacao)*size);
  f->size = size;
}

/**
 *@brief      função que inicializa a estrutura Facturacao e a estrutura Fmensal para cada filial
 *@param fact apontador para THash
 *@param i    posição da Tabela
 *@param j    posição da Lista
 *@param key  String com o produto
 */
static void initFacturacao(THashFact* fact, int i, int j, char* key) {
  Facturacao *f = &fact->tbl[i].list[j];

  f->prod = malloc(sizeof(char) * SMAX);
  strcpy(f->prod, key);
  f->ocup = 0;

  for(i=0; i<12; i++)
    for(j=0 ; j<3; j++) {
      f->mesfilial[i][j].vendasN = 0;
      f->mesfilial[i][j].vendasP = 0;
      f->mesfilial[i][j].facturacaoN = 0;
      f->mesfilial[i][j].facturacaoP = 0;
      f->mesfilial[i][j].unidades = 0;
    }
}

/**
 *@brief      função que carrega as estrutura faturacao com todos os produtos
 *@param fact apontador para THashFact
 *@param prod apontador para catálogo de produtos
 */
void loadFactFromCat(THashFact* fact, Catalogo* prod) {
  int i, j, size;

  for(i=0; i<SIZE; i++) {
    size = getCatListSize(prod, i);
    initTFacturacao(fact, i, size);

    for(j=0; j<size; j++)
      initFacturacao(fact, i, j, getCatKey(prod, i, j));
  }
}

/**
 * @brief        Função adiciona uma venda a THashFact
 * @param fact   Apontador para THashFact
 * @param hash   Posição da tabela a adicionar
 * @param pos    Posicao da lista a adicionar
 * @param month  mês ao qual vai ser adicionado a venda
 * @param branch filial à qual vai ser adicionada a venda
 * @param type   tipo da venda
 * @param price  preço do produto da venda
 * @param uni    quantidade de produtos da venda
 */
void addFact(THashFact* fact, int hash, int pos, int month, int branch, char type, float price, int uni) {
  FMensal* f = &fact->tbl[hash].list[pos].mesfilial[month-1][branch-1];

  if(type == 'N') {
    f->vendasN ++;
    f->facturacaoN += (price * uni);
  }

  else {
    f->vendasP ++;
    f->facturacaoP += (price * uni);
  }

  f->unidades += uni;

  if(fact->tbl[hash].list[pos].ocup == 0) fact->tbl[hash].list[pos].ocup = 1;
}

/**
  *@brief      função que liberta o espaço ocupado pela THashFact
  *@param fact apontador para THashFact
  */
void freeFact(THashFact* fact) {
    int i, j;

    for(i=0; i<SIZE; i++) {
        for(j=0; j<fact->tbl[i].size; j++) {
          free(fact->tbl[i].list[j].prod);
          fact->tbl[i].list[j].prod = NULL;
        }
        free(fact->tbl[i].list);
        fact->tbl[i].list = NULL;
    }
    free(fact->tbl);
    fact->tbl = NULL;

    free(fact);
    fact = NULL;
}

/*GETTERS*/

/**
  *@brief        função que devolve o número de vendas em regime normal de uma determinada filial num determinado mês
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@param j      posição da lista a obter
  *@param month  mês a obter
  *@param branch filial a obter
  *@return       inteiro que representa o número de vendas N de uma filial num mês
  */
int getFatVendasN(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].vendasN;
}

/**
  *@brief        função que devolve o número de vendas em regime de promoção de uma determinada filial num determinado mês
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@param j      posição da lista a obter
  *@param month  mês a obter
  *@param branch filial a obter
  *@return       inteiro que representa o número de vendas P de uma filial num mês
  */
int getFatVendasP(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].vendasP;
}

/**
  *@brief        função que devolve a faturação de vendas em regime normal de uma determinada filial num determinado mês
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@param j      posição da lista a obter
  *@param month  mês a obter
  *@param branch filial a obter
  *@return       float que representa a faturação de vendas N de uma filial num mês
  */
float getFatFaturacaoN(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].facturacaoN;
}

/**
  *@brief        função que devolve a faturação de vendas em regime de promoção de uma determinada filial num determinado mês
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@param j      posição da lista a obter
  *@param month  mês a obter
  *@param branch filial a obter
  *@return       float que representa a faturação de vendas P de uma filial num mês
  */
float getFatFaturacaoP(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].facturacaoP;
}

/**
  *@brief        função que devolve o número de unidades vendidas de uma determinada filial num determinado mês
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@param j      posição da lista a obter
  *@param month  mês a obter
  *@param branch filial a obter
  *@return       inteiro que representa as unidades vendidas de uma filial num mês
  */
int getFatUnidades(THashFact* fact, int i, int j, int month, int branch) {
  return fact->tbl[i].list[j].mesfilial[month][branch].unidades;
}

/**
  *@brief        função que devolve o tamanho da lista de Facturacao
  *@param fact   apontador para THashFact
  *@param i      posição da tabela a obter
  *@return       inteiro que representa o tamanho da lista de Facturacao
  */
int getFatListSize(THashFact* fact, int i) {
  return fact->tbl[i].size;
}

/**
 *@brief      função que devolve o número de ocupados da lista
 *@param fact apontador +ara THashFact
 *@param i    posição da Tabela
 *@param j    posição da Lista
 *@return     inteiro que representa o número de ocupados da lista
 */
int getFatOcup(THashFact* fact, int i, int j) {
  return fact->tbl[i].list[j].ocup;
}
