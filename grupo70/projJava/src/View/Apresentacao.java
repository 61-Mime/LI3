package View;


import Model.ConsultasInterativas;

import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Apresentacao implements IApresentacao {

    public void welcome() {
        System.out.print("   SSSSSSSSSSSSSSS           GGGGGGGGGGGG   VVVVVVVV           VVVVVVVV\n");
        System.out.print(" SS:::::::::::::::S       GGG::::::::::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::SSSSSS::::::S     GG:::::::::::::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::S     SSSSSSS    G:::::GGGGGGGG::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::S               G:::::G       GGGGGG   V:::::V           V:::::V \n");
        System.out.print("S:::::S              G:::::G                  V:::::V         V:::::V  \n");
        System.out.print(" S::::SSSS           G:::::G                   V:::::V       V:::::V   \n");
        System.out.print("  SS::::::SSSSS      G:::::G    GGGGGGGGGG      V:::::V     V:::::V    \n");
        System.out.print("    SSS::::::::SS    G:::::G    G::::::::G       V:::::V   V:::::V     \n");
        System.out.print("       SSSSSS::::S   G:::::G    GGGGG::::G        V:::::V V:::::V      \n");
        System.out.print("            S:::::S  G:::::G        G::::G         V:::::V:::::V       \n");
        System.out.print("            S:::::S   G:::::G       G::::G          V:::::::::V        \n");
        System.out.print("SSSSSSS     S:::::S    G:::::GGGGGGGG::::G           V:::::::V         \n");
        System.out.print("S::::::SSSSSS:::::S     GG:::::::::::::::G            V:::::V          \n");
        System.out.print("S:::::::::::::::SS        GGG::::::::::::G             V:::V           \n");
        System.out.print(" SSSSSSSSSSSSSSS             GGGGGGGGGGGG               VVV            \n");
        System.out.print("\nBem Vindo ao Sistema de Gestão de Vendas. Durante a execução do programa\n");
        System.out.print("pode executar qualquer dos comandos do menu, tendo em atenção que os dados\n");
        System.out.print("têm de ser carregados antes das consultas.\n");
        System.out.print("Pressione qualquer tecla para continuar!\n");
    }

    public void clearScreen() {
        for (int i = 0; i < 3; ++i)
            System.out.println();
    }

    public void menu(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("                       INÍCIO\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Consultas estatisticas\n");
        sb.append("2 | Consultas iterativas\n");
        sb.append("3 | Gravar estado\n");
        sb.append("4 | Carregar estado a partir de um ficheiro\n");
        sb.append("5 | Carregar dados a partir do ficheiro vendas_1M.txt\n");
        sb.append("0 | Sair\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    public void menuConsultasInterativas(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-------------------------------------------------------------------------------------------\n");
        sb.append("                                   CONSULTAS INTERATIVAS\n");
        sb.append("---+---------------------------------------------------------------------------------------\n");
        sb.append(" 1 | Códigos Produtos nunca comprados e total\n");
        sb.append(" 2 | Total vendas e clientes distintos para cada filial e para um dado mês\n");
        sb.append(" 3 | Número compras, produtos distintos e gasto total de um dado cliente para cada mês\n");
        sb.append(" 4 | Número compras, clientes distintos e faturação total de um dado produto para cada mês\n");
        sb.append(" 5 | Lista produtos que um cliente mais comprou(quantidade)\n");
        sb.append(" 6 | X produtos mais vendidos em todo o ano(unidades) e clientes distintos que os compraram\n");
        sb.append(" 7 | 3 maiores compradores em termos de faturação por filial\n");
        sb.append(" 8 | X clientes que compraram mais produtos diferentes\n");
        sb.append(" 9 | X clientes que mais compraram um produto e valor gasto para cada um\n");
        sb.append("10 | Faturação total de cada produto mês a mês e filial a filial\n");
        sb.append(" 0 | Voltar\n");
        sb.append("---+----------------------------------------------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    public void menuConsultasEstatisticas(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("               CONSULTAS ESTATÍSTICAS\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Dados relativos ao último ficheiro de vendas lido\n");
        sb.append("2 | Total compras por mês\n");
        sb.append("3 | Facturação total e por (Filial/Mês)\n");
        sb.append("4 | Clientes compradores distintos por (Filial/Mês)\n");
        sb.append("0 | Voltar\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    public void menuQ10() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("                      QUERIE 10\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Ver tabela de faturação de um produto\n");
        sb.append("0 | Voltar\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    public void printMessage(String message) {
        System.out.println(message);
    }

    public void pedirNomeFicheiro(){
        System.out.println("Introduza o nome do ficheiro: ");
    }

    public void printErroLerInt(){
        System.out.println("Erro a ler int!");
    }

    public void printErroCarregar(){
        System.out.println("Carregue as estruturas primeiro!");
    }

    public void printErroLerFicheiro(int i){
        if(i == 1)
            System.out.println("Erro a ler ficheiro!");
        else
            System.out.println("Ficheiro não encontrado!");
    }

    public void printTime(String time,String type){
        System.out.println("Tempo carregamento " + type + ":" +time);
    }

    public String pedirCliente(){
        return "Introduza um cliente:";
    }

    public String pedirProduto(){
        return "Introduza um produto:";
    }

    public String pedirMes(){
        return "Introduza um mês:";
    }

    public String pedirLimite(){
        return "Introduza um limite:";
    }

    public String pedirNumero(){
        return "Introduza um número:";
    }

    public void printConsultasEstatisticas1(String salesPath, int vendasInvalidas, int totalProdutos, int prodsComprados, int prodsNaoComprados,
                                            int totalClientes, int cliCompradores, int cliNaoCompradores, int comprasValor0, float fatTotal) {
        final StringBuilder sb = new StringBuilder();

        sb.append("-------------------------------------------------------\n");
        sb.append("       Informações sobre ficheiro de vendas lido \n");
        sb.append("----------------------------------+--------------------\n");
        sb.append(" Ficheiro vendas lido             | ").append(salesPath).append("\n");
        sb.append(" Vendas Inválidas                 | ").append(vendasInvalidas).append("\n");
        sb.append(" Total produtos                   | ").append(totalProdutos).append("\n");
        sb.append(" Número prodtutos comprados       | ").append(prodsComprados).append("\n");
        sb.append(" Número prodtutos nunca Comprados | ").append(prodsNaoComprados).append("\n");
        sb.append(" Total clientes                   | ").append(totalClientes).append("\n");
        sb.append(" Número clientes compradores      | ").append(cliCompradores).append("\n");
        sb.append(" Número clientes não compradores  | ").append(cliNaoCompradores).append("\n");
        sb.append(" Compras com valor 0              | ").append(comprasValor0).append("\n");
        sb.append(" Facturação total                 | ").append(fatTotal).append("\n");
        sb.append("----------------------------------+--------------------\n");

        clearScreen();

        System.out.println(sb.toString());
    }

    public void printConsultasEstatisticas2(int[] comprasMes) {
        final StringBuilder sb = new StringBuilder();

        sb.append("Número de compras efetuadas em cada mês\n");
                for(int j = 0;j < 12;j++)
                    sb.append("\nMes ").append(j+1).append(":").append(comprasMes[j]);

        clearScreen();

        System.out.println(sb.toString());
    }

    public void printConsultasEstatisticas3(float[][] tabela, int type) {

        if (type == 0)
            System.out.println("Facturação (Filial/Mês)");
        else
            System.out.println("Clientes compradores (Filial/Mês)");

        System.out.println(String.format("%5s %7s %8s %10s %8s %10s %8s %10s", "Filial" , "|", "1", "|", "2","|", "3","|"));
        printTabela(tabela);

        clearScreen();
    }

    public void printQ1(List<String> list) {
        System.out.println("Produtos não comprados:\n");
        //printStringList(list);
    }

    public void printQ2(int [] array) {
        StringBuilder sb = new StringBuilder();
        sb.append("Vendas e clientes distintos que as fizeram para o mês dado\n\n");
        sb.append("Total vendas no mês dado ").append(":").append(array[0]);
        sb.append("Clientes distintos no mês dado ").append(":").append(array[1]);
        for(int i = 2;i < 8;i+=2) {
            sb.append("Total vendas filial ").append(i/2).append(":").append(array[i]);
            sb.append("Clientes distintos filial ").append(i/2).append(":").append(array[i + 1]);
        }
        System.out.println(sb.toString());
    }

    public void printQ3(Map<Integer,float[]> querie3) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie3.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Mês" , "|", "Compras", "|", "Produtos","|", "Gasto","|"));
        printTabela(res);
    }

    public void printQ4(Map<Integer,float[]> querie4) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie4.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Mês" , "|", "Vendas", "|", "Clientes","|", "Faturação","|"));
        printTabela(res);
    }

    public void printQ7(Map<Integer,List<String>> list) {
        System.out.println("3 Maiores compradores por filial\n\n");
        System.out.println(String.format("%5s %5s %8s %7s %8s %7s %8s %7s", "Filial" , "|", "1º", "|", "2º","|", "3º","|"));
        System.out.println(String.format("%s", "---------------------------------------------------------------"));
        for(int i = 0;i < 3;i++) {
            System.out.println(String.format("%5d %5s %10s %5s %10s %5s %10s %5s", i+1 ,  "|", list.get(i).get(0),
                                                                                            "|",list.get(i).get(1), "|",list.get(i).get(2),"|"));
        }
    }

    private void printTabela(float[][] table){
        int mes = 1;
        System.out.println(String.format("%s", "--------------------------------------------------------------------------"));
        for (final float[] row : table) {
            System.out.println(String.format("%5s %2d %5s %10.2f %5s %10.2f %5s %10.2f %5s", "Mes ",  mes, "|", row[0], "|",row[1], "|",row[2],"|"));
            mes++;
        }
    }

    public void printQ10(String prod, float[][] arr){

        System.out.println("Faturação produto "+prod+"\n");
        if (arr != null){
            System.out.println(String.format("%5s %8s %8s %10s %8s %10s %8s %10s", "Filial" , "|", "1", "|", "2","|", "3","|"));
            printTabela(arr);
        }
        else
            System.out.println("Produto não vendido\n");
    }

    private void printPagina(List<String> list, int page, int cols, int max, int maxpage) {
        int i, j;
        int size = list.size();


        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("                                       Página (" + (page+1) + "/" +(maxpage+1) +")");
        System.out.println("---------------------------------------------------------------------------------------------");

        for(i=max * page; i<(max * (page+1)) && i<size; i+=cols) {
            for(j=i; (j<i+cols-1) && (j<size-1); j++)
                System.out.print(list.get(j) + "  |  ");
            System.out.println(list.get(j));
        }

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("      [N] Next Page | [P] Previous Page | [F] First Page | [L] Last Page | [Q] Quit        ");
        System.out.println("---------------------------------------------------------------------------------------------");
    }

    private void printArray(List<String> list) {
        int page = 0, lines = 6, cols = 93/(list.get(0).length() + 3);
        int max = lines * cols, maxpage = (list.size()-1)/max;
        Scanner s = new Scanner(System.in);
        String line;
        boolean r=true;

        while(r) {
            printPagina(list, page, cols, max, maxpage);

            line = s.nextLine();

            if((line.equals("N") || line.equals("n")) && page<maxpage)
                page++;

            else if((line.equals("P") || line.equals("p")) && page>0)
                page--;

            else if(line.equals("F")  || line.equals("f"))
                page = 0;

            else if(line.equals("L") || line.equals("l"))
                page = maxpage;

            else if(line.equals("Q") || line.equals("q"))
                r=false;
        }
    }

    public void printConsultasIterativas(ConsultasInterativas ci, int i, String time) {
        switch (i) {
            case 1:
                printArray(ci.getQ1());
                printQ1(ci.getQ1());
                break;
            case 2:
                printQ2(ci.getQ2());
                break;
            case 3:
                printQ3(ci.getQ3());
                break;
            case 4:
                printQ4(ci.getQ4());
                break;
            case 5:
                printArray(ci.getQ5());
                break;
            case 6:
                printArray(ci.getQ6());
                break;
            case 7:
                printQ7(ci.getQ7());
                break;
            case 8:
                printArray(ci.getQ8());
                break;
            case 9:
                printArray(ci.getQ9());
                break;
        }

        printTime(time, "Querie " + i);
    }
}
