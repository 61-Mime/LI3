import java.util.Arrays;

public class Apresentacao {

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


    public void printMessage(String message) {
        System.out.println(message);
    }

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

    public void printConsultasEstatisticas(ConsultasEstatisticas ce, int i) {
        final StringBuilder sb = new StringBuilder("ConsultasEstatisticas\n");

        switch (i) {
            case 1:
                sb.append("SalesPath='").append(ce.getSalesPath());
                sb.append("\nvendasInvalidas=").append(ce.getVendasInvalidas());
                sb.append("\ntotalProdutos=").append(ce.getTotalProdutos());
                sb.append("\nprodsComprados=").append(ce.getProdsComprados());
                sb.append("\nprodsNaoComprados=").append(ce.getProdsNaoComprados());
                sb.append("\ntotalClientes=").append(ce.getTotalClientes());
                sb.append("\ncliCompradores=").append(ce.getCliCompradores());
                sb.append("\ncliNaoCompradores=").append(ce.getCliNaoCompradores());
                sb.append("\ncomprasValor0=").append(ce.getComprasValor0());
                sb.append("\nfatTotal=").append(ce.getFatTotal());
                break;
            case 2:
                sb.append("\ncomprasMes=").append(Arrays.toString(ce.getComprasMes()));
                break;
            case 3:
                for(int j = 0;j < 12;j++)
                    sb.append("\nFaturação Mes ").append(i+1).append(":").append(ce.getFatMesFil()[i][0]).
                            append(" ").append(ce.getFatMesFil()[i][1]).append(" ").append(ce.getFatMesFil()[i][2]);
                break;
            case 4:
                for(int j = 0;j < 12;j++)
                    sb.append("\nCompradores Mes ").append(i+1).append(":").append(ce.getCompradoresMesFil()[0][i]).
                            append(" ").append(ce.getCompradoresMesFil()[1][i]).append(" ").append(ce.getCompradoresMesFil()[2][i]);
                break;
        }

        System.out.println(sb.toString());
    }
}
