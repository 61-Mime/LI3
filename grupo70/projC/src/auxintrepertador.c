#include "auxintrepertador.h"

int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

void runQuerie1e13(SGV sgv, char* buffer, int load) {
  char *c1 = NULL, *c2 = NULL, *c3 = NULL;
  clock_t start_t, end_t;

  if(!temEspaco(buffer)) {
    c1 = "/Users/luissobral/grupo70/grupo70/projC/files/Clientes.txt";
    c2 = "/Users/luissobral/grupo70/grupo70/projC/files/Produtos.txt";
    c3 = "/Users/luissobral/grupo70/grupo70/projC/files/Vendas_1M.txt";
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

  if(load==1) {
    destroySGV(sgv);
    sgv = initSGV();
  }

  start_t = clock();
  sgv = loadSGVFromFiles(sgv, c1, c2, c3);
  end_t = clock();

  Q13* querie13 = getCurrentFilesInfo(sgv, c1, c2, c3);

  printQ1(start_t, end_t);
  printQ13(querie13);

  free(querie13);
  querie13 = NULL;
}

void runQuerie2(SGV sgv, char* buffer) {
    char *c1 = NULL;

    if(temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, "\n");

      Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
      printQ2(querie2, c1[0]);

      for(int i=0; i<querie2->size; i++) {
        free(querie2->prods[i]);
        querie2->prods[i] = NULL;
      }

      free(querie2);
      querie2 = NULL;
    }
}

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

void runQuerie4(SGV sgv, char* buffer) {
  char *c1 = NULL;

  if(temEspaco(buffer))
    printf("Querie inválida\n");

  else {
    c1 = strsep(&buffer, "\n");

    Q4* querie4 = getProductsNeverBough(sgv, atoi(c1));
    printQ4(querie4);

    for(int i=0; i<querie4->size; i++) {
        free(querie4->prods[i]);
        querie4->prods[i] = NULL;
    }

    free(querie4);
    querie4 = NULL;
  }
}

void runQuerie5(SGV sgv, int tam) {
  if(tam>2)
    printf("Querie inválida\n");

  else {
    Q5* querie5 = getClientsOfAllBranches(sgv);

    printQ5(querie5);

    for(int i=0; i<querie5->size; i++) {
      free(querie5->cli[i]);
      querie5 = NULL;
    }

    free(querie5);
    querie5 = NULL;
  }
}

void runQuerie6(SGV sgv, char* buffer, int tam) {
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
