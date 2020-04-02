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

void intrepertador(SGV sgv) {
    int r=1, querie=-1, tam = 0;
    char *buffer = NULL, *s = NULL;
    buffer = malloc(MAX*sizeof(char));

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

        if(strcmp(s,"menu") == 0)
          menu();

        else if(atoi(s) != 1 && sgv -> load == 0)
          printf("O SGV ainda não foi carregado\n");

        else{
          querie = atoi(s);

          switch(querie) {
              case 0:
                  r=0;
                  printf("\nA Sair do Programa\n");
                  break;

              case 1:
                  runQuerie1(sgv, buffer);
                  break;

              case 2:
                  runQuerie2(sgv, buffer);
                  break;

              case 3:
                  runQuerie3(sgv, buffer);
                  break;

              case 4:
                  runQuerie4(sgv, buffer);
                  break;

              case 5:
                  if(tam>2) printf("Querie inválida\n");
                  break;

              case 6:
                  runQuerie6(sgv, buffer, tam);
                  break;

              case 7:
                  runQuerie7(sgv, buffer);
                  break;

              case 8:
                  runQuerie8(sgv, buffer);
                  break;

              case 9:
                  runQuerie9(sgv, buffer);
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
                  runQuerie13(sgv, buffer, tam);
                  break;

              default:
                  printf("Querie Inválida\n");
                  break;
          }
        }
    }
}
