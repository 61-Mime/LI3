#include "apresentacao.h"

void menu() {
    system("clear");
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

void printQ1(clock_t start_t, clock_t end_t) {
    system("clear");

    printf("\nTempo de execução da Querie 1: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ2(Q2* querie2, char letter) {
    int i;

    system("clear");

    for(i=0; i<querie2->size; i++)
        printf("(%d) %s\n", i, querie2->prods[i]);

    printf("Numero de Produtos começados por %c: %d\n", letter, querie2->size);
}

void printQ3(Q3* querie3, char* prodID, int month) {
    int i;

    system("clear");

    if(querie3->size == 1) {
        printf("\nFaturação do produto %s no mês %d\n", prodID, month);
        printf("Número de vendas N: %d\n", querie3->fat->nVendasN);
        printf("Número de vendas P: %d\n", querie3->fat->nVendasP);
        printf("Total Faturado N: %f\n", querie3->fat->fatN);
        printf("Total Faturado P: %f\n", querie3->fat->fatP);
    }

    else {
        for(i=0; i<3; i++) {
            printf("\nFaturação do produto %s no mês %d para a Filial %d\n", prodID, month, i+1);
            printf("Número de vendas N: %d\n", querie3->fat[i].nVendasN);
            printf("Número de vendas P: %d\n", querie3->fat[i].nVendasP);
            printf("Total Faturado N: %.2f\n", querie3->fat[i].fatN);
            printf("Total Faturado P: %.2f\n", querie3->fat[i].fatP);
        }
    }
}

void printQ4(Q4* querie4) {
    int i;

    system("clear");

    for(i = 0; i < querie4 -> size;i++)
        printf("%s\n", querie4->prods[i]);

    printf("Produtos não comprados:%d\n", querie4->size);
}

void printQ5(Q5* querie5) {
    int i;

    system("clear");

    for(i=0; i<querie5->size; i++)
        printf("%s\n", querie5->cli[i]);

    printf("Clientes que realizaram compras em todas as Filiais: %d\n", querie5->size);
}

void printQ6(Q6* querie6, clock_t start_t, clock_t end_t) {
    system("clear");

    printf("\nClientes não compradores: %d\n", querie6->nCli);
    printf("Produtos não comprados: %d\n", querie6->nProd);

    printf("\nTempo de execução da Querie 6: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ7(Q7* querie7, clock_t start_t, clock_t end_t) {
    int i;

    system("clear");

    printf("Filial  1   2   3\n" );
    for(i=0; i<12; i++)
        printf("Mes %d: %d   %d   %d\n", (i+1), querie7->tabela[i][0], querie7->tabela[i][1], querie7->tabela[i][2]);

    printf("\nTempo de execução da Querie 7: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ8(Q8* querie8, clock_t start_t, clock_t end_t) {
    system("clear");

    printf("\nTotal vendas: %d\n", querie8->vendas);
    printf("Total faturado: %.2f\n", querie8->fact);

    printf("\nTempo de execução da Querie 8: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ9(Q9* querie9, int filial, clock_t start_t, clock_t end_t) {
    int i;

    system("clear");

    for(i=0; i<querie9->total; i++) {
        if(querie9->lista[i].tipocompra == 1)
            printf("%s (N)\n", querie9->lista[i].cliente);
        else if(querie9->lista[i].tipocompra == 2)
            printf("%s (P)\n", querie9->lista[i].cliente);
        else
            printf("%s (N/P)\n", querie9->lista[i].cliente);
    }

    printf("Numero de Clientes que comraram o produto da filial %d: %d\n", filial, querie9->total);

    printf("\nTempo de execução da Querie 9: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ10(Q10* querie10, clock_t start_t, clock_t end_t) {
  int i;

  system("clear");

  if(querie10 == NULL) 
    printf("Cliente inválido\n");

  for(i = 0; i < querie10 -> size;i++)
    printf("%s %d\n", querie10->produtos[i].prod,querie10->produtos[i].quantidade);

    printf("\nTempo de execução da Querie 9: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ13(Q13* querie13) {
    system("clear");

    printf("\nNumero de Clientes Lidos: %d\n", querie13->cliL);
    printf("Numero de Clientes Validados: %d\n", querie13->cliV);

    printf("Numero de Produtos Lidos: %d\n", querie13->prodL);
    printf("Numero de Produtos Validados: %d\n", querie13->prodV);
    
    //printf("Numero de Vendas Lidas: %d\n", querie13->salesL);
    //printf("Numero de Vendas Validadas: %d\n", querie13->salesV);
}
