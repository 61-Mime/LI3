/**
 * @file  apresentacao.c
 * @brief Ficheiro que contém funções relativas ao módulo Apresentacao
 */

#include "apresentacao.h"

void welcome() {
    printf("   SSSSSSSSSSSSSSS           GGGGGGGGGGGG   VVVVVVVV           VVVVVVVV\n");
    printf(" SS:::::::::::::::S       GGG::::::::::::G  V::::::V           V::::::V\n");
    printf("S:::::SSSSSS::::::S     GG:::::::::::::::G  V::::::V           V::::::V\n");
    printf("S:::::S     SSSSSSS    G:::::GGGGGGGG::::G  V::::::V           V::::::V\n");
    printf("S:::::S               G:::::G       GGGGGG   V:::::V           V:::::V \n");
    printf("S:::::S              G:::::G                  V:::::V         V:::::V  \n");
    printf(" S::::SSSS           G:::::G                   V:::::V       V:::::V   \n");
    printf("  SS::::::SSSSS      G:::::G    GGGGGGGGGG      V:::::V     V:::::V    \n");
    printf("    SSS::::::::SS    G:::::G    G::::::::G       V:::::V   V:::::V     \n");
    printf("       SSSSSS::::S   G:::::G    GGGGG::::G        V:::::V V:::::V      \n");
    printf("            S:::::S  G:::::G        G::::G         V:::::V:::::V       \n");
    printf("            S:::::S   G:::::G       G::::G          V:::::::::V        \n");
    printf("SSSSSSS     S:::::S    G:::::GGGGGGGG::::G           V:::::::V         \n");
    printf("S::::::SSSSSS:::::S     GG:::::::::::::::G            V:::::V          \n");
    printf("S:::::::::::::::SS        GGG::::::::::::G             V:::V           \n");
    printf(" SSSSSSSSSSSSSSS             GGGGGGGGGGGG               VVV            \n");
    printf("\nBem Vindo ao Sistema de Gestão de Vendas. Durante a execução do programa\n");
    printf("pode executar qualquer dos comandos do menu, tendo em atenção que o com-\n");
    printf("ando 1 tem de ser executado antes de qualquer outro.\n");
    printf("Pode também usar o comando menu, para voltar a exibir o menu, ou Q, para\n");
    printf("sair do programa.\n\n");
}

/**
 *@brief função que mostra o menu dos comandos que o utilizador pode usar
 */
void menu() {
    printf("\n MENU \n");
    printf("  [1] | Iniciar o SGV\n");
    printf("  [2] | Produtos começados por uma letra\n");
    printf("  [3] | Informação de um produto por mês\n");
    printf("  [4] | Códigos de produto que ninguém comprou\n");
    printf("  [5] | Códigos de cliente que realizaram compras em todas as filiais\n");
    printf("  [6] | Número de Clientes e número de Produtos nunca utilizados\n");
    printf("  [7] | Informação das compras de um cliente\n");
    printf("  [8] | Número de Vendas para um intervalo de meses\n");
    printf("  [9] | Códigos de cliente que compraram um produto\n");
    printf(" [10] | Códigos de produto que um cliente comprou num mês\n");
    printf(" [11] | Códigos de produto mais vendidos\n");
    printf(" [12] | Códigos de produto em que um cliente gastou mais dinheiro\n");
}

/**
 *@brief função que imprime uma tabela de Strings
 */
void printArray(char** arr, int size) {
    int i, j;


    for(i=0; i<size; i+=12) {
        for(j=i; (j<i+11) && (j<size-1); j++)
            printf("%s - %-5d  ", arr[j], j+1);
        printf("%s - %-5d\n", arr[j], j+1);
    }
}

/**
 *@brief         função que imprime o tempo que a querie 1 demora a executar
 *@param start_t momento em que a querie 1 inicia
 *@param end_t   momento em que a querie 1 finda
 */
void printQ1(clock_t start_t, clock_t end_t) {
    printf("\nTempo de execução da Querie 1: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief         função que imprime o número de produtos começados por um determinado char
 *@param querie2 apontador para Q2
 *@param letter  char que começa o nome dos produtos
 */
void printQ2(Q2* querie2, char letter) {
    if(querie2 == NULL) {
        printf("Letra inválida\n");
        return;
    }

    printArray(querie2->prods, querie2->size);

    printf("\nNumero de Produtos começados por %c: %d\n", letter, querie2->size);
}

/**
 *@brief         função que imprime a faturação de um determinado produto, por filial e mês
 *@param querie3 apontador para Q3
 *@param prodID  String que representa o produto
 *@param month   mês do qual se pretende obter a faturação
 */
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

/**
 *@brief         função que imprime o número de produtos não comprados
 *@param querie4 apontador para Q4
 */
void printQ4(Q4* querie4) {

    printArray(querie4->prods, querie4->size);

    printf("\nProdutos não comprados:%d\n", querie4->size);
}

/**
 *@brief         função que imprime o número de clientes que realizaram compras em todas as Filiais
 *@param querie5 apontador para Q5
 */
void printQ5(Q5* querie5) {
    printArray(querie5->cli, querie5->size);

    printf("\nClientes que realizaram compras em todas as Filiais: %d\n", querie5->size);
}

/**
 *@brief         função que imprime os cliente que não compraram, os produtos não comprados e o tempo de execução desta querie
 *@param querie6 apontador para a estrutura Q6
 *@param start_t momento em que a querie 6 inicia
 *@param end_t   momento em que a querie 6 finda
 */
void printQ6(Q6* querie6, clock_t start_t, clock_t end_t) {
    printf("\nClientes não compradores: %d\n", querie6->nCli);
    printf("Produtos não comprados: %d\n", querie6->nProd);

    printf("\nTempo de execução da Querie 6: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief         função que imprime os produtos comprados por um cliente e o tempo de execução desta querie
 *@param querie7 apontador para a estrutura Q7
 *@param start_t momento em que a querie 7 inicia
 *@param end_t   momento em que a querie 7 finda
 */
void printQ7(Q7* querie7, clock_t start_t, clock_t end_t) {
    int i;

    if(querie7 == NULL) {
        printf("Cliente inválido\n");
        return;
    }

    printf("\nFilial  1     2     3\n" );
    for(i=0; i<12; i++)
        printf("Mes %02d: %-4d  %-4d  %-4d\n", (i+1), querie7->tabela[i][0], querie7->tabela[i][1], querie7->tabela[i][2]);

    printf("\nTempo de execução da Querie 7: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief         função que imprime o total de vendas, o total faturado e o tempo de execução desta querie
 *@param querie8 apontador para a estrutura Q8
 *@param start_t momento em que a querie 8 inicia
 *@param end_t   momento em que a querie 8 finda
 */
void printQ8(Q8* querie8, clock_t start_t, clock_t end_t) {
    printf("\nTotal vendas: %d\n", querie8->vendas);
    printf("Total faturado: %.2f\n", querie8->fact);

    printf("\nTempo de execução da Querie 8: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief         função que imprime a lista de clientes para um determinado produto numa determinada filial e o tempo de execução desta querie
 *@param filial  filial a ser analisada
 *@param querie9 apontador para a estrutura Q9
 *@param start_t momento em que a querie 9 inicia
 *@param end_t   momento em que a querie 9 finda
 */
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
    }

    printf("Numero de Clientes que compraram o produto da filial %d: %d\n", filial, querie9->total);

    printf("\nTempo de execução da Querie 9: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief          função que imprime por ordem decrescente de quantidade os produtos que um determinado cliente comprou e o tempo de execução desta querie
 *@param querie10 apontador para a estrutura Q10
 *@param start_t  momento em que a querie 10 inicia
 *@param end_t    momento em que a querie 10 finda
 */
void printQ10(Q10* querie10, clock_t start_t, clock_t end_t) {
  int i;

  if(querie10 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie10 -> size;i++)
    printf("%s %d\n", querie10->produtos[i].prod,querie10->produtos[i].quantidade);

  printf("\nTempo de execução da Querie 10: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief          função que imprime por ordem decrescente o número de produtos mais vendido em todo o ano, indicando o número total de clientes e unidades vendidas por filial, e o tempo de execução desta querie
 *@param querie11 apontador para a estrutura Q11
 *@param start_t  momento em que a querie 11 inicia
 *@param end_t    momento em que a querie 11 finda
 */
void printQ11(Q11* querie11, clock_t start_t, clock_t end_t) {
  int i;

  if(querie11 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie11->size;i++)
    printf("%s %-4d %-4d %-4d %d %d %d %d\n", querie11->produtos[i].prod, querie11->produtos[i].unidades[0], querie11->produtos[i].unidades[1], querie11->produtos[i].unidades[2],
                        querie11->produtos[i].clientes[0], querie11->produtos[i].clientes[1], querie11->produtos[i].clientes[2], querie11->produtos[i].total);

  printf("\nTempo de execução da Querie 11: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief          função que imprime os n produtos mais comprados por um determinado cliente durante o ano e o tempo de execução desta querie
 *@param querie12 apontador para a estrutura Q12
 *@param start_t  momento em que a querie 12 inicia
 *@param end_t    momento em que a querie 12 finda
 */
void printQ12(Q12* querie12, clock_t start_t, clock_t end_t) {
  int i;

  if(querie12 == NULL) {
    printf("Cliente inválido\n");
    return;
  }

  for(i = 0; i < querie12 -> size;i++)
    printf("%s %.2f\n", querie12->prods[i].prod,querie12->prods[i].faturacao);

  printf("\nTempo de execução da Querie 12: %.4f s\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
}

/**
 *@brief          função que imprime os resultados da leitura dos ficheiros da querie 1, bem como o ficheiro lido e usado e o número total de linhas lidas e validadas
 *@param querie13 apontador para a estrutura Q13
 */
void printQ13(Q13* querie13) {
    printf("\nFicheiro de Clientes usado: %s\n", querie13->pathCli);
    printf("Numero de Clientes Lidos: %d\n", querie13->cliL);
    printf("Numero de Clientes Validados: %d\n", querie13->cliV);

    printf("\nFicheiro de Produtos usado: %s\n", querie13->pathProd);
    printf("Numero de Produtos Lidos: %d\n", querie13->prodL);
    printf("Numero de Produtos Validados: %d\n", querie13->prodV);

    printf("\nFicheiro de Vendas usado: %s\n", querie13->pathSales);
    printf("Numero de Vendas Lidas: %d\n", querie13->salesL);
    printf("Numero de Vendas Validadas: %d\n", querie13->salesV);
}
