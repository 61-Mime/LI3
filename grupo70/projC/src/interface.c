#include "interface.h"

#define MAX 100

void intrepertador(SGV sgv) {
    int r=1, querie=-1, tam = 0;
    char *buffer = NULL, *s = NULL;
    buffer = malloc(MAX*sizeof(char));

    system("clear");

    while(r) {
        printf("\nIntroduza menu, um comando para executar uma querie ou 'Q' para sair\n");
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

        else if(strcmp(s,"q")==0 || strcmp(s,"Q")==0)
          r=0;

        /*
        else if(atoi(s)!=1 && atoi(s)!=0 && (*load)==0)
          printf("O SGV ainda não foi carregado\n");
        */

        else switch((querie = atoi(s))) {
              case 1:
                  runQuerie1e13(sgv, buffer);
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
                  runQuerie5(sgv, tam);
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
}
