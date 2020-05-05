public class ConsultasEstatisticas {
    private String SalesPath;
    private int vendasInvalidas;
    private int totalProdutos;
    private int prodsComprados;
    private int prodsNaoComprados;
    private int totalClientes;
    private int cliCompradores;
    private int cliNaoCompradores;
    private int comprasValor0;
    private float fatTotal;
    private int []comprasMes;
    private float []fatMesFil;
    private int []compradoresMesFil1;
    private int []compradoresMesFil2;
    private int []compradoresMesFil3;

    public ConsultasEstatisticas(Load sgv) {
        SalesPath = sgv.getLoadInfo().getSalesPath();
        vendasInvalidas = sgv.getLoadInfo().getVendasInvalidas();
        totalProdutos = sgv.getLoadInfo().getProdValidos();
        prodsComprados = sgv.getFact().getComprados();
        prodsNaoComprados = totalProdutos - prodsNaoComprados;
        totalClientes = sgv.getLoadInfo().getCliValidos();
        cliCompradores = sgv.getLoadInfo().getCliComprador();
        cliNaoCompradores = totalClientes - cliCompradores;
        comprasValor0 = sgv.getFact().getCompras0();
        fatTotal = sgv.getFact().getFaturacaoTotal();
        comprasMes = sgv.getFact().getComprasMes();
        fatMesFil = sgv.getFact().getFaturacaoMesFil();
        compradoresMesFil1 = sgv.getFilial(0).getCliCompradoresMes();
        compradoresMesFil2 = sgv.getFilial(1).getCliCompradoresMes();
        compradoresMesFil3 = sgv.getFilial(2).getCliCompradoresMes();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Ficheiro vendas:").append(SalesPath).append("\n").
        append("Vendas inválidas:").append(vendasInvalidas).append("\n").
        append("Total produtos:").append(totalProdutos).append("\n").
        append("Total clientes:").append(totalClientes).append("\n").
        append("Produtos comprados:").append(prodsComprados).append("\n").
        append("Produtos não comprados:").append(prodsNaoComprados).append("\n").
        append("Clientes compradores:").append(cliCompradores).append("\n").
        append("Clientes não compradores:").append(cliNaoCompradores).append("\n").
        append("Compras valor 0.0:").append(comprasValor0).append("\n").
        append("Faturação total:").append(fatTotal).append("\n").
        append("Faturação Janeiro:").append(fatMesFil[0]).append(" ").
        append(fatMesFil[12]).append(" ").append(fatMesFil[24]).append("\n").
        append("Clientes compradores Janeiro:").append(compradoresMesFil1[0]).
        append(" ").append(compradoresMesFil2[0]).append(" ").
        append(compradoresMesFil3[0]).append("\n");

        return sb.toString();
    }
}
