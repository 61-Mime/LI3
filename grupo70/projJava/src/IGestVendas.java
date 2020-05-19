import java.util.List;
import java.util.Set;

public interface IGestVendas {

    String getLoadInfoSalesPath();
    int getLoadInfoVendasInvalidas();
    int getLoadInfoProdValidos();
    int getFactComprados();
    int getLoadInfoCliValidos();
    int getLoadInfoCliComprador();
    int getFactCompras0();
    float getFactFaturacaoTotal();
    int[] getFactComprasMes();
    float[][] getFactFaturacaoMesFil();
    int[] getgFilCliCompradoresMes(int branch);
    Set<String> getCatPtree();
    boolean getFactContainsProd(String cod);
    int getGFilVendasMes(int month);
    int getGFilClientesDiferentesMes(int month);
    int getFilialVendas(int branch);
    int getFilialClientesCompradores(int branch);
    float getGFilNumeroComprasMes(String cod, int month);
    float getGFilProdutosDiferentes(String cod, int month);
    float getGFilGastoTotalMes(String cod, int month);
    float getFactUniMes(String cod, int month);
    float getGFilClientesDiferentes(String cod, int month);
    float getFactTotalMes(String cod, int month);
    Set<ParStringFloat> getGFilCliSet(int branch, String cod);
    Set<String> getFactKeys();
    int getFactUni(String cod);
    int getGFilClientesDiferentesTotal(String cod);
    List<String> getFilialClientesMaisCompradores(int branch);
    Set<String> getCatCtree();
    int getGFilProdutosDiferentesTotal(String cod);
    Set<ParStringFloat> getGFilProdSet(int branch, String cod);
    float[][] getFactMesFilProd(String cod);
}
