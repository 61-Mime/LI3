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
  for(i=0; s[i] && r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

void intrepertador(SGV sgv) {
    int r=1, querie=-1;
    char *buffer = NULL;
    buffer = malloc(MAX*sizeof(char));
    char* s = NULL;

    while(r)
    {
        menu();
        fgets(buffer, MAX, stdin);
        //sscanf(buffer, "%d", &querie);

        if(!temEspaco(buffer))
          s = strsep(&buffer, "\n");
        else
          s = strsep(&buffer, " ");

        querie = atoi(s);

        switch(querie) {
            case 0:
                r=0;
                break;

            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            case 11:
                break;

            case 12:
                break;

            case 13:
                break;

            default:
                printf("Querie Inválida\n");
                break;
        }
    }
}
