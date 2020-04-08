/**
 * @file  interface.c
 * @brief Ficheiro que contém funções relativas ao módulo Interface
 */

#include "interface.h"

#define MAX 100

/**
 *@brief função que define o interpretador
 *@param sgv sistema de gestão de vendas a ser interpretado
 */
void intrepertador(SGV sgv) {
    int r=1, querie=-1, tam = 0, load=0;
    char *buffer = malloc(MAX*sizeof(char)), *s = NULL;

    system("clear");

    welcome();
    menu();

    while(r) {
        printf("\n\nIntroduza o seu comando: ");
        fgets(buffer, MAX, stdin);

        if(!temEspaco(buffer)) {
            s = strtok(buffer, "\n");
            tam = strlen(buffer);
        }

        else
          s = strtok(buffer, " ");

        printf("%s\n", s);
       if(strcmp(s,"menu") == 0)
          menu();

        else if(strcmp(s,"q")==0 || strcmp(s,"Q")==0)
          r=0;

        else if(atoi(s)!=1 && atoi(s)!=0 && load==0)
          printf("O SGV ainda não foi carregado\n");

        else switch((querie = atoi(s))) {
              case 1:
                  sgv = runQuerie1e13(sgv, load);
                  if(sgv != NULL)
                    load = 1;
                  else
                    load = 0;
                  break;

              case 2:
                  runQuerie2(sgv);
                  break;

              case 3:
                  runQuerie3(sgv, buffer);
                  break;

              case 4:
                  runQuerie4(sgv, buffer);
                  break;

              case 5:
                  runQuerie5(sgv, tam);
                  break;

              case 6:
                  runQuerie6(sgv, tam);
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
                  runQuerie10(sgv, buffer);
                  break;

              case 11:
                  runQuerie11(sgv, buffer);
                  break;

              case 12:
                  runQuerie12(sgv, buffer);
                  break;

              default:
                  printf("Comando inválido\n");
                  break;
          }
    }

    printf("\nA Sair do Programa\n");

    free(buffer);
    buffer = NULL;
}
