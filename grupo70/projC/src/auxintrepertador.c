/**
 * @file  auxintrepertador.c
 * @brief Ficheiro que contém funções relativas ao módulo Auxinterpretador
 */

#include "auxintrepertador.h"

#define MAX 100
#define SMAX 30

/**
 *@brief        função que aplica as querie 1 e 13
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas as queries 1 e 13
 *@param load   flag que indica se o sgv ja foi inicializado
 */
SGV runQuerie1e13(SGV sgv, int load) {
    clock_t start_t, end_t;
    char buffer[MAX], c1[SMAX], c2[SMAX], c3[SMAX];
    int res;

    printf("\nIntroduza o caminho para os três ficheiros:\n");
    fgets(buffer, MAX, stdin);

    if(buffer[0]=='\0') {
      strcpy(c1, "../files/Clientes.txt");
      strcpy(c2, "../files/Produtos.txt");
      strcpy(c3, "../files/Vendas_1M.txt");
    }    

    else
      res = sscanf(buffer, "%s %s %s", c1, c2, c3);

    if(fopen(c1, "r")==NULL) {
      perror(c1);
      return NULL;
    }

    else if(fopen(c2, "r")==NULL) {
      perror(c2);
      return NULL;
    }

    else if(fopen(c3, "r")==NULL) {
      perror(c3);
      return NULL;
    }

    if(load==1)
      destroySGV(sgv);

    start_t = clock();
    sgv = loadSGVFromFiles(sgv, c1, c2, c3);
    end_t = clock();

    Q13* querie13 = getCurrentFilesInfo(sgv, c1, c2, c3);

    printQ1(start_t, end_t);
    printQ13(querie13);

    free(querie13);
    querie13 = NULL;

  return sgv;
}

/**
 *@brief        função que aplica a querie 2
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 2
 */
void runQuerie2(SGV sgv) {
    char c1, buffer[MAX], res;
    int i;

    printf("\nIntroduza o carater inicial do Produto (Maiúsculo):\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%c", c1);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }

    Q2* querie2 = getProductsStartedByLetter(sgv, c1);
    printQ2(querie2, c1);

    for(i=0; i<querie2->size; i++) {
      free(querie2->prods[i]);
      querie2->prods[i] = NULL;
    }

    free(querie2);
    querie2 = NULL;
}

/**
 *@brief        função que aplica a querie 3
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 3
 */
void runQuerie3(SGV sgv){
    char *c = NULL;
    int mes, type, res;
    char buffer[MAX];

    printf("Introduza um produto, um mes e um 0/1 (0-Resultados Globais / 1-Resultados por Filial):\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%s %d %d", c, mes, type);

    if(res == 0) {
      printf("Argumentos inválidos\n");
      return;
    }

    Q3* querie3 = getProductSalesAndProfit(sgv, c, mes, type);
    printQ3(querie3, c, mes);

    free(querie3);
    querie3 = NULL;

}

/**
 *@brief        função que aplica a querie 4
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 4
 */
void runQuerie4(SGV sgv) {
  int i, filial, res;
  char buffer[MAX];

  printf("Introduza uma filial (1 a 3) ou 0 se pretender os resultados globais:\n");
  fgets(buffer, MAX, stdin);
  res = sscanf(buffer, "%d", filial);

  if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }

  Q4* querie4 = getProductsNeverBough(sgv, filial);
  printQ4(querie4);

  for(i=0; i<querie4->size; i++) {
      free(querie4->prods[i]);
      querie4->prods[i] = NULL;
  }

  free(querie4);
  querie4 = NULL;
}

/**
 *@brief        função que aplica a querie 5
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 5
 */
void runQuerie5(SGV sgv) {
  int i;

  Q5* querie5 = getClientsOfAllBranches(sgv);
  printQ5(querie5);

  for(i=0; i<querie5->size; i++) {
    free(querie5->cli[i]);
  }

  free(querie5);
  querie5 = NULL;
}

/**
 *@brief        função que aplica a querie 6
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 6
 */
void runQuerie6(SGV sgv) {
    clock_t start_t, end_t;

    start_t = clock();
    Q6* querie6 = getClientsAndProductsNeverBoughtCount(sgv);
    end_t = clock();

    printQ6(querie6, start_t, end_t);

    free(querie6);
    querie6 = NULL;
}

/**
 *@brief        função que aplica a querie 7
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 7
 */
void runQuerie7(SGV sgv) {
    char *c1 = NULL, buffer[MAX];
    int res;
    clock_t start_t, end_t;

    printf("Introduza um código de Cliente:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%s", c1);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }
    
    start_t = clock();
    Q7* querie7 = getProductsBoughtByClient(sgv, c1);
    end_t = clock();

    printQ7(querie7, start_t, end_t);

    free(querie7);
    querie7 = NULL;
    
}

/**
 *@brief        função que aplica a querie 8
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 8
 */
void runQuerie8(SGV sgv) {
    char buffer[MAX];
    int minMonth, maxMonth, res;
    clock_t start_t, end_t;

    printf("Introduza um mes mínimo e um mes máximo:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%d %d", minMonth, maxMonth);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }

    start_t = clock();
    Q8* querie8 = getSalesAndProfit(sgv, minMonth, maxMonth);
    end_t = clock();

    printQ8(querie8, start_t, end_t);

    free(querie8);
    querie8 = NULL;
}

/**
 *@brief        função que aplica a querie 9
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 9
 */
void runQuerie9(SGV sgv) {
    char *c1 = NULL, buffer[MAX];
    int filial, res;
    clock_t start_t, end_t;

    printf("Introduza um código de Produto e uma Filial:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%s %d", c1, filial);

    if(res == 0) {
      printf("Argumentos inválidos\n");
      return;
    }    

    start_t = clock();
    Q9* querie9 = getProductBuyers(sgv, c1, filial);
    end_t = clock();

    printQ9(querie9, filial, start_t, end_t);

    free(querie9->lista);
    querie9->lista = NULL;
    free(querie9);
    querie9 = NULL;
}

/**
 *@brief        função que aplica a querie 10
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 10
 */
void runQuerie10(SGV sgv) {
    char *c1 = NULL, buffer[MAX];
    int res, mes;
    clock_t start_t, end_t;

    printf("Introduza um código de Cliente e um mes:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%d", c1, mes);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }  

    start_t = clock();
    Q10* querie10 = getClientFavouriteProducts(sgv,c1,mes);
    end_t = clock();

    printQ10(querie10, start_t, end_t);

    free(querie10->produtos);
    querie10->produtos = NULL;
    free(querie10);
    querie10 = NULL;
}

/**
 *@brief        função que aplica a querie 11
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 11
 */
void runQuerie11(SGV sgv) {
    clock_t start_t, end_t;
    char buffer[MAX];
    int limit, res;

    printf("Introduza o número limite de Produtos a apresentar:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%d", limit);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }

    start_t = clock();
    Q11* querie11 = getTopSelledProducts(sgv, limit);
    end_t = clock();

    printQ11(querie11, start_t, end_t);

    free(querie11->produtos);
    querie11->produtos = NULL;
    free(querie11);
    querie11 = NULL;
}

/**
 *@brief        função que aplica a querie 12
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 12
 */
void runQuerie12(SGV sgv) {
    char *c1 = NULL, buffer[MAX];
    int res, limit;
    clock_t start_t, end_t;

    printf("Introduza um código de Cliente e o número máximo de produtos a apresentar:\n");
    fgets(buffer, MAX, stdin);
    res = sscanf(buffer, "%s %d", c1, limit);

    if(res == 0) {
      printf("Argumento inválido\n");
      return;
    }
  
    start_t = clock();
    Q12* querie12 = getClientTopProfitProducts(sgv, c1, limit);
    end_t = clock();
    printQ12(querie12, start_t, end_t);

    free(querie12->prods);
    querie12->prods = NULL;
    free(querie12);
    querie12 = NULL;
}
