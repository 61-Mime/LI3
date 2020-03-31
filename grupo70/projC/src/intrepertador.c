#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intrepertador.h"

#define MAX 100

void menu() {
    printf("\n- 0\n");
    printf("- 1 <pathProd> <pathCli> <pathSales>\n");
    printf("- 2 <letter>\n");
    printf("- 3 <prodID> <month>\n");
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
    printf("Introduza o seu comando: ");
}

int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

void intrepertador(SGV sgv) {
    int r=1, querie=-1, tam = 0;
    char *buffer = NULL;
    buffer = malloc(MAX*sizeof(char));
    char* s = NULL;

    while(r)
    {
        menu();
        fgets(buffer, MAX, stdin);
        //sscanf(buffer, "%d", &querie);

        if(!temEspaco(buffer)) {
            tam = strlen(buffer);
            s = strsep(&buffer, "\n");
        }
        else
          s = strsep(&buffer, " ");

        querie = atoi(s);

        switch(querie) {
            case 0:
                r=0;
                break;

            case 1:
                if(!temEspaco(buffer))
                  {printf("Querie inválida\n");
                  break;}
                else{
                  char* c1 = strsep(&buffer, " ");
                  if(!temEspaco(buffer)){
                    printf("Querie inválida\n");
                    break;
                  }
                  else {
                    char* c2 = strsep(&buffer, " ");
                    if(temEspaco(buffer)){
                      printf("Querie inválida\n");
                      break;
                    }
                    else {
                      char* c3 = strsep(&buffer, "\n");
                      printf("done\n%s %s %s\n", c1, c2, c3);
                      //querie1(c1, c2, c3);
                    }
                  }
                }
                break;

            case 2:
                if(temEspaco(buffer))
                  {printf("Querie inválida\n");
                  break;}
                else{
                  char* c1 = strsep(&buffer, "\n");
                  printf("done\n%s\n", c1);

                //getProductsStartedByLetter(sgv, c1);
                }
                break;

            case 3:
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
                    //querie3(c1,c2);
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
                //else {querie5();}
                break;

            case 6:
                if(tam>2) printf("Querie inválida\n");
                //else {getClientsAndProductsNeverBoughtCount(sgv);}
                break;

            case 7:
                if(temEspaco(buffer))
                  {printf("Querie inválida\n");
                  break;}
                else{
                  char* c1 = strsep(&buffer, "\n");
                  printf("done\n%s\n", c1);
                  //getProductsBoughtByClient(sgv, c1);
                }
                break;

            case 8:
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
                    //getSalesAndProfit(sgv, c1, c2));
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
                //querie13();
                break;

            default:
                printf("Querie Inválida\n");
                break;
        }
    }
}
