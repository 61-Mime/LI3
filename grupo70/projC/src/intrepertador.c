#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "intrepertador.h"

#define MAX 100

void menu() {
    printf("\n- 0\n");
    printf("- 1 <pathProd> <pathCli> <pathSales>\n");
    printf("- 2 <letter>\n");
    printf("- 3 <prodID> <month> <type>\n");
    printf("- 4 <branchID>\n");
    printf("- 5\n");
    printf("- 6\n");
    printf("- 7 <clientID>\n");
    printf("- 8 <minMonth> <maxMonth>\n");
    printf("- 9 <productID> <branchID>\n");
    printf("- 10 <clientID> <month>\n");
    printf("- 11 <limit>\n");
    printf("- 12 <clientID> <limit>\n");
    printf("- 13\n");
}

int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

void intrepertador(SGV sgv) {
    int r=1, querie=-1, tam = 0;
    char *buffer = NULL, *s = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
    buffer = malloc(MAX*sizeof(char));
    clock_t start_t, end_t; 

    while(r)
    {
        printf("\nIntroduza menu, um comando para executar uma querie ou 0 para sair\n");
        printf("Introduza o seu comando: ");
        fgets(buffer, MAX, stdin);

        if(!temEspaco(buffer)) {
            s = strsep(&buffer, "\n");
            tam = strlen(buffer);
        }

        else
          s = strsep(&buffer, " ");

        if(strcmp(s,"menu") == 0) {
          menu();
        }

        else{
          querie = atoi(s);

          switch(querie) {
              case 0:
                  r=0;
                  printf("A Sair do Programa\n");
                  break;

              case 1:
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
                  
                  /*
                  if(sgv->load == 1) {
                    destroySGV(sgv);
                    sgv = initSGV();
                  }
                  */

                  start_t = clock();
                  loadSGVFromFiles(sgv, c1, c2, c3);
                  end_t = clock();

                  printQ1(start_t, end_t);

                  break;

              case 2:
                  if(temEspaco(buffer))
                    printf("Querie inválida\n");

                  else {
                    c1 = strsep(&buffer, "\n");

                    Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
                    printQ2(querie2, c1[0]);
                  }
                  break;

              case 3:
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
                  break;

              case 4:
                  if(temEspaco(buffer))
                    {printf("Querie inválida\n");
                    break;}
                  else{
                    char* c1 = strsep(&buffer, "\n");
                    printf("done\n%s\n", c1);
                    //querie4(c1);
                  }
                  break;

              case 5:
                  if(tam>2) printf("Querie inválida\n");
                  break;

              case 6:
                  if(tam>2) 
                    printf("Querie inválida\n");

                  else {
                    printf(".");
                  }

                  break;

              case 7:
                  if(temEspaco(buffer))
                    printf("Querie inválida\n");

                  else {
                    c1 = strsep(&buffer, "\n");

                    start_t = clock();
                    Q7* querie7 = getProductsBoughtByClient(sgv, c1);
                    end_t = clock();

                    printQ7(querie7, start_t, end_t);
                  }
                  break;

              case 8:
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
                  break;

              case 9:
                  if(!temEspaco(buffer))
                    {printf("Querie inválida\n");
                    break;}
                  else{
                    char* c1 = strsep(&buffer, " ");
                    if(temEspaco(buffer))
                      {printf("Querie invalida\n");
                      break;}
                    else{
                      char* c2 = strsep(&buffer, "\n");
                      printf("done\n%s %s\n", c1, c2);
                      //getProductBuyers(sgv, c1, c2);
                    }
                  }
                  break;

              case 10:
                  if(!temEspaco(buffer))
                    {printf("Querie inválida\n");
                    break;}
                  else{
                    char* c1 = strsep(&buffer, " ");
                    if(temEspaco(buffer))
                      {printf("Querie invalida\n");
                      break;}
                    else{
                      char* c2 = strsep(&buffer, "\n");
                      printf("done\n%s %s\n", c1, c2);
                      //querie10(c1, c2);
                    }
                  }
                  break;

              case 11:
                  if(temEspaco(buffer))
                    {printf("Querie inválida\n");
                    break;}
                  else{
                    char* c1 = strsep(&buffer, "\n");
                    printf("done\n%s\n", c1);
                    //querie11(c1);
                  }
                  break;

              case 12:
                  if(!temEspaco(buffer))
                    {printf("Querie inválida\n");
                    break;}
                  else{
                    char* c1 = strsep(&buffer, " ");
                    if(temEspaco(buffer))
                      {printf("Querie invalida\n");
                      break;}
                    else{
                      char* c2 = strsep(&buffer, "\n");
                      printf("done\n%s %s\n", c1, c2);
                      //querie12(c1, c2);
                    }
                  }
                  break;

              case 13:
                  if(tam>3) 
                    printf("Querie inválida\n");

                  else {
                    Q13* querie13 = getCurrentFilesInfo(sgv);
                    printQ13(querie13);
                  }
                  break;

              default:
                  printf("Querie Inválida\n");
                  break;
          }
        }
    }
}
