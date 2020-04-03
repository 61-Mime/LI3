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

void printArray(char** arr, int size) {
    int i, j;

    system("clear");

    for(i=0; i<size; i+=12) {
        for(j=i; (j<i+11) && (j<size-1); j++)
            printf("%s - %-5d  ", arr[j], j+1);
        printf("%s - %-5d\n", arr[j], j+1);
    }
}

void printQ1(clock_t start_t, clock_t end_t) {
    printf("\nTempo de execução da Querie 1: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ2(Q2* querie2, char letter) {
    if(querie2 == NULL) {
        printf("Letra inválida\n");
        return;
    }

    printArray(querie2->prods, querie2->size);

    printf("\nNumero de Produtos começados por %c: %d\n", letter, querie2->size);
}

void printQ3(Q3* querie3, char* prodID, int month) {
    int i;

    if(querie3 == NULL) {
        printf("Produto inválido\n");
        return;
    }

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

    printArray(querie4->prods, querie4->size);

    printf("\nProdutos não comprados:%d\n", querie4->size);
}

void printQ5(Q5* querie5) {
    printArray(querie5->cli, querie5->size);

    printf("\nClientes que realizaram compras em todas as Filiais: %d\n", querie5->size);
}

void printQ6(Q6* querie6, clock_t start_t, clock_t end_t) {
    printf("\nClientes não compradores: %d\n", querie6->nCli);
    printf("Produtos não comprados: %d\n", querie6->nProd);

    printf("\nTempo de execução da Querie 6: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ7(Q7* querie7, clock_t start_t, clock_t end_t) {
    int i;

    if(querie7 == NULL) {
        printf("Cliente inválido\n");
        return;
    }

    printf("\nFilial  1     2     3\n" );
    for(i=0; i<12; i++)
        printf("Mes %02d: %-4d  %-4d  %-4d\n", (i+1), querie7->tabela[i][0], querie7->tabela[i][1], querie7->tabela[i][2]);

    printf("\nTempo de execução da Querie 7: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ8(Q8* querie8, clock_t start_t, clock_t end_t) {
    printf("\nTotal vendas: %d\n", querie8->vendas);
    printf("Total faturado: %.2f\n", querie8->fact);

    printf("\nTempo de execução da Querie 8: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ9(Q9* querie9, int filial, clock_t start_t, clock_t end_t) {
    int i;

    if(querie9 == NULL) {
        printf("Produto inválido\n");
        return;
    }

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

  if(querie10 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie10 -> size;i++)
    printf("%s %d\n", querie10->produtos[i].prod,querie10->produtos[i].quantidade);

  printf("\nTempo de execução da Querie 10: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ11(Q11* querie11, clock_t start_t, clock_t end_t) {
  int i;

  if(querie11 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie11 -> size;i++)
    printf("%s %d %d %d %d %d %d %d\n", querie11->produtos[i].prod, querie11->produtos[i].unidades[0], querie11->produtos[i].unidades[1], querie11->produtos[i].unidades[2],
                        querie11->produtos[i].clientes[0], querie11->produtos[i].clientes[1], querie11->produtos[i].clientes[2], querie11->produtos[i].total);

  printf("\nTempo de execução da Querie 11: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ12(Q12* querie12, clock_t start_t, clock_t end_t) {
  int i;

  if(querie12 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie12 -> size;i++)
    printf("%s %.2f\n", querie12->prods[i].prod,querie12->prods[i].faturacao);

  printf("\nTempo de execução da Querie 12: %.4f s\n", (end_t - start_t) * 0.000001);
}

void printQ13(Q13* querie13) {
    printf("\nNumero de Clientes Lidos: %d\n", querie13->cliL);
    printf("Numero de Clientes Validados: %d\n", querie13->cliV);

    printf("Numero de Produtos Lidos: %d\n", querie13->prodL);
    printf("Numero de Produtos Validados: %d\n", querie13->prodV);

    //printf("Numero de Vendas Lidas: %d\n", querie13->salesL);
    //printf("Numero de Vendas Validadas: %d\n", querie13->salesV);
}
