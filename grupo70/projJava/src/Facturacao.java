import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Comparator;

public class Facturacao implements Serializable {
    private Map<String,FactMF> listaProd;
    private int comprados;
    private int compras0;
    private float faturacaoTotal;
    private float [] faturacaoMesFil;
    private int [] comprasMes;

    public Facturacao() {
        listaProd = new HashMap<>();
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new float[36];
    }

    public int getComprados() {
        return comprados;
    }

    public int getCompras0() {
        return compras0;
    }

    public float getFaturacaoTotal() {
        return faturacaoTotal;
    }

    public int[] getComprasMes() {
        return comprasMes;
    }

    public float[] getFaturacaoMesFil() {
        return faturacaoMesFil;
    }

    public Set<String> getKeys() {
        return listaProd.keySet();
    }

    public String getProd(String code) {
        return listaProd.get(code).getCodProd();
    }

    public int getUni(String code) {
        return listaProd.get(code).getUniTotal();
    }

    public int getSize() {
        return listaProd.size();
    }

    public double getFatTotalMes(String code,int month){
        return listaProd.get(code).getFaturacaoMes(month);
    }

    public double[][] getFatMesFilProd(String code){
        return listaProd.get(code).getFaturacaoMesFill();
    }

    public double getUniMes(String code,int month){
        return listaProd.get(code).getUnidadesMes(month);
    }

    public List<FactMF> getList(){
        return listaProd.values().stream().collect(Collectors.toList());
    }

    public boolean containsProd(String prodCode){
        return listaProd.containsKey(prodCode);
    }

    public void addSale(int branch,int month,float price,int uni,char type,String prod){

        if(!listaProd.containsKey(prod)) {
            comprados++;
            listaProd.put(prod,new FactMF(prod));
        }
        if(price * uni == 0.0)
            compras0++;

        float f = price * uni;
        faturacaoTotal += f;
        comprasMes[month]++;
        faturacaoMesFil [12*branch + month]+= f;
        listaProd.get(prod).setFact(branch,month,price,uni);
    }
}
