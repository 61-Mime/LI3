package Model;

import Model.ParStringFloat;

import java.util.List;
import java.util.Map;
import java.util.Set;

public interface IGestVendas {
    String getLoadInfoSalesPath();
    int getLoadInfoVendasInvalidas();
    int getLoadInfoProdValidos();
    int getLoadInfoCliValidos();
    int getLoadInfoCliComprador();
    boolean getCatCcontains(String cliCode);
    boolean getCatPcontains(String prodCode);
    Set<String> getCatPtree();
    Set<String> getCatCtree();
    boolean getFactContainsProd(String cod);
    int getFactCompras0();
    int getFactComprados();
    int getFactUni(String cod);
    float getFactTotalMes(String cod, int month);
    float getFactUniMes(String cod, int month);
    float getFactFaturacaoTotal();
    int[] getFactComprasMes();
    float[][] getFactFaturacaoMesFil();
    float[][] getFactMesFilProd(String cod);
    Set<String> getFactKeys();
    int getGFilVendasMes(int month);
    int getGFilClientesDiferentesMes(int month);
    int getFilialVendas(int branch);
    int getFilialClientesCompradores(int branch);
    int getGFilClientesDiferentesTotal(String cod);
    int getGFilProdutosDiferentesTotal(String cod);
    float[] getgFilCliCompradoresMes(int branch);
    float getGFilNumeroComprasMes(String cod, int month);
    float getGFilProdutosDiferentes(String cod, int month);
    float getGFilGastoTotalMes(String cod, int month);
    float getGFilClientesDiferentes(String cod, int month);
    Set<ParStringFloat> getGFilCliSet(int branch, String cod);
    List<String> getFilialClientesMaisCompradores(int branch);
    Set<ParStringFloat> getGFilProdSet(int branch, String cod);
    int loadCat(String filename, int type);
    int loadSales(String filename);
    float[][] getCompradoresMesFil();
    List<String> getQ1();
    int[] getQ2(int month);
    Map<Integer,float[]> getQ3(String code);
    Map<Integer,float[]> getQ4(String code);
    List<ParStringFloat> getQ5(String code);
    List<ParStringFloat> getQ6(int limit);
    Map<Integer,List<String>> getQ7();
    List<ParStringFloat> getQ8(int limit);
    List<ParStringFloat> getQ9(String code, int limit);
    Map<String,float[][]> getQ10();
    List<String> listParStringFloatToListString(List<ParStringFloat> list);
}
