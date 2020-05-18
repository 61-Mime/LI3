import java.util.Arrays;

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
    private double fatTotal;
    private int []comprasMes;
    private double [][] fatMesFil;
    private int [][]compradoresMesFil;

    public ConsultasEstatisticas(Load sgv) {
        SalesPath = sgv.getLoadInfoSalesPath();
        vendasInvalidas = sgv.getLoadInfoVendasInvalidas();
        totalProdutos = sgv.getLoadInfoProdValidos();
        prodsComprados = sgv.getFactComprados();
        prodsNaoComprados = totalProdutos - prodsComprados;
        totalClientes = sgv.getLoadInfoCliValidos();
        cliCompradores = sgv.getLoadInfoCliComprador();
        cliNaoCompradores = totalClientes - cliCompradores;
        comprasValor0 = sgv.getFactCompras0();
        fatTotal = sgv.getFactFaturacaoTotal();
        comprasMes = sgv.getFactComprasMes();
        fatMesFil = sgv.getFactFaturacaoMesFil();
        compradoresMesFil = new int[3][12];
        compradoresMesFil[0] = sgv.getgFilCliCompradoresMes(0);
        compradoresMesFil[1] = sgv.getgFilCliCompradoresMes(1);
        compradoresMesFil[2] = sgv.getgFilCliCompradoresMes(2);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("ConsultasEstatisticas\n");
        sb.append("SalesPath='").append(SalesPath);
        sb.append("\nvendasInvalidas=").append(vendasInvalidas);
        sb.append("\ntotalProdutos=").append(totalProdutos);
        sb.append("\nprodsComprados=").append(prodsComprados);
        sb.append("\nprodsNaoComprados=").append(prodsNaoComprados);
        sb.append("\ntotalClientes=").append(totalClientes);
        sb.append("\ncliCompradores=").append(cliCompradores);
        sb.append("\ncliNaoCompradores=").append(cliNaoCompradores);
        sb.append("\ncomprasValor0=").append(comprasValor0);
        sb.append("\nfatTotal=").append(fatTotal);
        return sb.toString();
    }

    public String toString2(){
        final StringBuilder sb = new StringBuilder();
        sb.append("\ncomprasMes=").append(Arrays.toString(comprasMes));
        return sb.toString();
    }

    public String toString3(){
        final StringBuilder sb = new StringBuilder();
        for(int i = 0;i < 12;i++)
            sb.append("\nFaturação Mes ").append(i+1).append(":").append(fatMesFil[i][0]).
                    append(" ").append(fatMesFil[i][1]).append(" ").append(fatMesFil[i][2]);
        return sb.toString();
    }

    public String toString4(){
        final StringBuilder sb = new StringBuilder();
        for(int i = 0;i < 12;i++)
            sb.append("\nCompradores Mes ").append(i+1).append(":").append(compradoresMesFil[0][i]).
                    append(" ").append(compradoresMesFil[1][i]).append(" ").append(compradoresMesFil[2][i]);
        return sb.toString();
    }
}
