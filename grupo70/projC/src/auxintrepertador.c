/**
 * @file  auxintrepertador.c
 * @brief Ficheiro que contém funções relativas ao módulo Auxinterpretador
 */

#include "auxintrepertador.h"

/**
 *@brief   função que verifica se uma String tem ou nao o carater espaço
 *@param s String a ser verificada
 *@return  inteiro booleano que representa a existência ou não do carater espaço na String
 */
int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}


/**
 *@brief        função que aplica as querie 1 e 13
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas as queries 1 e 13
 *@param buffer argumentos do comando utilizado para correr as queries 1 e 13
 *@param load   flag que indica se o sgv ja foi inicializado
 */
SGV runQuerie1e13(SGV sgv, char* buffer, int load) {
  char *c1 = NULL, *c2 = NULL, *c3 = NULL;
  clock_t start_t, end_t;

  if(!temEspaco(buffer)) {
    c1 = "../files/Clientes.txt";
    c2 = "../files/Produtos.txt";
    c3 = "../files/Vendas_1M.txt";
    }
  else {
    c1 = strsep(&buffer, " ");
    if(!temEspaco(buffer)){
      c2 = "../files/Produtos.txt";
      c3 = "../files/Vendas_1M.txt";
    }
    else {
      c2 = strsep(&buffer, " ");
      if(temEspaco(buffer))
        c3 = "../files/Vendas_1M.txt";

      else
        c3 = strsep(&buffer, "\n");
    }
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
 *@param buffer argumento do comando utilizado para correr a querie 2
 */
void runQuerie2(SGV sgv, char* buffer) {
    char *c1 = NULL;

    if(temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, "\n");

      Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
      printQ2(querie2, c1[0]);
      int i;

      for(i=0; i<querie2->size; i++) {
        free(querie2->prods[i]);
        querie2->prods[i] = NULL;
      }

      free(querie2);
      querie2 = NULL;
    }
}

/**
 *@brief        função que aplica a querie 3
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 3
 *@param buffer argumentos do comando utilizado para correr a querie 3
 */
void runQuerie3(SGV sgv, char* buffer){
    char *c1 = NULL, *c2 = NULL, *c3 = NULL;

    if(!temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, " ");

      if(!temEspaco(buffer))
        printf("Querie invalida\n");

      else {
        c2 = strsep(&buffer, " ");

        if(temEspaco(buffer))
          printf("Querie invalida\n");

        else {
          c3 = strsep(&buffer, "\n");

          Q3* querie3 = getProductSalesAndProfit(sgv, c1, atoi(c2), atoi(c3));
          printQ3(querie3, c1, atoi(c2));

          free(querie3);
          querie3 = NULL;
        }
      }
    }
}

/**
 *@brief        função que aplica a querie 4
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 4
 *@param buffer argumento do comando utilizado para correr a querie 4
 */
void runQuerie4(SGV sgv, char* buffer) {
  char *c1 = NULL;

  if(temEspaco(buffer))
    printf("Querie inválida\n");

  else {
    c1 = strsep(&buffer, "\n");

    Q4* querie4 = getProductsNeverBough(sgv, atoi(c1));
    printQ4(querie4);
    int i;

    for(i=0; i<querie4->size; i++) {
        free(querie4->prods[i]);
        querie4->prods[i] = NULL;
    }

    free(querie4);
    querie4 = NULL;
  }
}

/**
 *@brief        função que aplica a querie 5
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 5
 *@param tam    tamanho a partir do qual o comando é inválido
 */
void runQuerie5(SGV sgv, int tam) {
  if(tam>2)
    printf("Querie inválida\n");

  else {
    Q5* querie5 = getClientsOfAllBranches(sgv);
    int i;

    printQ5(querie5);

    for(i=0; i<querie5->size; i++) {
      printf(".\n");
      free(querie5->cli[i]);
    }

    free(querie5);
    querie5 = NULL;
  }
}

/**
 *@brief        função que aplica a querie 6
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 6
 *@param tam    tamanho a partir do qual o comando é inválido
 */
void runQuerie6(SGV sgv,int tam) {
    clock_t start_t, end_t;

    if(tam>2)
        printf("Querie inválida\n");

    else {
        start_t = clock();
        Q6* querie6 = getClientsAndProductsNeverBoughtCount(sgv);
        end_t = clock();

        printQ6(querie6, start_t, end_t);

        free(querie6);
        querie6 = NULL;
    }
}

/**
 *@brief        função que aplica a querie 7
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 7
 *@param buffer argumento do comando utilizado para correr a querie 7
 */
void runQuerie7(SGV sgv, char* buffer) {
    char *c1 = NULL;
    clock_t start_t, end_t;

    if(temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, "\n");

      start_t = clock();
      Q7* querie7 = getProductsBoughtByClient(sgv, c1);
      end_t = clock();

      printQ7(querie7, start_t, end_t);

      free(querie7);
      querie7 = NULL;
    }
}

/**
 *@brief        função que aplica a querie 8
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 8
 *@param buffer argumentos do comando utilizado para correr a querie 8
 */
void runQuerie8(SGV sgv, char* buffer) {
    char *c1 = NULL, *c2 = NULL;
    clock_t start_t, end_t;

    if(!temEspaco(buffer))
      printf("Querie inválida\n");

    else {
        c1 = strsep(&buffer, " ");
        if(temEspaco(buffer))
            printf("Querie invalida\n");

        else{
            c2 = strsep(&buffer, "\n");

            start_t = clock();
            Q8* querie8 = getSalesAndProfit(sgv, atoi(c1), atoi(c2));
            end_t = clock();

            printQ8(querie8, start_t, end_t);

            free(querie8);
            querie8 = NULL;
        }
    }
}

/**
 *@brief        função que aplica a querie 9
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 9
 *@param buffer argumentos do comando utilizado para correr a querie 9
 */
void runQuerie9(SGV sgv, char* buffer) {
    char *c1 = NULL, *c2 = NULL;
    clock_t start_t, end_t;

    if(!temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, " ");

      if(temEspaco(buffer))
        printf("Querie invalida\n");

      else {
        c2 = strsep(&buffer, "\n");

        start_t = clock();
        Q9* querie9 = getProductBuyers(sgv, c1, atoi(c2));
        end_t = clock();

        printQ9(querie9, atoi(c2), start_t, end_t);

        free(querie9->lista);
        querie9->lista = NULL;
        free(querie9);
        querie9 = NULL;
      }
    }
}

/**
 *@brief        função que aplica a querie 10
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 10
 *@param buffer argumentos do comando utilizado para correr a querie 10
 */
void runQuerie10(SGV sgv, char* buffer) {
  char *c1 = NULL,*c2 = NULL;
  clock_t start_t, end_t;

  if(!temEspaco(buffer))
    printf("Querie inválida\n");

  else {
    c1 = strsep(&buffer, " ");
    if(temEspaco(buffer))
      printf("Querie inválida\n");
    else {
      c2 = strsep(&buffer, "\n");

      start_t = clock();
      Q10* querie10 = getClientFavouriteProducts(sgv,c1,atoi(c2));
      end_t = clock();

      printQ10(querie10, start_t, end_t);

      free(querie10->produtos);
      querie10->produtos = NULL;
      free(querie10);
      querie10 = NULL;
    }
  }
}

/**
 *@brief        função que aplica a querie 11
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 11
 *@param buffer argumento do comando utilizado para correr a querie 11
 */
void runQuerie11(SGV sgv, char* buffer) {
  clock_t start_t, end_t;

  if(temEspaco(buffer))
    printf("Querie inválida\n");

  else {
    int i = atoi(buffer);
    start_t = clock();
    Q11* querie11 = getTopSelledProducts(sgv,i);
    end_t = clock();

    printQ11(querie11, start_t, end_t);

    free(querie11->produtos);
    querie11->produtos = NULL;
    free(querie11);
    querie11 = NULL;
  }
}

/**
 *@brief        função que aplica a querie 12
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 12
 *@param buffer argumentos do comando utilizado para correr a querie 12
 */
void runQuerie12(SGV sgv, char* buffer) {
  char *c1 = NULL, *c2 = NULL;
  clock_t start_t, end_t;

  if(!temEspaco(buffer))
    printf("Querie inválida\n");

  else{
    c1 = strsep(&buffer, " ");
    if(temEspaco(buffer))
      printf("Querie invalida\n");

    else{
      c2 = strsep(&buffer, "\n");
      start_t = clock();
      Q12* querie12 = getClientTopProfitProducts(sgv, c1, atoi(c2));
      end_t = clock();
      printQ12(querie12, start_t, end_t);

      free(querie12->prods);
      querie12->prods = NULL;
      free(querie12);
      querie12 = NULL;
    }
  }
}
