/**
 * @file  interface.c
 * @brief Ficheiro que contém funções relativas ao módulo Interface
 */

#include "interface.h"

#define MAX 100

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
 *@brief função que define o interpretador
 *@param sgv sistema de gestão de vendas a ser interpretado
 */
void intrepertador(SGV sgv) {
    int r=1, querie=0, load=0;
    char *buffer = malloc(MAX*sizeof(char));

    welcome();
    menu();

    while(r) {
        printf("\n\nIntroduza o seu comando: ");
        fgets(buffer, MAX, stdin);

        if(temEspaco(buffer))
            printf("Comando inválido\n");
        
        else {
            buffer = strtok(buffer, "\n");

            if(strcmp(buffer, "menu") == 0)
              menu();

            else if(strcmp(buffer, "q")==0 || strcmp(buffer, "Q")==0)
              r=0;

            else if(atoi(buffer)!=1 && atoi(buffer)!=0 && load==0)
              printf("O SGV ainda não foi carregado\n");

            else switch((querie = atoi(buffer))) {
                  case 1:
                      sgv = runQuerie1e13(sgv, load);
                      if(sgv == NULL)
                        load = 0;
                      else
                        load = 1;
                      break;

                  case 2:
                      runQuerie2(sgv);
                      break;

                  case 3:
                      runQuerie3(sgv);
                      break;

                  case 4:
                      runQuerie4(sgv);
                      break;

                  case 5:
                      runQuerie5(sgv);
                      break;

                  case 6:
                      runQuerie6(sgv);
                      break;

                  case 7:
                      runQuerie7(sgv);
                      break;

                  case 8:
                      runQuerie8(sgv);
                      break;

                  case 9:
                      runQuerie9(sgv);
                      break;

                  case 10:
                      runQuerie10(sgv);
                      break;

                  case 11:
                      runQuerie11(sgv);
                      break;

                  case 12:
                      runQuerie12(sgv);
                      break;

                  default:
                      printf("Comando inválido\n");
                      break;
              }
        }
    }

    printf("\nA Sair do Programa\n");

    free(buffer);
    buffer = NULL;
}
