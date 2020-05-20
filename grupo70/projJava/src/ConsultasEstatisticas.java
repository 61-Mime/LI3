import java.util.Arrays;

public class ConsultasEstatisticas implements IConsultasEstatisticas{
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
    private float [][] fatMesFil;
    private float [][]compradoresMesFil;

    public ConsultasEstatisticas(GestVendas sgv) {
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
        compradoresMesFil = new float[12][3];
        float [] array = sgv.getgFilCliCompradoresMes(0);
        float [] array2 = sgv.getgFilCliCompradoresMes(1);
        float [] array3 = sgv.getgFilCliCompradoresMes(2);
        for(int i = 0;i < 12; i++) {
            compradoresMesFil[i][0] = array[i];
            compradoresMesFil[i][1] = array2[i];
            compradoresMesFil[i][2] = array3[i];
        }
    }

    public String getSalesPath() {
        return SalesPath;
    }

    public int getVendasInvalidas() {
        return vendasInvalidas;
    }

    public int getTotalProdutos() {
        return totalProdutos;
    }

    public int getProdsComprados() {
        return prodsComprados;
    }

    public int getProdsNaoComprados() {
        return prodsNaoComprados;
    }

    public int getTotalClientes() {
        return totalClientes;
    }

    public int getCliCompradores() {
        return cliCompradores;
    }

    public int getCliNaoCompradores() {
        return cliNaoCompradores;
    }

    public int getComprasValor0() {
        return comprasValor0;
    }

    public float getFatTotal() {
        return fatTotal;
    }

    public int[] getComprasMes() {
        return comprasMes.clone();
    }

    public float[][] getFatMesFil() {
        return fatMesFil.clone();
    }

    public float[][] getCompradoresMesFil() {
        return compradoresMesFil.clone();
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
