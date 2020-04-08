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
    char *buffer = malloc(MAX*sizeof(char)), *s = NULL, *aux=NULL;

    system("clear");

    while(r) {
        printf("\nIntroduza menu, um comando para executar uma querie ou 'Q' para sair\n");
        printf("Introduza o seu comando: ");
        fgets(buffer, MAX, stdin);

        aux = buffer;

        if(!temEspaco(aux)) {
            s = strsep(&aux, "\n");
            tam = strlen(aux);
        }

        else
          s = strsep(&aux, " ");

        if(strcmp(s,"menu") == 0)
          menu();

        else if(strcmp(s,"q")==0 || strcmp(s,"Q")==0)
          r=0;

        else if(atoi(s)!=1 && atoi(s)!=0 && load==0)
          printf("O SGV ainda não foi carregado\n");

        else switch((querie = atoi(s))) {
              case 1:
                  sgv = runQuerie1e13(sgv, aux, load);
                  load = 1;
                  break;

              case 2:
                  runQuerie2(sgv, aux);
                  break;

              case 3:
                  runQuerie3(sgv, aux);
                  break;

              case 4:
                  runQuerie4(sgv, aux);
                  break;

              case 5:
                  runQuerie5(sgv, tam);
                  break;

              case 6:
                  runQuerie6(sgv, tam);
                  break;

              case 7:
                  runQuerie7(sgv, aux);
                  break;

              case 8:
                  runQuerie8(sgv, aux);
                  break;

              case 9:
                  runQuerie9(sgv, aux);
                  break;

              case 10:
                  runQuerie10(sgv, aux);
                  break;

              case 11:
                  runQuerie11(sgv, aux);
                  break;

              case 12:
                  runQuerie12(sgv, aux);
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
