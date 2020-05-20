import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Apresentacao implements IApresentacao{

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
        System.out.print("INÍCIO\n" +
                "1 | Consultas estatisticas\n" +
                "2 | Consultas iterativas\n" +
                "3 | Gravar estado\n" +
                "4 | Carregar estado a partir de um ficheiro\n" +
                "5 | Carregar dados a partir do ficheiro vendas_1M.txt\n" +
                "0 | Sair\n");
    }

    public void menuConsultasInterativas(){
        System.out.print("CONSULTAS INTERATIVAS\n" +
                "1 | Códigos Produtos nunca comprados e total\n" +
                "2 | Total vendas e clientes distintos para cada filial e para um dado mês\n" +
                "3 | Número compras, produtos distintos e gasto total de um dado cliente para cada mês\n" +
                "4 | Número compras, clientes distintos e faturação total de um dado produto para cada mês\n"+
                "5 | Lista produtos que um cliente mais comprou(quantidade)\n"+
                "6 | X produtos mais vendidos em todo o ano(unidades) e clientes distintos que os compraram\n" +
                "7 | 3 maiores compradores em termos de faturação por filial\n" +
                "8 | X clientes que compraram mais produtos diferentes\n" +
                "9 | X clientes que mais compraram um produto e valor gasto para cada um\n" +
                "10| Faturação total de cada produto mês a mês e filial a filial\n" +
                "0 | Sair\n");
    }

    public void menuConsultasEstatisticas(){
        System.out.print("CONSULTAS ESTATÍSTICAS\n" +
                "1 | Dados relativos ao último ficheiro de vendas lido\n" +
                "2 | Total compras por mês\n" +
                "3 | Facturação total e por (Filial/Mês)\n" +
                "4 | Clientes compradores distintos por (Filial/Mês)\n" +
                "0 | Sair\n");
    }

    private void printPagina(List<ParStringFloat> list, int page, int max, int maxpage) {
        int i, j;
        int size = list.size();

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("                                       Página (" + (page+1) + "/" +(maxpage+1) +")");
        System.out.println("---------------------------------------------------------------------------------------------");

        for(i=max*page; i<(max*(page+1)) && i<size; i+=6) {
            for(j=i; (j<i+5) && (j<size-1); j++)
                System.out.print(list.get(j).toString() + "  |  ");
            System.out.println(list.get(j).toString());
        }

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("      [N] Next Page | [P] Previous Page | [F] First Page | [L] Last Page | [Q] Quit        ");
        System.out.println("---------------------------------------------------------------------------------------------");
    }

    private void printArray(List<ParStringFloat> list, int max) {
        int page = 0, maxpage = (list.size()-1)/max;
        Scanner s = new Scanner(System.in);
        String line;
        boolean r=true;

        while(r) {
            printPagina(list, page, max, maxpage);

            line = s.nextLine();

            if(line.equals("N") && page<maxpage)
                page++;

            else if(line.equals("P") && page>0)
                page--;

            else if(line.equals("F"))
                page = 0;

            else if(line.equals("L"))
                page = maxpage;

            else if(line.equals("Q"))
                r=false;
        }
    }


    public void printMessage(String message) {
        System.out.println(message);
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

    public void pedirNomeFicheiro(){
        System.out.println( "Introduza o nome do ficheiro:");
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

    public void printConsultasEstatisticas(ConsultasEstatisticas ce, int i) {
        final StringBuilder sb = new StringBuilder();

        switch (i) {
            case 1:
                sb.append("Informações sobre ficheiro de vendas lido\n");
                sb.append("\nFicheiro vendas lido:").append(ce.getSalesPath());
                sb.append("\nVendas Inválidas:").append(ce.getVendasInvalidas());
                sb.append("\nTotal produtos:").append(ce.getTotalProdutos());
                sb.append("\nNúmero prodtutos comprados:").append(ce.getProdsComprados());
                sb.append("\nNúmero prodtutos nunca Comprados:").append(ce.getProdsNaoComprados());
                sb.append("\nTotal clientes:").append(ce.getTotalClientes());
                sb.append("\nNúmero clientes compradores:").append(ce.getCliCompradores());
                sb.append("\nNúmero clientes não compradores:").append(ce.getCliNaoCompradores());
                sb.append("\nCompras com valor 0:").append(ce.getComprasValor0());
                sb.append("\nFacturação total:").append(ce.getFatTotal());
                System.out.println(sb.toString());
                break;
            case 2:
                sb.append("Número de compras efetuadas em cada mês\n");
                int [] comprasmes = ce.getComprasMes();
                for(int j = 0;j < 12;j++)
                    sb.append("\nMes ").append(j+1).append(":").append(comprasmes[i]);
                System.out.println(sb.toString());
                break;
            case 3:
                System.out.println("Facturação (Filial/Mês)");
                System.out.println(String.format("%5s %8s %8s %10s %8s %10s %8s %10s", "Filial" , "|", "1", "|", "2","|", "3","|"));
                printTabela(ce.getFatMesFil());
                break;
            case 4:
                System.out.println("Clientes compradores (Filial/Mês)");
                System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Filial" , "|", "1", "|", "2","|", "3","|"));
                printTabela(ce.getCompradoresMesFil());
                break;
        }
        clearScreen();
    }

    private void printStringList(List<String> list){
        StringBuilder sb = new StringBuilder();
        int size = list.size(),i,c;
        for(i = 0,c = 0;i < size;i++,c++) {
            if (c == 2) {
                sb.append(list.get(i)).append("\n");
                c = 0;
            } else
                sb.append(list.get(i)).append("  ");
        }
        System.out.println(sb.append("\n").toString());
    }

    private void printQ1(List<String> list) {
        System.out.println("Produtos não comprados:\n");
        printStringList(list);
    }

    private void printQ2(int [] array) {
        StringBuilder sb = new StringBuilder();
        sb.append("Vendas e clientes distintos que as fizeram para o mês dado\n\n");
        sb.append("Total vendas no mês dado ").append(":").append(array[0]);
        sb.append("Clientes distintos no mês dado ").append(":").append(array[1]);
        for(int i = 2;i < 8;i+=2) {
            sb.append("Total vendas filial ").append(i/2).append(":").append(array[i]);
            sb.append("Clientes distintos filial ").append(i/2).append(":").append(array[i + 1]);
        }
    }

    private void printQ3(Map<Integer,float[]> querie3) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie3.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Mês" , "|", "Compras", "|", "Produtos","|", "Gasto","|"));
        printTabela(res);
    }

    private void printQ4(Map<Integer,float[]> querie4) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie4.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Mês" , "|", "Vendas", "|", "Clientes","|", "Faturação","|"));
        printTabela(res);
    }

    private void printQ7(Map<Integer,List<String>> list) {
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

    private void printQ10(Map<String,float[][]> querie10){
        for(Map.Entry<String, float[][]> cod:querie10.entrySet()) {
            System.out.println("Faturação produto "+cod.getKey()+"\n");
            if (cod.getValue() != null){
                System.out.println(String.format("%5s %8s %8s %8s %8s %8s %8s %8s", "Filial" , "|", "1", "|", "2","|", "3","|"));
                printTabela(cod.getValue());
            }
            else
                System.out.println("Produto não vendido\n");
        }
    }

    public void printConsultasIterativas(ConsultasInterativas ci, int i,String time) {
        final StringBuilder sb = new StringBuilder("ConsultasEstatisticas\n");

        switch (i) {
            case 1:
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
                printArray(ci.getQ5(), 100);
                break;
            case 6:
                printArray(ci.getQ6(), 100);
                break;
            case 7:
                printQ7(ci.getQ7());
                break;
            case 8:
                printArray(ci.getQ8(), 100);
                break;
            case 9:
                printArray(ci.getQ9(), 100);
                break;
            case 10:
                printQ10(ci.getQ10());
                break;
        }

        printTime(time, "Querie " + i);
    }

    /*
    public void printQ1(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ1()+"\nTempo querie 1:" + time);
    }

    public void printQ2(ConsultasInterativas ci, String time, int num) {
        System.out.println(ci.toStringQ2(num)+"\nTempo querie 2:" + time);
    }

    public void printQ3(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ3()+"\nTempo querie 3:" + time);
    }

    public void printQ4(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ4()+"\nTempo querie 4:" + time);
    }

    public void printQ5(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ5()+"\nTempo querie 5:" + time);
    }

    public void printQ6(ConsultasInterativas ci, String time, int num) {
        System.out.println(ci.toStringQ6(num)+"\nTempo querie 6:" + time);
    }

    public void printQ7(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ7()+"\nTempo querie 7:" + time);
    }

    public void printQ8(ConsultasInterativas ci, String time, int num) {
        System.out.println(ci.toStringQ8(num)+"\nTempo querie 8:" + time);
    }

    public void printQ9(ConsultasInterativas ci, String time, int num, String line) {
        System.out.println(ci.toStringQ9(num, line)+"\nTempo querie 9:" + time);
    }

    public void printQ10(ConsultasInterativas ci, String time) {
        System.out.println(ci.toStringQ10()+"\nTempo querie 10:" + time);
    }
*/
}
