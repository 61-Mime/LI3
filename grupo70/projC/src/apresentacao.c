#include "apresentacao.h"

void printQ1(clock_t start_t, clock_t end_t) {
    printf("\nTempo de execução da Querie 1: %.2f s\n", (end_t - start_t) * 0.000001);
}

void printQ2(Q2* querie2, char letter) {
    int i;

    printf("\n");

    for(i=0; i<querie2->size; i++)
        printf("(%d) %s\n", i, querie2->prods[i]);

    printf("Numero de Produtos começados por %c: %d\n", letter, querie2->size);
}

void printQ3(Q3* querie3, char* prodID, int month) {
    int i;
    
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

void printQ6(Q6* querie6) {
    printf("\nClientes não compradores: %d\n", querie6->nCli);
    printf("Produtos não comprados: %d\n", querie6->nProd);
}

void printQ7(Q7* querie7, clock_t start_t, clock_t end_t) {
    int i;
    
    printf("Filial  1   2   3\n" );
    for(i=0; i<12; i++)
        printf("Mes %d: %d   %d   %d\n", (i+1), querie7->tabela[i][0], querie7->tabela[i][1], querie7->tabela[i][2]);

    printf("\nTempo de execução da Querie 7: %.2f s\n", (end_t - start_t) * 0.000001);
}

void printQ8(Q8* querie8, clock_t start_t, clock_t end_t) {
    printf("\nTotal vendas: %d\n", querie8->vendas);
    printf("Total faturado: %.2f\n", querie8->fact);

    printf("\nTempo de execução da Querie 8: %.2f s\n", (end_t - start_t) * 0.000001);
}

void printQ13(Q13* querie13) {
    printf("\nNumero de Clientes Lidos: %d\n", querie13->cliL);
    printf("Numero de Clientes Validados: %d\n", querie13->cliV);
    printf("Numero de Produtos Lidos: %d\n", querie13->prodL);
    printf("Numero de Produtos Validados: %d\n", querie13->prodV);
    printf("Numero de Vendas Lidas: %d\n", querie13->salesL);
    printf("Numero de Vendas Validadas: %d\n", querie13->salesV);
}