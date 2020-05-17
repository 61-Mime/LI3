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

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public Facturacao() {
        listaProd = new HashMap<>();
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new float[36];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

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
        return comprasMes.clone();
    }

    public float[] getFaturacaoMesFil() {
        return faturacaoMesFil.clone();
    }

    public Set<String> getKeys() {
        return new TreeSet(listaProd.keySet());
    }

    public int getUni(String code) {
        return listaProd.get(code).getUniTotal();
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

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public boolean containsProd(String prodCode){
        return listaProd.containsKey(prodCode);
    }

    public void addSale(int branch,int month,float price,int uni,String prod){

        if(!listaProd.containsKey(prod)) {
            comprados++;
            listaProd.put(prod,new FactMF());
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
