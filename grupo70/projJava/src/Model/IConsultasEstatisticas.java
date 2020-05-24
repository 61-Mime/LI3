package Model;

public interface IConsultasEstatisticas {

    String getSalesPath();
    int getVendasInvalidas();
    int getTotalProdutos();
    int getProdsComprados();
    int getProdsNaoComprados();
    int getTotalClientes();
    int getCliCompradores();
    int getCliNaoCompradores();
    int getComprasValor0();
    float getFatTotal();
    int[] getComprasMes();
    float[][] getFatMesFil();
    float[][] getCompradoresMesFil();
}
