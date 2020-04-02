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
                  
  if(sgv->load == 1) {
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
  
  if(sgv->load == 1){
    if(!temEspaco(buffer))
      printf("Querie inválida\n");

    else {
      c1 = strsep(&buffer, "\n");

      Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
      printQ2(querie2, c1[0]);
    }
  }

  else
    printf("O SGV ainda não foi carregado\n");
}

void runQuerie3(SGV sgv, char* buffer){
  char *c1 = NULL, *c2 = NULL, *c3 = NULL;

  if(sgv->load == 1) {
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

  else
    printf("O SGV ainda não foi carregado\n");
}

void runQuerie6(SGV sgv, char* buffer, int tam) {
    clock_t start_t, end_t;

    if(sgv->load == 1) {
        if(tam>2) 
            printf("Querie inválida\n");

        else {
            start_t = clock();
            Q6* querie6 = getClientsAndProductsNeverBoughtCount(sgv);
            end_t = clock();

            printQ6(querie6, start_t, end_t);
        }
    }  

    else 
        printf("O SGV ainda não foi carregado\n");
}

void runQuerie7(SGV sgv, char* buffer) {
  char *c1 = NULL;
  clock_t start_t, end_t;

  if(sgv->load == 1) {
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

  else
    printf("O SGV ainda não foi carregado\n");
}

void runQuerie8(SGV sgv, char* buffer) {
    char *c1 = NULL, *c2 = NULL;
    clock_t start_t, end_t;
    
    if(sgv->load == 1) {
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

    else
        printf("O SGV ainda não foi carregado\n");
}

void runQuerie9(SGV sgv, char* buffer) {
    char *c1 = NULL, *c2 = NULL;
    clock_t start_t, end_t;
    
    if(sgv->load == 1) {
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

    else
        printf("O SGV ainda não foi carregado\n");
}

void runQuerie13(SGV sgv, char* buffer, int tam) {
    if(sgv->load == 1) {
        if(tam>3) 
          printf("Querie inválida\n");

        else {
          Q13* querie13 = getCurrentFilesInfo(sgv);
          printQ13(querie13);
        }
    }

    else
        printf("O SGV ainda não foi carregado\n");
}