#include "auxintrepertador.h"

int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

void runQuerie1(SGV sgv, char* buffer) {
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

  if(sgv->load==1) {
    destroySGV(sgv);
    sgv = initSGV();
  }

  start_t = clock();
  loadSGVFromFiles(sgv, c1, c2, c3);
  end_t = clock();

  printQ1(start_t, end_t);
}

void runQuerie2(SGV sgv, char* buffer) {
    char *c1 = NULL;

    if(temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, "\n");

      Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
      printQ2(querie2, c1[0]);
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
  }
}

void runQuerie5(SGV sgv, int tam) {
  if(tam>2) 
    printf("Querie inválida\n");

  else {
    Q5* querie5 = getClientsOfAllBranches(sgv);

    printQ5(querie5);
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
    }
  }
}

void runQuerie11(SGV sgv, char* buffer) {
  char *c1 = NULL;
  
  if(temEspaco(buffer))
    printf("Querie inválida\n");

  else{
    c1 = strsep(&buffer, "\n");
    printf("done\n%s\n", c1);
  }
}

void runQuerie12(SGV sgv, char* buffer) {
  char *c1 = NULL, *c2 = NULL;
  
  if(!temEspaco(buffer))
    printf("Querie inválida\n");

  else{
    c1 = strsep(&buffer, " ");
    if(temEspaco(buffer))
      printf("Querie invalida\n");

    else{
      c2 = strsep(&buffer, "\n");
      printf("done\n%s %s\n", c1, c2);
    }
}
}

void runQuerie13(SGV sgv, char* buffer, int tam) {
    if(tam>3)
      printf("Querie inválida\n");

    else {
      Q13* querie13 = getCurrentFilesInfo(sgv);
      printQ13(querie13);
    }
}
